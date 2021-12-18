#include <iostream>
#include <sstream>   // iss
#include <fstream>   // ifs
#include <string>
#include <vector>
//---------------------------------ADVENT OF CODE 2021 - DAY 9 - PART I -----------------------------------
//----------------------------------------------FUNCTIONS--------------------------------------------------
std::vector<std::vector<short int>> read_map_from_file(std::istream& str){
    std::vector<std::vector<short int>> m; // Map.
    if(str.good()){
        std::string line, cave;
        short int h;                       // Height.
        std::vector<short int> c;          // Caves.
        std::istringstream iss;

        for(;!str.eof();){
            str.clear();
            getline(str, line);
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
    str.clear();
    return m;
}

long long int sum_all_low_points(std::vector<std::vector<short int>> const& m){
    long long int sum = 0;
    short int n, up, down, left, right;
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
    std::string file = "input_day9.txt";
    std::ifstream ifs(file.c_str());
    std::vector<std::vector<short int>> cave_map = read_map_from_file(ifs);
    long long int ans = sum_all_low_points(cave_map);
    //std::cout << ans << "\n";
    return 0;
}
