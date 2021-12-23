// Mattia Cacciatore - Computer Science student at the University of Genoa - Italy
#include "AoC11_part1.h"
//---------------------------------------------------TEST--------------------------------------------------
int main(){
    uint64_t steps = 100;
    read_cavern_from_file("input_day11.txt");
    uint64_t ans = count_flashes(steps);
    std::cout << "***** ADVENT OF CODE 2021 - DAY 11 - PART I *****\n";
    //std::cout << "\nThe total amount of flashes is: UNKNOWN\n";
    return 0;
}
