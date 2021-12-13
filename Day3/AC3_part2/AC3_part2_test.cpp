#include "AC3_part2.h"
//---------------------------------ADVENT OF CODE 2021 - DAY 3 - PART II ----------------------------------
//---------------------------------------------------TEST--------------------------------------------------
int main(){
    std::string file = "input_day3.txt";
    std::ifstream ifs(file.c_str());
    std::vector<std::vector<short int>> report = read_from_file(ifs);
    long long int ans = find_air_rate(report);
    //std::cout << ans << "\n";
    return 0;
}
