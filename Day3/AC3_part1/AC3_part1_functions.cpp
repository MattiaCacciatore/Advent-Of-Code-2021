#include "AC3_part1.h"
//---------------------------------ADVENT OF CODE 2021 - DAY 3 - PART I -----------------------------------
//------------------------------------------HELPER FUNCTIONS-----------------------------------------------
int bit_vector_to_int(std::vector<short int> const &v){
    long long int num = 0;
    std::vector<short int> tmp(v);
    std::reverse(tmp.begin(), tmp.end()); // E.g. 1100 --> 0011 so it can computes the result correctly.

    for(size_t i = 0; i < SIZE; ++i){
        if(tmp[i] == 1){num += pow(2,i);}
    }
    return num;
}

void flip_bit_vector(std::vector<short int> &v){
    for(size_t i = 0; i < SIZE; ++i){
        if(v[i] == 1) v[i] = 0;
        else v[i] = 1;
    }
}
//-------------------------------------------------FUNCTIONS-----------------------------------------------
std::vector<std::vector<short int>> read_from_file(std::istream& str){
    std::vector<std::vector<short int>> r; // Report.
    if(!str.good()){
    	str.clear();
    	return r;
    }

    std::string line, bn; // Binary number.
    std::istringstream iss;
    std::vector<short int> n; // Number.
    v.resize(SIZE);

    for(;!str.eof();){
        getline(str, line);
        iss.clear();
        iss.str(line);
        iss >> bn;
        for(size_t i = 0; i < SIZE; ++i){
            if(bn[i] == '1') n[i] = 1;
            else n[i] = 0;
        }
        r.push_back(n);
    }
    str.clear();
    return r;
}

std::vector<short int> find_most_common_bit_number(std::vector<std::vector<short int>> const &m){
    std::vector<short int> g_r; // Gamma rate vector with most common bits.
    g_r.resize(SIZE);           // All numbers set to 0.
    long long int zeroes, ones;

    for(size_t i = 0; i < SIZE; ++i){
        ones = zeroes = 0;
        for(size_t j = 0, dim = m.size(); j < dim; ++j){ // Counting j-th bit for all i-th numbers.
            if(m[j][i] == 1) ones++;
            else zeroes++;
        }

        if(ones > zeroes){g_r[i] = 1;} // Most common bit?
    }
    return g_r;
}

int calculate_gamma_rate(std::vector<short int> const &v){
    int g_r = bit_vector_to_int(v);
    return g_r;
}

int calculate_epsilon_rate(std::vector<short int> const &v){
    std::vector<short int> tmp(v);
    flip_bit_vector(tmp);             // If v is the bit vector with most common bits, just flipping it
    int e_r = bit_vector_to_int(tmp); // and it becomes the bit vector with least common bits.
    return e_r;
}

long long int calculate_power_consumption(int g_r, int e_r){
    long long int p_c = g_r * e_r;
    return p_c;
}
