// Mattia Cacciatore - Computer Science student at the University of Genoa - Italy
#include "AoC4_part1.h"
//---------------------------------ADVENT OF CODE 2021 - DAY 4 - PART I -----------------------------------
//---------------------------------------------------TEST--------------------------------------------------
int main(){
    std::vector<std::vector<std::vector<precision>>> cards = read_cards_from_file("input_cards_day4.txt");
    std::vector<precision> numbers = read_numbers_from_file("input_wild_numbers_day4.txt");
    uint64_t ans = play_bingo(cards, numbers);
    std::cout << "***** ADVENT OF CODE 2021 - DAY 4 - PART I *****\n";
    //std::cout << "\nThe final score is: " << ans << "\n"; // Seventh star *******
    return 0;
}
