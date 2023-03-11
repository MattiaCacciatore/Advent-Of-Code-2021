// Mattia Cacciatore - Computer Science student at the University of Genoa - Italy
#include<iostream>
#include<sstream>   // iss
#include<fstream>   // ifs
#include<string>
#include<vector>
//--------------------------------------------STRUCTURES AND TYPES-----------------------------------------
typedef struct cave{
	std::string label;
	bool visited;
	bool big_cave;
	std::vector<std::string> adjacent_caves;
}cave;
//------------------------------------------------FUNCTIONS------------------------------------------------
std::vector<cave> read_caves_from_file(const std::string &);

size_t all_paths(std::vector<cave> &, const uint64_t);