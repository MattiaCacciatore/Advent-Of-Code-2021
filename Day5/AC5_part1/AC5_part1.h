#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>

#define SIZE 1000
//-------------------------------------------------FUNCTIONS-----------------------------------------------
std::vector<std::vector<short int>> read_vents_from_file(std::istream&);

std::vector<std::vector<int>> create_map(size_t);

void mark_all_vents(std::vector<std::vector<int>> &, std::vector<std::vector<int>> &);
