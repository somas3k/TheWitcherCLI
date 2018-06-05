#pragma once
#include <random>
#include <time.h>	
#include <vector>
#include <sstream>
#include <string>


int generate_hit(int max_hit);

int generate_random_item_level();

int generate_random_price(int max);

int generate_random_index(int max);

namespace {
	std::vector<std::string> split(const std::string& s, char delimiter)
	{
		std::vector<std::string> tokens;
		std::string token;
		std::istringstream tokenStream(s);
		while (getline(tokenStream, token, delimiter))
		{
			tokens.push_back(token);
		}
		return tokens;
	}
}
