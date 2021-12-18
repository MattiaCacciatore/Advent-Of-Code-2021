// Mattia Cacciatore - Computer Science student at the University of Genoa - Italy
#include <iostream>
#include <sstream>  // iss
#include <fstream>  // ifs
#include <string>
#include <vector>
#include <cstdlib>  // abs

#define SIZE 1000   // Be aware of precision. Map size.

typedef uint16_t precision;
//-------------------------------------------------FUNCTIONS-----------------------------------------------
std::vector<std::vector<precision>> read_vents_from_file(std::string);

std::vector<std::vector<precision>> create_map(size_t);

void mark_all_vents(std::vector<std::vector<precision>> &, std::vector<std::vector<precision>> &v);

uint64_t count_vents_in_map(std::vector<std::vector<precision>> const &, size_t, size_t);
