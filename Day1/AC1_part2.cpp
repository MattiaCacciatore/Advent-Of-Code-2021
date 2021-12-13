#include <iostream>
#include <limits>
#include <sstream>
#include <fstream>
#include <string>
//---------------------------------ADVENT OF CODE 2021 - DAY 1 - PART II ----------------------------------
int count_from_file(std::istream& str){ // Stream.
    if(!str.good()){         // Check if the file exists.
    	str.clear();
    	return -1;
    }

    std::string line;
    std::istringstream iss; // Input stream to operate on strings.
    int s_w_one = 0, s_w_two = 0, s_w_three = 0, curr_sum = 0, prev_sum = 0, n_count = 0; // Sliding windows and counter.
    getline(str, line);     // E.g. line = "163".
    iss.clear();            // Clear the stream.
    iss.str(line);
    iss >> s_w_one;         // E.g. "163" --> 163
    getline(str, line);
    iss.clear();
    iss.str(line);
    iss >> s_w_two;
    getline(str, line);
    iss.clear();
    iss.str(line);
    iss >> s_w_three;
    curr_sum = s_w_one + s_w_two + s_w_three;

    for(;!str.eof();){      // Until the end of file...
        if(curr_sum > prev_sum){ n_count++;}
        prev_sum = curr_sum;
        getline(str, line);
        iss.clear();
        iss.str(line);
        s_w_one = s_w_two;
        s_w_two = s_w_three;
        iss >> s_w_three;
        curr_sum = curr_sum = s_w_one + s_w_two + s_w_three;
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
