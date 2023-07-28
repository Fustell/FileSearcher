#include "FileSearcher.h"

std::mutex mtx;
std::atomic<bool> fileFound(false);
std::atomic<bool> fileNotExist(false);
std::list<std::filesystem::path> subdirectories;
std::condition_variable cv;
std::filesystem::path fileFoundDir;

const int MAX_THREADS = 8;

void searchFile(const std::string& filename) {
	while (true) {
		std::filesystem::path directory;
		{
			std::unique_lock<std::mutex> lock(mtx);

			if (subdirectories.empty())
			{
				fileNotExist = true;
				return;
			}
			cv.wait(lock, [&] { return !subdirectories.empty() || fileFound; });
			if (fileFound)
				return;
			if (subdirectories.empty())
				return;
			directory = subdirectories.front();
			subdirectories.pop_front();
		}

		try {
			for (const auto& entry : std::filesystem::directory_iterator(directory)) {
				if (entry.is_directory()) {
					std::lock_guard<std::mutex> lock(mtx);
					subdirectories.push_back(entry.path());
					cv.notify_one();
				}
				else if (entry.is_regular_file() && entry.path().filename() == filename) {
					fileFound = true;
					cv.notify_all();
					fileFoundDir = entry;
					return;
				}
			}
		}
		catch (const std::filesystem::filesystem_error& ex) {
			std::lock_guard<std::mutex> lock(mtx);
		}
	}
}

void startSearching(std::filesystem::path path, std::string filename)
{
	const std::string targetFilename = filename;
	const std::filesystem::path rootDir = path;


	subdirectories.push_back(rootDir);
	std::vector<std::thread> threads;

	for (int i = 0; i < MAX_THREADS; i++) {
		threads.emplace_back(searchFile, targetFilename);
	}

	for (auto& thread : threads) {
		if (thread.joinable())
			thread.join();
	}

	while (true)
	{
		if (fileFound)
		{
			std::cout << "File was found at: " << std::filesystem::path(fileFoundDir) << std::endl;
			break;
		}
		if (fileNotExist)
		{
			std::cout << "File is not exist" << std::endl;
			break;
		}
	}
}