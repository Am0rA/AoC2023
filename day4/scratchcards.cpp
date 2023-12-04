#include <iostream>
#include <fstream>
#include <cctype>
#include <string>
#include <unordered_map>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <sstream>
#include <numeric>
#include <algorithm>
#include <cmath>

void printUsage(const char* programName) {
    std::cerr << "Usage: " << programName << " <filename>" << std::endl;
}

void printError(const std::string& errorMessage) {
    std::cerr << "Error: " << errorMessage << std::endl;
}

std::ifstream openFile(const char* filename) {
    std::ifstream file(filename);
    return file;
}

void processLine(std::string& line, size_t& sum) {
    std::vector<size_t> winner;
    std::vector<size_t> pool;

    size_t cardVal = 0;

    line.erase(0, 10);
    std::istringstream iss(line);
    std::string token;

    while (iss >> token) {
        try {
            winner.push_back(std::stoul(token));
        } catch(const std::invalid_argument& e) {
            while (iss >> token) {
                pool.push_back(std::stoul(token));
            }
        }
    }

    for (size_t val : winner) {
        cardVal += std::count(pool.begin(), pool.end(), val);
    }

    if (cardVal)
        sum += std::pow(2, cardVal - 1);
}

int main(int argc, char **argv) {
    if (argc != 2) {
        printUsage(argv[0]);
        return 1;
    }

    std::ifstream inputFile = openFile(argv[1]);
    if (!inputFile) {
        printError("Could not open file.");
        return 1;
    }

    std::string line;
    size_t sum = 0;

    while (std::getline(inputFile, line)) {
        processLine(line, sum);
        line.clear();
    }

    std::cout << "sum : " << sum << std::endl;

    inputFile.close();
    return 0;
}
