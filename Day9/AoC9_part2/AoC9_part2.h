#include <iostream>
#include <sstream>   // iss
#include <fstream>   // ifs
#include <string>
#include <vector>
#include <algorithm> // sort

typedef uint8_t precision;
//----------------------------------------------FUNCTIONS--------------------------------------------------
std::vector<std::vector<precision>> read_map_from_file(std::string);

uint64_t mul_largest_basins(std::vector<std::vector<precision>> &);

