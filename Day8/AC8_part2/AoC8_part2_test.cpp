// Mattia Cacciatore - Computer Science student at the University of Genoa - Italy
#include "AoC8_part2.h"
//---------------------------------ADVENT OF CODE 2021 - DAY 8 - PART II ----------------------------------
//---------------------------------------------------TEST--------------------------------------------------
int main(){
    std::vector<std::vector<std::string>> encrypted_digits = read_digit_from_file("input_day8.txt");
    uint64_t ans = sum_all_digits(encrypted_digits);
    std::cout << "***** ADVENT OF CODE 2021 - DAY 8 - PART II *****\n";
    //std::cout << "\nThe sum of output values is: " << ans << "\n"; // Sixteenth star ****************
    return 0;
}
