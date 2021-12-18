// Mattia Cacciatore - Computer Science student at the University of Genoa - Italy
#include "AoC3_part2.h"
//---------------------------------ADVENT OF CODE 2021 - DAY 3 - PART II ----------------------------------
//---------------------------------------------------TEST--------------------------------------------------
int main(){
    std::vector<std::vector<precision>> report = read_from_file("input_day3.txt");
    uint64_t ans = find_air_rate(report);
    std::cout << "***** ADVENT OF CODE 2021 - DAY 3 - PART II *****\n";
    //std::cout << "\nSubmarine life support rating is: " << ans << "\n"; // Sixth star ******
    return 0;
}
