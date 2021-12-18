// Mattia Cacciatore - Computer Science student at the University of Genoa - Italy
#include "AoC5_part2.h"
//---------------------------------ADVENT OF CODE 2021 - DAY 5 - PART II ----------------------------------
//---------------------------------------------------TEST--------------------------------------------------
int main(){
    std::vector<std::vector<precision>> vents = read_vents_from_file("input_day5.txt");
    std::vector<std::vector<precision>> vents_map = create_map(SIZE);   // 322 horizontal/vertical vents, 168 diagonal vents.
    mark_all_vents(vents_map, vents);
    uint64_t ans = count_vents_in_map(vents_map, SIZE, SIZE);
    std::cout << "***** ADVENT OF CODE 2021 - DAY 5 - PART II *****\n";
    //std::cout << "\nThe number of dangerous vents is: " << ans << "\n"; // Tenth star **********
    return 0;
}

