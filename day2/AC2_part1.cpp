#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
//---------------------------------ADVENT OF CODE 2021 - DAY 2 - PART I -----------------------------------
long long int readFromFile(std::istream& str){
    if(!str.good()){
    	str.clear();
    	return -1;
	  }

	  std::string line, dir, mov; // Direction and movement.
	  std::istringstream iss;
    int h_p = 0, up = 0, down = 0;
    long long int depth = 0;

    for(;!str.eof();){
        getline(str, line);
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
    str.clear();
    depth = h_p * (down - up);
    return depth;
}
//---------------------------------------------------TEST--------------------------------------------------
int main(){
    std::string file = "input_day2.txt";
    std::ifstream ifs(file.c_str());
    long long int ans = readFromFile(ifs);
    //std::cout << ans << "\n";
    return 0;
}
