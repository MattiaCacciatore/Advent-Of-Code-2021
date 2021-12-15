#include <iostream>
#include <sstream>  // iss
#include <fstream>  // ifs
#include <string>
#include <vector>
//---------------------------------ADVENT OF CODE 2021 - DAY 6 - PART I -----------------------------------
//-------------------------------------------------FUNCTIONS-----------------------------------------------
void check_breeding(std::vector<short int> &s_f){
    for(size_t i = 0, dim = s_f.size(); i < dim; ++i){
        if(s_f[i] < 0){            // Time to breed.
            s_f[i] = 6;            // Reset breed count down.
            s_f.push_back(8);      // A new fish is born.
        }
    }
}

void daytime(std::vector<short int> &s_f){
    for(size_t i = 0, dim = s_f.size(); i < dim; ++i){s_f[i]--;}
    check_breeding(s_f);
}

std::vector<short int> read_fish_from_file(std::istream& str){
    std::vector<short int> s_f; // School of fish.
    if(str.good()){
        std::string line;
        char garbage;           // See input.
        short int fish;
        std::istringstream iss;

        for(;!str.eof();){
            str.clear();
            getline(str, line);
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
    str.clear();
    return s_f;
}

long long int calculate_growth_rate(std::vector<short int> &s_f, int days){
    for(int d = 0; d < days; ++d){daytime(s_f);}
    long long int total = s_f.size();
    return total;
}
//---------------------------------------------------TEST--------------------------------------------------
int main(){
    std::string file = "input_day6.txt";
    std::ifstream ifs(file.c_str());
    std::vector<short int> school_fish = read_fish_from_file(ifs);
    long long int ans = calculate_growth_rate(school_fish, 80);
    //std::cout << ans << "\n";
    return 0;
}
