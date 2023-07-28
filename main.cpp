#include <filesystem>
#include "FileSearcher.h"


int main() {

    std::string fileName;
    std::cout << "Enter the file name: ";
    std::cin >> fileName;
    std::cout << std::endl;
    std::cout << "Searching..." << std::endl;
    startSearching(std::filesystem::path("C://"), fileName);
    std::cin.get();


    return 0;
}