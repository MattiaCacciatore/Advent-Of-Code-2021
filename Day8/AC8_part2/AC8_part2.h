#include <iostream>
#include <sstream>   // iss
#include <fstream>   // ifs
#include <string>
#include <vector>

#define INP_SIZE 14  // Number of strings in the input line.
//----------------------------------------------FUNCTIONS--------------------------------------------------
// Just for fun.
void print_digit(std::vector<char> const);

std::vector<std::vector<std::string>> read_digit_from_file(std::istream&);

long long int sum_all_digits(std::vector<std::vector<std::string>> const&);
