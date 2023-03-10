// Mattia Cacciatore - Computer Science student at the University of Genoa - Italy
#include "AoC11.h"
//---------------------------------------------------TEST--------------------------------------------------
int main(){
    uint64_t steps = 1000; // Set it manually.
    read_cavern_from_file("input_day11.txt");
    std::vector<uint64_t> ans; // Answers.
	ans = count_flashes(steps); // Total flashes and first step when all octopuses flash.
    std::cout << "***** ADVENT OF CODE 2021 - DAY 11 - PART I *****\n";
    //std::cout << "\nThe total amount of flashes is: " << ans[0] << "\n\n"; // Twenty-first star *********************
    std::cout << "***** ADVENT OF CODE 2021 - DAY 11 - PART II *****\n";
    // std::cout << "\nThe first step when all octopuses flash is: " << ans[1] << "\n"; // Twenty-second star **********************
    return 0;
}