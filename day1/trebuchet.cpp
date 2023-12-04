#include <iostream>
#include <fstream>
#include <cctype>
#include <string>
#include <unordered_map>

int findFirstLastOccurrence(const std::string& input, const std::unordered_map<std::string, int>& wordToDigit)
{
    int result = 0;
    size_t pos = std::string::npos;
    // Find the first occurrence
	size_t	i = 0;
	for (std::unordered_map<std::string, int>::const_iterator it = wordToDigit.begin(); it != wordToDigit.end(); ++it)
	{
		size_t	found = input.find(it->first);
		if (found != std::string::npos && (pos == std::string::npos || found < pos))
		{
			pos = found;
			i = it->second;
		}
	}

	result = i * 10;
	pos = std::string::npos;
	i = 0;
    // Find the last occurrence
	for (std::unordered_map<std::string, int>::const_iterator it = wordToDigit.begin(); it != wordToDigit.end(); ++it)
	{
		size_t	found = input.rfind(it->first);
		if (found != std::string::npos && (pos == std::string::npos || found > pos))
		{
			pos = found;
			i = it->second;
		}
	}
	return (result + i);
}

int main(int argc, char* argv[]) {
	if (argc != 2) {
		std::cerr << "Usage: " << argv[0] << " <filename>" << std::endl;
		return 1;
	}

	std::ifstream inputFile(argv[1]);
	if (!inputFile) {
		std::cerr << "Error: Could not open file." << std::endl;
		return 1;
	}

	// You can remove pairs below with 'string' digits if you want to see the part 1 solution.
	std::unordered_map<std::string, int> wordToDigit = {
		{"zero", 0},
		{"one", 1},
		{"two", 2},
		{"three", 3},
		{"four", 4},
		{"five", 5},
		{"six", 6},
		{"seven", 7},
		{"eight", 8},
		{"nine", 9},
		{"1", 1},
		{"2", 2},
		{"3", 3},
		{"4", 4},
		{"5", 5},
		{"6", 6},
		{"7", 7},
		{"8", 8},
		{"9", 9},
		{"0", 0}
	};

	int totalResult = 0;
	std::string line;

	while (std::getline(inputFile, line)) {
		int lineResult = findFirstLastOccurrence(line, wordToDigit);
		std::cout << "Line Result: " << lineResult << std::endl;
		totalResult += lineResult;
	}

	std::cout << "Total Result: " << totalResult << std::endl;

	return 0;
}