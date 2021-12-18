// Mattia Cacciatore - Computer Science student at the University of Genoa - Italy
#include "AoC3_part1.h"
//---------------------------------ADVENT OF CODE 2021 - DAY 3 - PART I -----------------------------------
//---------------------------------------------------TEST--------------------------------------------------
int main(){
	std::vector<std::vector<precision>> report = read_report_from_file("input_day3.txt");
	std::vector<precision> gamma_rate = find_most_common_bit_number(report);
	uint32_t g_r = calculate_gamma_rate(gamma_rate);
	uint32_t e_r = calculate_epsilon_rate(gamma_rate);
 	uint64_t ans = calculate_power_consumption(g_r, e_r);
	std::cout << "***** ADVENT OF CODE 2021 - DAY 3 - PART I *****\n";
        //std::cout << "\nSubmarine power consumption is: " << ans << "\n"; // Fifth star *****
	return 0;
}
