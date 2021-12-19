// Mattia Cacciatore - Computer Science student at the University of Genoa - Italy
#include <iostream>
#include <sstream>  // iss
#include <fstream>  // ifs
#include <string>
#include <vector>

typedef int64_t precision;
//---------------------------------ADVENT OF CODE 2021 - DAY 6 - PART II ----------------------------------
//-------------------------------------------HELPER FUNCTIONS----------------------------------------------
void daytime(std::vector<precision> &s_f){
    precision d0 = s_f[0];      // Most efficient solution!
    s_f[0] = s_f[1];
    s_f[1] = s_f[2];
    s_f[2] = s_f[3];
    s_f[3] = s_f[4];
    s_f[4] = s_f[5];
    s_f[5] = s_f[6];
    s_f[6] = s_f[7] + d0;       // Old fishes breed time reset.
    s_f[7] = s_f[8];
    s_f[8] = d0;                // Welcome new fishes!
}
//-------------------------------------------------FUNCTIONS-----------------------------------------------
uint64_t calculate_growth_rate(std::vector<precision> &s_f, uint32_t days){
    for(int d = 0; d < days; ++d){daytime(s_f);}
    uint64_t total = s_f[0] + s_f[1] + s_f[2] + s_f[3] + s_f[4] + s_f[5] + s_f[6] + s_f[7] + s_f[8];
    return total;
}

std::vector<precision> read_fish_from_file(std::string input){
    std::vector<precision> s_f;    // School of fish.
    s_f.resize(9);                 // From day0 to day8.
    std::ifstream ifs(input);
    if(ifs.good()){
        char garbage;              // See input.
        short int fish;
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
		if(fish == 0) s_f[0]++;       // Fishes reproduce on a 8-day cycle,
		else if(fish == 1) s_f[1]++;  // so it's important to know how many
		else if(fish == 2) s_f[2]++;  // fishes are there and which is their day cicle
		else if(fish == 3) s_f[3]++;  // status. In order to avoid RAM saturation
		else if(fish == 4) s_f[4]++;  // caused by immense vector/list, it's a most
		else if(fish == 5) s_f[5]++;  // pratical way to record them in this form.
		else if(fish == 6) s_f[6]++;
		else if(fish == 7) s_f[7]++;
		else if(fish == 8) s_f[8]++;
                iss >> fish;
            }
        }
    }
    ifs.clear();
    return s_f;
}
//---------------------------------------------------TEST--------------------------------------------------
int main(){
    std::vector<precision> school_fish = read_fish_from_file("input_day6.txt");
    uint32_t days = 256;
    uint64_t ans = calculate_growth_rate(school_fish, days);
    std::cout << "***** ADVENT OF CODE 2021 - DAY 6 - PART II *****\n";
    //std::cout << "\nThe number of fishes after " << days << " days is: " << ans << "\n"; // Twelveth star ************
    return 0;
}
