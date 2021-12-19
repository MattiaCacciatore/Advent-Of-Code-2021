// Mattia Cacciatore - Computer Science student at the University of Genoa - Italy
#include <iostream>
#include <sstream>   // iss
#include <fstream>   // ifs
#include <string>
#include <vector>

#define DIG_SIZE 14  // Number of strings in the input line.
//----------------------------------------------FUNCTIONS--------------------------------------------------
// Just for fun.
void print_digit(std::vector<char> const);

std::vector<std::vector<std::string>> read_digit_from_file(std::string);

uint64_t sum_all_digits(std::vector<std::vector<std::string>> const&);
