// Mattia Cacciatore - Computer Science student at the University of Genoa - Italy
#include <iostream>
#include <sstream>   // iss
#include <fstream>   // ifs
#include <string>
#include <vector>

typedef uint8_t precision;
//---------------------------------ADVENT OF CODE 2021 - DAY 9 - PART I -----------------------------------
//----------------------------------------------FUNCTIONS--------------------------------------------------
std::vector<std::vector<precision>> read_map_from_file(std::string input){
    std::vector<std::vector<precision>> m; // Map.
    std::ifstream ifs(input);
    if(ifs.good()){
        precision h;                       // Height.
        std::vector<precision> c;          // Caves.
        std::string line, cave;
        std::istringstream iss;

        for(;!ifs.eof();){
            ifs.clear();
            getline(ifs, line);
            iss.clear();
            iss.str(line);
            iss >> cave;
            for(;iss;){
                for(size_t i = 0, dim = cave.size(); i < dim; ++i){
                    h = (cave[i] - '0');   // Getting the number.
                    c.push_back(h);
                }
                m.push_back(c);            // Cave complete.
                c.clear();
            	iss >> cave;
	    }
        }
    }
    ifs.clear();
    return m;
}

uint64_t sum_all_low_points(std::vector<std::vector<precision>> const& m){
    uint64_t sum = 0;
    precision n, up, down, left, right;
    for(ssize_t r = 0, row = m.size(); r < row; ++r){
        for(ssize_t c = 0, col = m[r].size(); c < col; ++c){
            n = m[r][c];
            up = down = left = right = 10;                                // Reset.

            if(c > 0){left = m[r][c - 1];}
            if(c + 1 < col){right = m[r][c + 1];}
            if(r > 0){up = m[r - 1][c];}
            if(r + 1 < row){down = m[r + 1][c];}

            if(n < up && n < down && n < left & n < right) sum += n + 1;  // Hot spot. Low point.
        }
    }
    return sum;
}
//---------------------------------------------------TEST--------------------------------------------------
int main(){
    std::vector<std::vector<precision>> cave_map = read_map_from_file("input_day9.txt");
    uint64_t ans = sum_all_low_points(cave_map);
    std::cout << "***** ADVENT OF CODE 2021 - DAY 9 - PART I *****\n";
    //std::cout << "\nThe number of low points is: " << ans << "\n"; // Seventeenth star *****************
    return 0;
}
