#define BLUE 14
#define GREEN 13
#define RED 12
#include <iostream>
#include <fstream>
#include <cctype>
#include <string>
#include <unordered_map>
#include <cstdlib>
#include <cstring>

size_t	checkValid(std::string& line)
{
	size_t	RGB[3] = {0, 0, 0};
	line.erase(0, 5);
	int	retVal = std::atol(line.c_str());
	while (std::isdigit(line.front()))
		line.erase(line.begin());
	line.erase(0, 2);
	size_t	tmp;
	while (line.front())
	{
		if (std::isdigit(line.front()))
		{
			tmp = std::atol(line.c_str());
			while (std::isdigit(line.front()))
				line.erase(line.begin());
		}
		else if (std::isspace(line.front()))
		{
			line.erase(line.begin());
		}
		else if (!strncmp(line.c_str(), "red", 3))
		{
			RGB[0] += tmp;
			if (RGB[0] > RED)
				return (0);
			line.erase(0, 3);
		}
		else if (!strncmp(line.c_str(), "green", 5))
		{
			RGB[1] += tmp;
			if (RGB[1] > GREEN)
				return (0);
			line.erase(0, 5);
		}
		else if (!strncmp(line.c_str(), "blue", 4))
		{
			RGB[2] += tmp;
			if (RGB[2] > BLUE)
				return (0);
			line.erase(0, 4);
		}
		else if (line.front() == ',')
		{
			line.erase(line.begin());
		}
		else if (line.front() == ';')
		{
			line.erase(line.begin());
			RGB[0] = 0;
			RGB[1] = 0;
			RGB[2] = 0;
		}
	}
	return (retVal);
}

/*
//Part 2
size_t	checkValid(std::string& line)
{
	size_t	RGB[3] = {0, 0, 0};
	size_t	fewest[3] = {0, 0, 0};
	line.erase(0, 5);
	while (std::isdigit(line.front()))
		line.erase(line.begin());
	line.erase(0, 2);
	size_t	tmp;
	while (line.front())
	{
		if (std::isdigit(line.front()))
		{
			tmp = std::atol(line.c_str());
			while (std::isdigit(line.front()))
				line.erase(line.begin());
		}
		else if (std::isspace(line.front()))
		{
			line.erase(line.begin());
		}
		else if (!strncmp(line.c_str(), "red", 3))
		{
			RGB[0] += tmp;
			line.erase(0, 3);
		}
		else if (!strncmp(line.c_str(), "green", 5))
		{
			RGB[1] += tmp;
			line.erase(0, 5);
		}
		else if (!strncmp(line.c_str(), "blue", 4))
		{
			RGB[2] += tmp;
			line.erase(0, 4);
		}
		else if (line.front() == ',')
		{
			line.erase(line.begin());
		}
		else if (line.front() == ';')
		{
			if (RGB[0] > fewest[0])
				fewest[0] = RGB[0];
			if (RGB[1] > fewest[1])
				fewest[1] = RGB[1];
			if (RGB[2] > fewest[2])
				fewest[2] = RGB[2];
			line.erase(line.begin());
			RGB[0] = 0;
			RGB[1] = 0;
			RGB[2] = 0;
		}
	}
	if (RGB[0] > fewest[0])
		fewest[0] = RGB[0];
	if (RGB[1] > fewest[1])
		fewest[1] = RGB[1];
	if (RGB[2] > fewest[2])
		fewest[2] = RGB[2];
	return (fewest[0] * fewest[1] * fewest[2]);
}
*/

int	main(int argc, char **argv)
{
	size_t	totalResult;

	if (argc != 2) {
		std::cerr << "Usage: " << argv[0] << " <filename>" << std::endl;
		return 1;
	}

	std::ifstream inputFile(argv[1]);
	if (!inputFile) {
		std::cerr << "Error: Could not open file." << std::endl;
		return 1;
	}

	std::string line;
	while (std::getline(inputFile, line))
	{
		std::cout << line << "\n";
		totalResult += checkValid(line);
		std::cout << "New total: " << totalResult << std::endl;
	}
	std::cout << "End total: " << totalResult << std::endl;
	inputFile.close();
	return (0);
}