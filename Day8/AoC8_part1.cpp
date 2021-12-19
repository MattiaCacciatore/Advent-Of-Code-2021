// Mattia Cacciatore - Computer Science student at the University of Genoa - Italy
#include <iostream>
#include <sstream>   // iss
#include <fstream>   // ifs
#include <string>
#include <vector>

typedef uint8_t precision;
//---------------------------------ADVENT OF CODE 2021 - DAY 8 - PART I -----------------------------------
//----------------------------------------------FUNCTIONS--------------------------------------------------
std::vector<precision> read_digit_from_file(std::string input){
    std::vector<precision> d_c; // Digit counter.
    d_c.resize(4);              // 1,4,7 and 8.
    std::ifstream ifs(input);
    if(ifs.good()){
        std::string line, digit;
        std::istringstream iss;

        for(;!ifs.eof();){
            ifs.clear();
            getline(ifs, line);
            iss.clear();
            iss.str(line);
            iss >> digit;
            for(;digit != "|";){
                iss >> digit;
            }
            iss >> digit;
            for(;iss;){
            	if(digit.size() == 2) d_c[0]++;      // 1
            	else if(digit.size() == 3) d_c[2]++; // 7
            	else if(digit.size() == 4) d_c[1]++; // 4
            	else if(digit.size() == 7) d_c[3]++; // 8
            	iss >> digit;
	    }
        }
    }
    ifs.clear();
    return d_c;
}

uint64_t sum_vector(std::vector<precision> const &v){
    uint64_t sum = 0;
    for(size_t i = 0, dim = v.size(); i < dim; ++i){ sum += v[i];}
    return sum;
}
//---------------------------------------------------TEST--------------------------------------------------
int main(){
    std::vector<precision> digit_counter = read_digit_from_file("input_day8.txt");
    uint64_t ans = sum_vector(digit_counter);
    std::cout << "***** ADVENT OF CODE 2021 - DAY 8 - PART I *****\n";
    //std::cout << "\n1,4,7 and 8 appear: " << ans << " times\n"; // Fifteenth star ***************
    return 0;
}
