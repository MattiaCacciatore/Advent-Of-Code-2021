#include "AC4_part1.h"
//---------------------------------ADVENT OF CODE 2021 - DAY 4 - PART I -----------------------------------
//---------------------------------------------------TEST--------------------------------------------------
int main(){
    std::string file = "input_cards_day4.txt";
    std::ifstream ifs(file.c_str());
    std::vector<std::vector<std::vector<short int>>> cards = read_cards_from_file(ifs);
    file = "input_wild_numbers_day4.txt";
    std::ifstream ifs_two(file.c_str());
    std::vector<short int> numbers = read_numbers_from_file(ifs_two);
    long long int ans = play_bingo(cards, numbers);
    //std::cout << ans << "\n";
    return 0;
}
