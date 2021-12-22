// Mattia Cacciatore - Computer Science student at the University of Genoa - Italy
#include "AoC10_part2.h"
//---------------------------------ADVENT OF CODE 2021 - DAY 10 - PART II ---------------------------------
//---------------------------------------------------TEST--------------------------------------------------
int main(){
    std::vector<std::string> navigation_subsystem = read_navigation_from_file("input_day10.txt");
    std::vector<std::string> missing_chars = parse_navigation_subsystem(navigation_subsystem);
    uint64_t ans = calculate_middle_score(missing_chars);
    std::cout << "***** ADVENT OF CODE 2021 - DAY 10 - PART II *****\n";
    //std::cout << "\nThe middle score is: " << ans << "\n"; // Twentieth star ********************
    return 0;
}
