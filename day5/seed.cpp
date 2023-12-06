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

#include <tuple>

struct Map
{
	uint64_t	dst;
	uint64_t	src;
	uint64_t	range;
};

void	getSeeds(std::vector<uint64_t>& seeds, std::string& line)
{
	line.erase(0, 7);
	std::istringstream iss(line);
	uint64_t token;
	while (iss >> token)
		seeds.push_back(token);
}

void	getMaps(std::vector<std::vector<Map>>& maps, std::ifstream& inputFile)
{
	std::string line;
	int i = -1;
	Map tmp;
	while (std::getline(inputFile, line))
	{
		if (line.size() == 1)
		{
			i++;
			std::getline(inputFile, line);
			std::getline(inputFile, line);
			std::vector<Map> local;
			maps.push_back(local);
		}
		std::istringstream iss(line);
		iss >> tmp.dst;
		iss >> tmp.src;
		iss >> tmp.range;
		maps[i].push_back(tmp);
	}
}

void	solveLocation(std::vector<uint64_t>& seeds, std::vector<std::vector<Map>> mapsArray)
{
	uint64_t lowest;
	lowest--;
	uint64_t curSrc;
	for (auto seed : seeds)
	{
		curSrc = seed;
		for (auto maps : mapsArray)
		{
			for (auto map : maps)
			{
				if (curSrc >= map.src && curSrc < map.src + map.range)
				{
					curSrc = curSrc - map.src + map.dst;
					break ;
				}
			}
		}
		if (lowest > curSrc)
			lowest = curSrc;
	}
	std::cout << "Lowest value :" << lowest << std::endl;
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
	std::vector<uint64_t> seeds;
	std::vector<std::vector<Map>> maps;
	std::string line;
	std::getline(inputFile, line);
	getSeeds(seeds, line);
	getMaps(maps, inputFile);
	inputFile.close();
	solveLocation(seeds, maps);
}