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

typedef std::vector<std::vector<char>> Grid;

void getTop(Grid& map, int original_j, int original_i, std::vector<size_t>& values)
{
	int i = original_i - 1, j = original_j - 1;
	std::vector<std::vector<char>> numbers;
	std::vector<char> local;
	while (std::isdigit(map[j][i]))
		i--;
	if (i < original_i - 1)
		i++;
	while (1)
	{
		while (std::isdigit(map[j][i]))
		{
			local.push_back(map[j][i]);
			i++;
		}
		if (local.size())
		{
			numbers.push_back(local);
			local.clear();
		}
		if (map[j][i] == '.')
			i++;
		if (i > original_i + 1)
			break ;
	}
	size_t	val;
	for (size_t a = 0; a < numbers.size(); a++)
	{
		val = 0;
		for (size_t b = 0; b < numbers[a].size(); b++)
			val = val * 10 + numbers[a][b] - '0';
		values.push_back(val);
	}
}

void getBottom(Grid& map, int original_j, int original_i, std::vector<size_t>& values)
{
	int i = original_i - 1, j = original_j + 1;
	std::vector<std::vector<char>> numbers;
	std::vector<char> local;
	while (std::isdigit(map[j][i]))
		i--;
	if (i < original_i - 1)
		i++;
	while (1)
	{
		while (std::isdigit(map[j][i]))
		{
			local.push_back(map[j][i]);
			i++;
		}
		if (local.size())
		{
			numbers.push_back(local);
			local.clear();
		}
		if (map[j][i] == '.')
			i++;
		if (i > original_i + 1)
			break ;
	}
	size_t	val;
	for (size_t a = 0; a < numbers.size(); a++)
	{
		val = 0;
		for (size_t b = 0; b < numbers[a].size(); b++)
			val = val * 10 + numbers[a][b] - '0';
		values.push_back(val);
	}
}

void getLeft(Grid& map, int original_j, int original_i, std::vector<size_t>& values)
{
	int i = original_i - 1, j = original_j;
	while (std::isdigit(map[j][i]))
		i--;
	if (i < original_i - 1)
		i++;
	std::vector<char> local;
	while (std::isdigit(map[j][i]))
	{
		local.push_back(map[j][i]);
		i++;
	}
	size_t	val;
	if (local.size())
	{
		val = 0;
		for (int a = 0; a < local.size(); a++)
			val = val * 10 + local[a] - '0';
		values.push_back(val);
	}
}

void getRight(Grid& map, int original_j, int original_i, std::vector<size_t>& values)
{
	int i = original_i + 1, j = original_j;
	std::vector<char> local;
	while (std::isdigit(map[j][i]))
	{
		local.push_back(map[j][i]);
		i++;
	}
	size_t	val;
	if (local.size())
	{
		val = 0;
		for (int a = 0; a < local.size(); a++)
			val = val * 10 + local[a] - '0';
		values.push_back(val);
	}
}

size_t	scanAround(Grid& map, int j, int i)
{
	std::vector<size_t>	values;
	getTop(map, j , i, values);
	getLeft(map, j, i, values);
	getRight(map, j, i, values);
	getBottom(map, j, i, values);
	if (values.size() != 2)
		return (0);
	size_t	ret = 1;
	for (int a = 0; a < values.size(); a++)
		ret *= values[a];
	return (ret);
}

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << "Usage: " << argv[0] << " <filename>" << std::endl;
		return 1;
	}

	std::ifstream inputFile(argv[1]);
	if (!inputFile) {
		std::cerr << "Error: Could not open file." << std::endl;
		return 1;
	}

	// // Part 1 solution
	// std::vector<std::vector<char>> map;
	// std::string line;
	// while (std::getline(inputFile, line))
	// {
	// 	std::vector<char> row;
	// 	for (char c : line)
	// 		row.push_back(c);
	// 	map.push_back(row);
	// }
	// std::vector<size_t> valids;
	// std::string pool = "*$/+-=&#@%";
	// for (int j = 0; j < map.size(); j++)
	// {
	// 	int	tmp = 0;
	// 	bool	status = false;
	// 	for (int i = 0; i < map[j].size(); i++)
	// 	{
	// 		tmp = 0;
	// 		status = false;
	// 		while (std::isdigit(map[j][i]))
	// 		{
	// 			tmp = tmp * 10 + (map[j][i] - '0');
	// 			if (i + 1 < map[j].size() && pool.find(map[j][i + 1]) != std::string::npos)
	// 				status = true;
	// 			if (i - 1 >= 0 && pool.find(map[j][i - 1]) != std::string::npos)
	// 				status = true;
	// 			if (j + 1 < map.size() && pool.find(map[j + 1][i]) != std::string::npos)
	// 				status = true;
	// 			if (j - 1 >= 0 && pool.find(map[j - 1][i]) != std::string::npos)
	// 				status = true;
	// 			if (j + 1 < map.size() && i + 1 < map[j].size() && pool.find(map[j + 1][i + 1]) != std::string::npos)
	// 				status = true;
	// 			if (j - 1 >= 0 && i - 1 >= 0 && pool.find(map[j - 1][i - 1]) != std::string::npos)
	// 				status = true;
	// 			if (j + 1 < map.size() && i - 1 >= 0 && pool.find(map[j + 1][i - 1]) != std::string::npos)
	// 				status = true;
	// 			if (j - 1 >= 0 && i + 1 < map[j].size() && pool.find(map[j - 1][i + 1]) != std::string::npos)
	// 				status = true;
	// 			i++;
	// 		}
	// 		if (status)
	// 		{
	// 			valids.push_back(tmp);
	// 			std::cout << "Pushed value :" << tmp << std::endl;
	// 		}
	// 	}
	// }
	// int sum = std::accumulate(valids.begin(), valids.end(), 0);
	// std::cout << "result: " << sum << std::endl;

	// Part 2 solution
	

	Grid	map;
	std::string line;
	while (std::getline(inputFile, line))
	{
		line.insert(line.begin(), '.');
		line.push_back('.');
		map.push_back(std::vector(line.begin(), line.end()));
	}
	map.insert(map.begin(), std::vector<char>(map[0].size() - 2, '.'));
	map.push_back(std::vector<char>(map[0].size() - 2, '.'));
	size_t	sum = 0;
	for (int j = 0; j < map.size() - 1; j++)
	{
		for (int i = 0; i < map[j].size() - 1; i++)
		{
			if (map[j][i] == '*')
			{
				sum += scanAround(map, j, i);
			}
		}
	}
	std::cout << "Result :" << sum << std::endl;
	inputFile.close();
	return (0);
}
