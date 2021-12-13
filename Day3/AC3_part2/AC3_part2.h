#include <iostream>
#include <sstream>      // iss
#include <fstream>      // ifs
#include <string>
#include <vector>
#include <algorithm>    // reverse
#include <cmath>        // pow

#define SIZE 12
//----------------------------------------FUNCTIONS------------------------------------------
std::vector<std::vector<short int>> read_from_file(std::istream&);

long long int find_air_rate(std::vector<std::vector<short int>> const &);
