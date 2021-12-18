// Mattia Cacciatore - Computer Science student at the University of Genoa - Italy
#include "AoC3_part1.h"
//---------------------------------ADVENT OF CODE 2021 - DAY 3 - PART I -----------------------------------
//------------------------------------------HELPER FUNCTIONS-----------------------------------------------
uint32_t bit_vector_to_int(std::vector<precision> const &v){
    uint32_t num = 0;
    std::vector<precision> tmp(v);
    std::reverse(tmp.begin(), tmp.end()); // E.g. 1100 --> 0011 so it can computes the result correctly.

    for(size_t i = 0; i < INPUT_SIZE; ++i){
        if(tmp[i] == 1){num += pow(2,i);}
    }
    return num;
}

void flip_bit_vector(std::vector<precision> &v){
    for(size_t i = 0; i < INPUT_SIZE; ++i){
        if(v[i] == 1) v[i] = 0;
        else v[i] = 1;
    }
}
//-------------------------------------------------FUNCTIONS-----------------------------------------------
std::vector<std::vector<precision>> read_report_from_file(std::string input){
    std::ifstream ifs(input);
    std::vector<std::vector<precision>> r;       // Report.
    if(ifs.good()){
        std::string line, bn;                    // Binary number.
        std::istringstream iss;
        std::vector<precision> n(INPUT_SIZE, 0); // Number.

        for(;!ifs.eof();){
            getline(ifs, line);
            iss.clear();
            iss.str(line);
            iss >> bn;
            for(size_t i = 0; i < INPUT_SIZE; ++i){
                if(bn[i] == '1') n[i] = 1;
                else n[i] = 0;
            }
            r.push_back(n);
        }
    }
    ifs.clear();
    return r;
}

std::vector<precision> find_most_common_bit_number(std::vector<std::vector<precision>> const &m){
    std::vector<precision> g_r(INPUT_SIZE, 0);            // Gamma rate vector with most common bits. All numbers set to 0.
    uint64_t zeroes, ones;

    for(size_t i = 0; i < INPUT_SIZE; ++i){
        ones = zeroes = 0;
        for(size_t j = 0, dim = m.size(); j < dim; ++j){ // Counting j-th bit for all i-th numbers.
            if(m[j][i] == 1) ones++;
            else zeroes++;
        }

        if(ones > zeroes){g_r[i] = 1;}                   // Most common bit?
    }
    return g_r;
}

uint32_t calculate_gamma_rate(std::vector<precision> const &v){
    uint32_t g_r = bit_vector_to_int(v);
    return g_r;
}

uint32_t calculate_epsilon_rate(std::vector<precision> const &v){
	std::vector<precision> tmp(v);
	flip_bit_vector(tmp);                  // If v is the bit vector with most common bits, just flipping it
	uint32_t e_r = bit_vector_to_int(tmp); // and it becomes the bit vector with least common bits.
	return e_r;
}

uint64_t calculate_power_consumption(uint32_t g_r, uint32_t e_r){
	uint64_t p_c = g_r * e_r;
	return p_c;
}

