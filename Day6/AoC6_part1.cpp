// Mattia Cacciatore - Computer Science student at the University of Genoa - Italy
#include <iostream>
#include <sstream>  // iss
#include <fstream>  // ifs
#include <string>
#include <vector>

typedef int16_t precision;
//---------------------------------ADVENT OF CODE 2021 - DAY 6 - PART I -----------------------------------
//-------------------------------------------------FUNCTIONS-----------------------------------------------
void check_breeding(std::vector<precision> &s_f){
    for(size_t i = 0, dim = s_f.size(); i < dim; ++i){
        if(s_f[i] < 0){            // Time to breed.
            s_f[i] = 6;            // Reset breed count down.
            s_f.push_back(8);      // A new fish is born.
        }
    }
}

void daytime(std::vector<precision> &s_f){
    for(size_t i = 0, dim = s_f.size(); i < dim; ++i){s_f[i]--;} // Inefficient version. I know, i know...
    check_breeding(s_f);                                         // it just works for few days. See part II.
}

std::vector<precision> read_fish_from_file(std::string input){
    std::vector<precision> s_f; // School of fish.
    std::ifstream ifs(input);
    if(ifs.good()){
        char garbage;           // See input.
        precision fish;
        std::string line;
        std::istringstream iss;

        for(;!ifs.eof();){
            ifs.clear();
            getline(ifs, line);
            iss.clear();
            iss.str(line);
            iss >> fish;
            for(;iss;){
                iss >> garbage; // ,
                s_f.push_back(fish);
                iss >> fish;
            }
        }
    }
    ifs.clear();
    return s_f;
}

size_t calculate_growth_rate(std::vector<precision> &s_f, uint32_t days){
    for(uint32_t d = 0; d < days; ++d){daytime(s_f);}
    size_t total = s_f.size();
    return total;
}
//---------------------------------------------------TEST--------------------------------------------------
int main(){
    std::vector<precision> school_fish = read_fish_from_file("input_day6.txt");
    uint32_t days = 80;
    size_t ans = calculate_growth_rate(school_fish, days);
    std::cout << "***** ADVENT OF CODE 2021 - DAY 6 - PART I *****\n";
    //std::cout << "\nThe number of fishes after " << days << " days is: " << ans << "\n"; // Eleventh star ***********
    return 0;
}
