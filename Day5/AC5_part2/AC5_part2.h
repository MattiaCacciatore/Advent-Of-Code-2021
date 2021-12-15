#include <iostream>
#include <sstream>  // iss
#include <fstream>  // ifs
#include <string>
#include <vector>
#include <cstdlib>  // abs

#define SIZE 1000
//-------------------------------------------------FUNCTIONS-----------------------------------------------
std::vector<std::vector<int>> read_vents_from_file(std::istream&);

std::vector<std::vector<int>> create_map(size_t);

void mark_all_vents(std::vector<std::vector<int>> &, std::vector<std::vector<int>> &);

long long int count_vents_in_map(std::vector<std::vector<int>> const &, size_t, size_t);
