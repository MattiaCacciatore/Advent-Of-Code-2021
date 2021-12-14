#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
//---------------------------------ADVENT OF CODE 2021 - DAY 2 - PART II ----------------------------------
long long int readFromFile(std::istream& str){
    if(!str.good()){
    	str.clear();
    	return -1;
    }

    std::string line, dir, mov; // Direction and movement.
    std::istringstream iss;
    int forwrd = 0, aim = 0;
    long long int depth = 0;

    for(;!str.eof();){
        getline(str, line);
        iss.clear();
        iss.str(line);
	iss >> dir;
	iss >> mov;
        if(dir == "forward"){
            forwrd += (mov[0] - '0');        // Horizontal position.
            depth += (aim * (mov[0] - '0')); // Depth.
        }
        else if(dir == "up")
            aim -= (mov[0] - '0');
        else if(dir == "down")
            aim += (mov[0] - '0');
	else{
	   std::cerr << "Invalid input format!\n";
	   return -1;
	}
    }
    str.clear();
    return depth * forwrd;
}
//---------------------------------------------------TEST--------------------------------------------------
int main(){
    std::string file = "input_day2.txt";
    std::ifstream ifs(file.c_str());
    long long int ans = readFromFile(ifs);
    //std::cout << ans << "\n";
    return 0;
}

