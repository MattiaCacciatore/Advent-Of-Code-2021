// Mattia Cacciatore - Computer Science student at Genoa University - Italy
#include <iostream>
#include <sstream>  // iss
#include <fstream>  // ifs
#include <string>
//---------------------------------ADVENT OF CODE 2021 - DAY 2 - PART I -----------------------------------
uint64_t read_path_from_file(std::string input){
    std::ifstream ifs(input);
    uint64_t h_p = 0, up = 0, down = 0, depth = 0;
    if(ifs.good()){
        std::string line, dir, mov; // Direction and movement.
        std::istringstream iss;

        for(;!ifs.eof();){
            getline(ifs, line);
            iss.clear();
            iss.str(line);
            iss >> dir;
            if(dir == "forward"){
                iss >> mov;
                h_p += (mov[0] - '0'); // Horizontal position
            }
            else if(dir == "up"){
                iss >> mov;
                up += (mov[0] - '0'); // Vertical position decrease.
            }
            else if(dir == "down"){
                iss >> mov;
                down += (mov[0] - '0'); // Vertical position increase.
            }
            else{
                std::cerr << "Invalid format input!\n";
                return -1;
            }
        }
    }
    ifs.clear();
    depth = h_p * (down - up);
    return depth;
}
//---------------------------------------------------TEST--------------------------------------------------
int main(){
    uint64_t ans = read_path_from_file("input_day2.txt");
    std::cout << "***** ADVENT OF CODE 2021 - DAY 2 - PART I *****\n";
    std::cout << "\nCurrent depth level of the submarine: " << ans << "\n"; // Second star **
    return 0;
}
