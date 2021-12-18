// Mattia Cacciatore - Computer Science student at the University of Genoa - Italy
#include <iostream>
#include <sstream>    // iss
#include <fstream>    // ifs
#include <string>
#include <vector>
#include <algorithm>  // reverse
#include <cmath>      // pow

#define INPUT_SIZE 12

typedef uint8_t precision;
//----------------------------------------FUNCTIONS------------------------------------------
void print_matrix(std::vector<std::vector<precision>> const &);

std::vector<std::vector<precision>> read_report_from_file(std::string);

std::vector<precision> find_most_common_bit_number(std::vector<std::vector<precision>> const &);

uint32_t calculate_gamma_rate(std::vector<precision> const &);

uint32_t calculate_epsilon_rate(std::vector<precision> const &);

uint64_t calculate_power_consumption(uint32_t, uint32_t);
