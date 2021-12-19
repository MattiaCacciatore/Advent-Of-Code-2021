// Mattia Cacciatore - Computer Science student at the University of Genoa - Italy
#include <iostream>
#include <sstream>   // iss
#include <fstream>   // ifs
#include <string>
#include <vector>
#include <cstdlib>   // abs
#include <limits>    // uint64_t limit

typedef uint16_t precision;
//---------------------------------ADVENT OF CODE 2021 - DAY 7 - PART II ----------------------------------
//-------------------------------------------HELPER FUNCTIONS----------------------------------------------
uint64_t summation(precision n){
    return ((n * (n + 1)) / 2);
}
//----------------------------------------------FUNCTIONS--------------------------------------------------
std::vector<precision> read_crab_from_file(std::string input){
    std::vector<precision> c; // Crabs.
    std::ifstream ifs(input);
    if(ifs.good()){
        char garbage;         // See input.
        precision crab;
        std::string line;
        std::istringstream iss;

        for(;!ifs.eof();){
            ifs.clear();
            getline(ifs, line);
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
    ifs.clear();
    return c;
}

uint64_t calculate_least_fuel(std::vector<precision> &c){
    uint64_t fuel = std::numeric_limits<uint64_t>::max(), prev_fuel; // Max fuel in order to find the least.
    precision crab = 0;

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
    std::vector<precision> crabs = read_crab_from_file("input_day7.txt");
    uint64_t ans = calculate_least_fuel(crabs);
    std::cout << "***** ADVENT OF CODE 2021 - DAY 7 - PART II *****\n";
    //std::cout << "\nThe least fuel consumption is: " << ans << "\n"; // Fourteenth star **************
    return 0;
}
