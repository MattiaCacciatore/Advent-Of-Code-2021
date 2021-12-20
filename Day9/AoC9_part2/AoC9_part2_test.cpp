// Mattia Cacciatore - Computer Science student at the University of Genoa - Italy
#include "AoC9_part2.h"
//---------------------------------ADVENT OF CODE 2021 - DAY 9 - PART II ----------------------------------
//---------------------------------------------------TEST--------------------------------------------------
int main(){
    std::vector<std::vector<precision>> cave_map = read_map_from_file("input_day9.txt");
    uint64_t ans = mul_largest_basins(cave_map);
    std::cout << "***** ADVENT OF CODE 2021 - DAY 9 - PART II *****\n";
    //std::cout << "\nThe multiplication of the 3 largest basins is: " << ans << "\n"; // Eighteenth star ******************
    return 0;
}
