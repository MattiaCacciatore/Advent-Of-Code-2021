#include "AC5_part1.h"
//---------------------------------ADVENT OF CODE 2021 - DAY 5 - PART I -----------------------------------
//---------------------------------------------------TEST--------------------------------------------------
int main(){
    std::string file = "input_day5.txt";
    std::ifstream ifs(file.c_str());
    std::vector<std::vector<short int>> vents = read_vents_from_file(ifs); // Max_x = 988, max_y = 989. 322 vents.
    std::vector<std::vector<int>> vents_map = create_map(SIZE);
    mark_all_vents(vents_map, vents);
    long long int ans = count_vents_in_map(vents_map, SIZE, SIZE);
    //std::cout << ans << "\n";
    return 0;
}
