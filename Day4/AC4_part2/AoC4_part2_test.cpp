// Mattia Cacciatore - Computer Science student at the University of Genoa - Italy
#include "AoC4_part2.h"
//---------------------------------ADVENT OF CODE 2021 - DAY 4 - PART II ----------------------------------
//---------------------------------------------------TEST--------------------------------------------------
int main(){
    std::vector<std::vector<std::vector<precision>>> cards = read_cards_from_file("input_cards_day4.txt");
    std::vector<precision> numbers = read_numbers_from_file("input_wild_numbers_day4.txt");
    uint64_t ans = lose_bingo(cards, numbers);
    std::cout << "***** ADVENT OF CODE 2021 - DAY 4 - PART II *****\n";
    //std::cout << "\nSquid final score is: " << ans << "\n"; // Eighth star ********
    return 0;
}
