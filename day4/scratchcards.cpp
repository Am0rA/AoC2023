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

// void printUsage(const char* programName)
// {
// 	std::cerr << "Usage: ./" << programName << " <filename>" << std::endl;
// }

// void printError(const std::string& errorMessage)
// {
// 	std::cerr << "Error: " << errorMessage << std::endl;
// }

// std::ifstream openFile(const char* filename)
// {
// 	std::ifstream file(filename);
// 	return file;
// }

// Part 1
// std::ifstream openFile(const char* filename) {
// 	std::ifstream file(filename);
// 	return file;
// }

// void processLine(std::string& line, size_t& sum) {
// 	std::vector<size_t> winner;
// 	std::vector<size_t> pool;

// 	size_t cardVal = 0;

// 	line.erase(0, 10);
// 	std::istringstream iss(line);
// 	std::string token;

// 	while (iss >> token)
// 	{
// 		try
// 		{
// 			winner.push_back(std::stoul(token));
// 		}
// 		catch(const std::invalid_argument& e)
// 		{
// 			while (iss >> token)
// 				pool.push_back(std::stoul(token));
// 		}
// 	}
// 	for (size_t val : winner)
// 		cardVal += std::count(pool.begin(), pool.end(), val);
// 	if (cardVal)
// 		sum += std::pow(2, cardVal - 1);
// }

// int main(int argc, char **argv)
// {
// 	if (argc != 2)
// 	{
// 		printUsage(argv[0]);
// 		return 1;
// 	}

// 	std::ifstream inputFile = openFile(argv[1]);
// 	if (!inputFile)
// 	{
// 		printError("Could not open file.");
// 		return 1;
// 	}

// 	std::string line;
// 	size_t sum = 0;

// 	while (std::getline(inputFile, line))
// 	{
// 		processLine(line, sum);
// 		line.clear();
// 	}

// 	std::cout << "sum : " << sum << std::endl;

// 	inputFile.close();
// 	return 0;
// }

// Part 2
size_t processLine(std::string& line)
{
	std::vector<size_t> winner;
	std::vector<size_t> pool;
	size_t cardVal = 0;
	line.erase(0, 10);
	std::istringstream iss(line);
	std::string token;

	while (iss >> token)
	{
		try
		{
			winner.push_back(std::stoul(token));
		}
		catch(const std::invalid_argument& e)
		{
			while (iss >> token)
				pool.push_back(std::stoul(token));
		}
	}
	for (size_t val : winner)
		cardVal += std::count(pool.begin(), pool.end(), val);
	return (cardVal);
}

size_t	diveRecursive(std::vector<size_t>& ref)
{
	if (ref.empty())
		return (0);
	size_t	range1 = std::min(ref.front(), ref.size());
	size_t	ret = range1;
	for (int i = 0; i < range1; i++)
	{
		std::vector<size_t> tmp(ref.begin() + i + 1, ref.end());
		ret += diveRecursive(tmp);
	}
	return (ret);
}

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << "Usage: ./" << argv[0] << " <filename>" << std::endl;
		return 1;
	}

	std::ifstream inputFile(argv[1]);
	if (!inputFile)
	{
		std::cerr << "Error: Could not open file." << std::endl;
		return 1;
	}

	std::string line;
	std::vector<size_t> results;
	while (std::getline(inputFile, line))
		results.push_back(processLine(line));
	inputFile.close();

	size_t	sum = results.size();
	for (int i = 0; i < results.size(); i++)
	{
		std::vector<size_t> tmp(results.begin() + i, results.end());
		sum += diveRecursive(tmp);
	}
	std::cout << "sum : " << sum << std::endl;

	return 0;
}
