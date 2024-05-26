#include<string>
#include<random>
#include "drawing.hpp"

std::string draw(){
	std::random_device seed_gen;
	std::mt19937 rng(seed_gen());
	
	std::vector<std::string> slips = {"Very good luck", "Good luck", "Bad luck", "Extremely bad luck"};
	std::uniform_int_distribution<> dist_n(1, slips.size());
	int n = dist_n(rng);
	return slips[n];
}
