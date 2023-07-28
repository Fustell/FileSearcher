#include <filesystem>
#include "FileSearcher.h"


int main() {

    std::string fileName;
    std::cout << "Enter the file name: ";
    std::cin >> fileName;
    std::cout << std::endl;
    std::cout << "Searching..." << std::endl;
    std::cin.get();
    startSearching(std::filesystem::path("C:\\"), fileName);
    std::cout << "Press enter to close this window" << std::endl;
    std::cin.get();


    return 0;
}