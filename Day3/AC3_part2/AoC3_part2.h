// Mattia Cacciatore - Computer Science student at the University of Genoa - Italy
#include <iostream>
#include <sstream>   // iss
#include <fstream>   // ifs
#include <string>
#include <vector>
#include <algorithm> // reverse
#include <cmath>     // pow

#define INPUT_SIZE 12

typedef uint32_t precision;
//----------------------------------------FUNCTIONS------------------------------------------
std::vector<std::vector<precision>> read_from_file(std::string);

std::vector<precision> find_oxygen_rate(std::vector<std::vector<precision>> const &);

std::vector<precision> find_carbon_rate(std::vector<std::vector<precision>> const &);

uint64_t find_air_rate(std::vector<std::vector<precision>> const &);
