// Mattia Cacciatore - Computer Science student at the University of Genoa - Italy
#include "AoC5_part1.h"
//---------------------------------ADVENT OF CODE 2021 - DAY 5 - PART I -----------------------------------
//---------------------------------------------------TEST--------------------------------------------------
int main(){
    std::vector<std::vector<precision>> vents = read_vents_from_file("input_day5.txt"); // Max_x = 988, max_y = 989. 322 vents.
    std::vector<std::vector<precision>> vents_map = create_map(SIZE);
    mark_all_vents(vents_map, vents);
    uint64_t ans = count_vents_in_map(vents_map, SIZE, SIZE);
    std::cout << "***** ADVENT OF CODE 2021 - DAY 5 - PART I *****\n";
    //std::cout << "\nThe number of dangerous vents is: " << ans << "\n"; // Nineth star *********
    return 0;
}
