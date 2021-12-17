#include <iostream>
#include <sstream>   // iss
#include <fstream>   // ifs
#include <string>
#include <vector>
//---------------------------------ADVENT OF CODE 2021 - DAY 8 - PART I -----------------------------------
//----------------------------------------------FUNCTIONS--------------------------------------------------
std::vector<int> read_digit_from_file(std::istream& str){
    std::vector<int> d_c; // Digit counter.
    d_c.resize(4);        // 1,4,7 and 8.
    if(str.good()){
        std::string line, digit;
        std::istringstream iss;

        for(;!str.eof();){
            str.clear();
            getline(str, line);
            iss.clear();
            iss.str(line);
            iss >> digit;
            for(;digit != "|";){
                iss >> digit;
            }
            iss >> digit;
            for(;iss;){
            	if(digit.size() == 2) d_c[0]++;      // 1
            	else if(digit.size() == 3) d_c[2]++; // 7
            	else if(digit.size() == 4) d_c[1]++; // 4
            	else if(digit.size() == 7) d_c[3]++; // 8
            	iss >> digit;
			}
        }
    }
    str.clear();
    return d_c;
}

long long int sum_vector(std::vector<int> const &v){
	long long int sum = 0;
	for(size_t i = 0, dim = v.size(); i < dim; ++i){ sum += v[i];}
	return sum;
}
//---------------------------------------------------TEST--------------------------------------------------
int main(){
    std::string file = "input_day8.txt";
    std::ifstream ifs(file.c_str());
    std::vector<int> digit_counter = read_digit_from_file(ifs);
    long long int ans = sum_vector(digit_counter);
    //std::cout << ans << "\n";
    return 0;
}
