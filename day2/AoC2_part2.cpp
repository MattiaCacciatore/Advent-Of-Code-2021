// Mattia Cacciatore - Computer Science student at the University of Genoa - Italy
#include <iostream>
#include <sstream>  // iss
#include <fstream>  // ifs
#include <string>
//---------------------------------ADVENT OF CODE 2021 - DAY 2 - PART II -----------------------------------
uint64_t read_path_from_file(std::string input){
    std::ifstream ifs(input);
    uint64_t forwrd = 0, aim = 0, depth = 0;
    if(ifs.good()){
        std::string line, dir, mov;              // Direction and movement.
        std::istringstream iss;

        for(;!ifs.eof();){
            getline(ifs, line);
            iss.clear();
            iss.str(line);
            iss >> dir;
            if(dir == "forward"){
                iss >> mov;
                forwrd += (mov[0] - '0');        // Horizontal position.
                depth += (aim * (mov[0] - '0')); // Depth.
            }
            else if(dir == "up"){
                iss >> mov;
                aim -= (mov[0] - '0');
            }
            else if(dir == "down"){
                iss >> mov;
                aim += (mov[0] - '0');
            }
            else{
                std::cerr << "Invalid format input!\n";
                return -1;
            }
        }
    }
    ifs.clear();
    depth *= forwrd;
    return depth ;
}
//---------------------------------------------------TEST--------------------------------------------------
int main(){
    uint64_t ans = read_path_from_file("input_day2.txt");
    std::cout << "***** ADVENT OF CODE 2021 - DAY 2 - PART II *****\n";
    //std::cout << "\nCurrent depth level of the submarine: " << ans << "\n"; // Fourth star ****
    return 0;
}
