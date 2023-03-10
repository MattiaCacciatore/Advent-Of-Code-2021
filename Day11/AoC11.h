// Mattia Cacciatore - Computer Science student at the University of Genoa - Italy
#include <iostream>
#include <sstream>   // iss
#include <fstream>   // ifs
#include <vector>

#define CAVERN_SIZE 10

struct dumbo_octopus{
    int energy;
    bool flashed;
};

inline dumbo_octopus cavern[CAVERN_SIZE][CAVERN_SIZE]; // Fixed input.
//------------------------------------------------FUNCTIONS------------------------------------------------
void read_cavern_from_file(std::string);

std::vector<uint64_t> count_flashes(uint64_t);