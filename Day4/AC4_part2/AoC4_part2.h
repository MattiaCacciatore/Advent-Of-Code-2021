// Mattia Cacciatore - Computer Science student at the University of Genoa - Italy
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>

#define BINGO_SIZE 5

typedef int32_t precision;
//-------------------------------------------------FUNCTIONS-----------------------------------------------
std::vector<std::vector<std::vector<precision>>> read_cards_from_file(std::string);

std::vector<precision> read_numbers_from_file(std::string);

uint64_t lose_bingo(std::vector<std::vector<std::vector<precision>>> &, std::vector<precision> const &);
