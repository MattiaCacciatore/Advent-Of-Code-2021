// Mattia Cacciatore - Computer Science student at Genoa University - Italy
#include <iostream>
#include <sstream>  // iss
#include <fstream>  // ifs
#include <string>
//---------------------------------ADVENT OF CODE 2021 - DAY 1 - PART II ----------------------------------
uint64_t count_from_file(std::string input){
    std::ifstream ifs(input);
    uint32_t s_w_one = 0, s_w_two = 0, s_w_three = 0; // Sliding windows and counter.
    uint64_t curr_sum = 0, prev_sum = 0, n_count = 0;
    if(ifs.good()){
        std::string line;
        std::istringstream iss; // Input stream to operate on strings.

        getline(ifs, line);     // See input.
        iss.clear();
        iss.str(line);
        iss >> s_w_one;
        getline(ifs, line);
        iss.clear();
        iss.str(line);
        iss >> s_w_two;
        getline(ifs, line);
        iss.clear();
        iss.str(line);
        iss >> s_w_three;
        curr_sum = s_w_one + s_w_two + s_w_three;

        for(;!ifs.eof();){
            if(curr_sum > prev_sum) n_count++;
            prev_sum = curr_sum;
            getline(ifs, line);
            iss.clear();
            iss.str(line);
            s_w_one = s_w_two;
            s_w_two = s_w_three;
            iss >> s_w_three;
            curr_sum = s_w_one + s_w_two + s_w_three;
        }
    }
    ifs.clear();
    return n_count;
}
//---------------------------------------------------TEST--------------------------------------------------
int main(){
    uint64_t ans = count_from_file("input_day1.txt"); // Answer.
    std::cout << "***** ADVENT OF CODE 2021 - DAY 1 - PART II *****\n";
    //std::cout << "\nNumber of sums larger than the previous ones: " << ans << "\n"; // Second star **
    return 0;
}
