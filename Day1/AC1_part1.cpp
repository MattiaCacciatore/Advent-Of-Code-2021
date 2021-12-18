// Mattia Cacciatore - Computer Science student at Genoa University - Italy
#include <iostream>
#include <limits>   // numeric_limit
#include <sstream>  // iss
#include <fstream>  // ifs
#include <string>
//---------------------------------ADVENT OF CODE 2021 - DAY 1 - PART I -----------------------------------
uint64_t count_from_file(std::string input){
    std::ifstream ifs(input);
    uint64_t curr_num = 0, prev_num = std::numeric_limits<uint64_t>::max(), n_count = 0; // Numbers and counter.
    if(ifs.good()){
        std::string line;
        std::istringstream iss; // Input stream to operate on strings.

        for(;!ifs.eof();){
            getline(ifs, line);
            iss.clear();
            iss.str(line);
            iss >> curr_num;
            if(curr_num > prev_num) n_count++;
            prev_num = curr_num;
        }
    }
    ifs.clear();
    return n_count;
}
//---------------------------------------------------TEST--------------------------------------------------
int main(){
    uint64_t ans = count_from_file("input_day1.txt"); // Answer.
    std::cout << "***** ADVENT OF CODE 2021 - DAY 1 - PART I *****\n";
    std::cout << "\nNumber of measurements larger than the previous ones: " << ans << "\n"; // First star *
    return 0;
}
