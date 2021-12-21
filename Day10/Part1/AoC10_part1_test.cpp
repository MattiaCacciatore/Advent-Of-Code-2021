// Mattia Cacciatore - Computer Science student at the University of Genoa - Italy
#include "AoC10_part1.h"
//---------------------------------ADVENT OF CODE 2021 - DAY 10 - PART I ----------------------------------
//---------------------------------------------------TEST--------------------------------------------------
int main(){
    std::vector<std::vector<char>> navigation_subsystem = read_navigation_from_file("input_day10.txt");
    std::vector<char> corrupted_chunks = parse_navigation_subsystem(navigation_subsystem);
    uint64_t ans = calculate_syntax_error_score(corrupted_chunks);
    std::cout << "***** ADVENT OF CODE 2021 - DAY 10 - PART I *****\n";
    //std::cout << "\nThe total syntax error score is: " << ans << "\n"; // Nineteenth star *******************
    return 0;
}
