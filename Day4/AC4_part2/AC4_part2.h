#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>

#define BINGO_SIZE 5
//-------------------------------------------------FUNCTIONS-----------------------------------------------
std::vector<std::vector<std::vector<short int>>> read_cards_from_file(std::istream&);

std::vector<short int> read_numbers_from_file(std::istream&);

long long int lose_bingo(std::vector<std::vector<std::vector<short int>>> &, std::vector<short int> const &);
