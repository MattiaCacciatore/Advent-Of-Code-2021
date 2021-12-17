#include "AC8_part2.h"
//---------------------------------ADVENT OF CODE 2021 - DAY 8 - PART II ----------------------------------
//---------------------------------------------------TEST--------------------------------------------------
int main(){
    std::string file = "input_day8.txt";
    std::ifstream ifs(file.c_str());
    std::vector<std::vector<std::string>> encrypted_digits = read_digit_from_file(ifs);
    long long int ans = sum_all_digits(encrypted_digits);
    //std::cout << ans << "\n";
    return 0;
}
