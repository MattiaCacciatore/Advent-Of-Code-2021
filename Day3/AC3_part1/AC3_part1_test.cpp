#include "AC3_part1.h"
//---------------------------------ADVENT OF CODE 2021 - DAY 3 - PART I -----------------------------------
//---------------------------------------------------TEST--------------------------------------------------
int main(){
	std::string file = "input_day3.txt";
	std::ifstream ifs(file.c_str());
	std::vector<std::vector<short int>> report = read_from_file(ifs);
	std::vector<short int> gamma_rate = find_most_common_bit_number(report);
	int g_r = calculate_gamma_rate(gamma_rate);
	int e_r = calculate_epsilon_rate(gamma_rate);
	long long int ans = calculate_power_consumption(g_r, e_r);
	//std::cout << ans << "\n";
	return 0;
}
