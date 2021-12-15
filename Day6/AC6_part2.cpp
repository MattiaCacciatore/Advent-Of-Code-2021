#include <iostream>
#include <sstream>  // iss
#include <fstream>  // ifs
#include <string>
#include <vector>
#include <limits>   // size_t limit
//---------------------------------ADVENT OF CODE 2021 - DAY 6 - PART II ----------------------------------
//-------------------------------------------HELPER FUNCTIONS----------------------------------------------
void daytime(std::vector<size_t> &s_f){
    size_t d0 = s_f[0];
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
size_t calculate_growth_rate(std::vector<size_t> &s_f, int days){
    size_t total = 0;
    if(s_f.size() == 9){
       for(int d = 0; d < days; ++d){daytime(s_f);}
       total = s_f[0] + s_f[1] + s_f[2] + s_f[3] + s_f[4] + s_f[5] + s_f[6] + s_f[7] + s_f[8];
    }
    return total;
}

std::vector<size_t> read_fish_from_file(std::istream& str){
    std::vector<size_t> s_f;    // School of fish.
    s_f.resize(9);              // From day0 to day8.
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
				if(fish == 0) s_f[0]++;       // Fishes reproduce on a 8-day cycle,
				else if(fish == 1) s_f[1]++;  // so it's important to know how many
				else if(fish == 2) s_f[2]++;  // fishes are there and which is their day cicle
				else if(fish == 3) s_f[3]++;  // status. In order to avoid RAM saturation
				else if(fish == 4) s_f[4]++;  // caused by immense vector/list, it's a most
				else if(fish == 5) s_f[5]++;  // pratical way to record them in this form.
				else if(fish == 6) s_f[6]++;
				else if(fish == 7) s_f[7]++;
				else if(fish == 8) s_f[8]++;
				else{
					std::cerr << "Invalid input format\n";
					s_f.clear();
					return s_f;
				}
                iss >> fish;
            }
        }
    }
    str.clear();
    return s_f;
}
//---------------------------------------------------TEST--------------------------------------------------
int main(){
	// Make sure i don't mess it up. It's big enough.
	//std::cout << std::numeric_limits<std::size_t>::max();
    std::string file = "input_day6.txt";
    std::ifstream ifs(file.c_str());
    std::vector<size_t> school_fish = read_fish_from_file(ifs);
    size_t ans = calculate_growth_rate(school_fish, 256);
    //std::cout << ans << "\n";
    return 0;
}
