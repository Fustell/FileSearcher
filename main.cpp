#include <filesystem>
#include "FileSearcher.h"


int main() {

    std::string fileName;
    std::cout << "Enter the file name: ";
    std::cin >> fileName;
    std::cout << std::endl;
    std::cout << "Searching..." << std::endl;
    std::cin.get();

#if defined(__linux__) // Or #if __linux__
    std::filesystem::path rootDir = std::filesystem::path("/");
#elif _WIN32
    std::filesystem::path rootDir = std::filesystem::path("C:\\");
#endif

    startSearching(rootDir, fileName);
    std::cout << "Press enter to close this window" << std::endl;
    std::cin.get();


    return 0;
}