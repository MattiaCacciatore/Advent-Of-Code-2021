// Mattia Cacciatore - Computer Science student at the University of Genoa - Italy
#include "AoC12_part1.h"
//---------------------------------------------------TEST--------------------------------------------------
int main(){
	std::vector<cave> caves = read_caves_from_file("input_day12.txt");
	// 10.000.000 iterations is like killing a mosquito with a cannon.
	// It's an overestimation of the number of attempts needed to get
	// the right answer because the path finding is (pseudo)random.
	size_t ans = all_paths(caves, 10000000);
	std::cout << "\n***** ADVENT OF CODE 2021 - DAY 12 - PART I *****\n";
    //std::cout << "\nThe number of different paths is: " << ans << "\n"; // Twenty-third star ***********************
	return 0;
}
