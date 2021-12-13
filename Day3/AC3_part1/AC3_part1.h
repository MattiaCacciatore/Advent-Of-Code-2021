#include <iostream>
#include <sstream>   // iss
#include <fstream>   // ifs
#include <string>
#include <cstdlib>
#include <vector>
#include <algorithm> // reverse
#include <cmath>     // pow

#define SIZE 12
//----------------------------------------FUNCTIONS------------------------------------------
void print_matrix(std::vector<std::vector<short int>> const &);

std::vector<std::vector<short int>> read_from_file(std::istream&);

std::vector<short int> find_most_common_bit_number(std::vector<std::vector<short int>> const &);

int calculate_gamma_rate(std::vector<short int> const &);

int calculate_epsilon_rate(std::vector<short int> const &);

long long int calculate_power_consumption(int, int);
