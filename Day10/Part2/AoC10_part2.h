// Mattia Cacciatore - Computer Science student at the University of Genoa - Italy
#include <iostream>
#include <sstream>   // iss
#include <fstream>   // ifs
#include <string>
#include <vector>
#include <algorithm> // sort
#include <stack>     // LIFO stack
//---------------------------------------------FUNCTIONS----------------------------------------------
std::vector<std::string> read_navigation_from_file(std::string);

std::vector<std::string> parse_navigation_subsystem(std::vector<std::string> &);

uint64_t calculate_middle_score(std::vector<std::string> const &);
