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

int main(void)
{
	std::cout << "Part 1" << std::endl;
	size_t records = 0;
	std::vector<int> results;
	std::vector<std::pair<int, int>> values = {{53, 275}, {71, 1181}, {78, 1215}, {80, 1524}};
	for (auto pair : values)
	{
		records = 0;
		for (int i = 0; i < pair.first; i++)
		{
			if (i * (pair.first - i) >= pair.second)
				records++;
		}
		results.push_back(records);
	}
	std::cout << std::accumulate(results.begin(), results.end(), 1, std::multiplies<int>()) << std::endl;
	std::cout << "Part 2" << std::endl;
	results.clear();
	records = 0;
	for (uint64_t i = 0; i < 53717880; i++)
	{
		if (i * (53717880 - i) >= 275118112151524)
			records++;
	}
	std::cout << records << std::endl;
	return (0);
}
