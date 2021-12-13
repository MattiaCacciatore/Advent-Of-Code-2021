#include <iostream>
#include <limits>
#include <sstream>
#include <fstream>
#include <string>
//---------------------------------ADVENT OF CODE 2021 - DAY 1 - PART I -----------------------------------
int count_from_file(std::istream& str){ // Stream.
    std::string line;

    getline(str, line); // E.g. line = "163".
    if(!str.good()){
    	str.clear();
    	return -1;
	}

    std::istringstream iss; // Input stream to operate on strings.
    int curr_num = 0, prev_num = std::numeric_limits<int>::max(), n_count = 1; // Numbers and counter.

    for(;!str.eof();){
        getline(str, line);
        iss.clear();
        iss.str(line);
        iss >> curr_num;
        if(curr_num > prev_num) n_count++;
        prev_num = curr_num;
    }
    str.clear();
    return n_count;
}
//---------------------------------------------------TEST--------------------------------------------------
int main(){
    std::string file = "input_day1.txt";
    std::ifstream ifs(file.c_str());
    int ans = count_from_file(ifs); // Answer.
    //std::cout << ans << "\n";
    return 0;
}
