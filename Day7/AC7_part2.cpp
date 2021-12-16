#include <iostream>
#include <sstream>   // iss
#include <fstream>   // ifs
#include <string>
#include <vector>
#include <cstdlib>   // abs
#include <algorithm> // sort
#include <limits>    // long long int limit
//---------------------------------ADVENT OF CODE 2021 - DAY 7 - PART II ----------------------------------
//-------------------------------------------HELPER FUNCTIONS----------------------------------------------
long long int summation(short int n){
	return ((n * (n + 1)) / 2);
}
//----------------------------------------------FUNCTIONS--------------------------------------------------
std::vector<short int> read_crab_from_file(std::istream& str){
    std::vector<short int> c; // Crabs.
    if(str.good()){
        std::string line;
        char garbage;         // See input.
        short int crab;
        std::istringstream iss;

        for(;!str.eof();){
            str.clear();
            getline(str, line);
            iss.clear();
            iss.str(line);
            iss >> crab;
            for(;iss;){
                iss >> garbage; // ,
				c.push_back(crab);
                iss >> crab;
            }
        }
    }
    str.clear();
    return c;
}

long long int calculate_least_fuel(std::vector<short int> &c){
	long long int fuel = std::numeric_limits<long long int>::max(), prev_fuel; // Max fuel in order to find the least.
	short int crab = 0;
	
	for(size_t i = 0, dim = c.size(); i < dim; ++i){
		prev_fuel = 0; // Reset.
		crab = c[i];   // Let's see if this crab position is the median.
		for(size_t j = 0; j < dim; ++j){prev_fuel += summation(abs(c[j] - crab));} // Previous fuel consumption.
		if(fuel > prev_fuel) fuel = prev_fuel; // Less fuel?
	}
	
	return fuel;
}
//---------------------------------------------------TEST--------------------------------------------------
int main(){
    std::string file = "input_day7.txt";
    std::ifstream ifs(file.c_str());
    std::vector<short int> crabs = read_crab_from_file(ifs);
    long long int ans = calculate_least_fuel(crabs);
    //std::cout << ans << "\n";
    return 0;
}
