// Mattia Cacciatore - Computer Science student at the University of Genoa - Italy
#include <iostream>
#include <sstream>   // iss
#include <fstream>   // ifs
#include <string>
#include <vector>
#include <stack>     // LIFO stack
//----------------------------------------------FUNCTIONS--------------------------------------------------
std::vector<std::vector<char>> read_navigation_from_file(std::string);

std::vector<char> parse_navigation_subsystem(std::vector<std::vector<char>> const &);

uint64_t calculate_syntax_error_score(std::vector<char> const &);
