#ifndef FILESEARCHER_LIB
#define FILESEARCHER_LIB

#include <iostream>
#include <filesystem>
#include <thread>
#include <vector>
#include <mutex>
#include <list>
#include <atomic>
#include <condition_variable>

void searchFile(const std::string& filename);
void startSearching(std::filesystem::path path, std::string filename);

#endif