#include "AC3_part2.h"
//---------------------------------ADVENT OF CODE 2021 - DAY 3 - PART II ----------------------------------
//------------------------------------------HELPER FUNCTIONS-----------------------------------------------
int bit_vector_to_int(std::vector<short int> v){
    long long int num = 0;
    std::reverse(v.begin(), v.end()); // E.g. 1100 --> 0011 so it can computes the result correctly.

    for(size_t i = 0; i < SIZE; ++i){
        if(v[i] == 1){num += pow(2,i);}
    }
    return num;
}

std::vector<short int> find_oxygen_rate(std::vector<std::vector<short int>> const &r){
    std::vector<std::vector<short int>> oxygen, tmp(r);      // Oxygen report.
    long long int ones, zeroes;

    for(size_t i = 0; i < SIZE; ++i){
        ones = zeroes = 0;                                   // Reset.

        for(size_t j = 0, dim = tmp.size(); j < dim; ++j){   // Counting ones and zeroes on the
            if(tmp[j][i] == 1) ones++;                       // i-th bit in the oxygen report.
            else zeroes++;
        }

        if(ones >= zeroes){                                  // Bit criteria oxygen: most common bit.
            for(size_t j = 0, dim = tmp.size(); j < dim; ++j){
                if(tmp[j][i] == 1) oxygen.push_back(tmp[j]); // Selecting valid oxygen reports.
            }
        }
        else{ // Zeroes > ones.
            for(size_t j = 0, dim = tmp.size(); j < dim; ++j){
                if(tmp[j][i] == 0) oxygen.push_back(tmp[j]); // Same here.
            }
        }

        tmp.resize(oxygen.size());
        for(size_t j = 0, dim = tmp.size(); j < dim; ++j){tmp[j] = oxygen[j];}  // Overwrite the oxygen report.
        oxygen.resize(0);
    }
    return oxygen[0];                                        // Only 1 report remains at the end.
}

std::vector<short int> find_carbon_rate(std::vector<std::vector<short int>> const &r){
    std::vector<std::vector<short int>> carbon, tmp(r);      // Carbon report.
    long long int ones, zeroes;

    for(size_t i = 0; i < SIZE; ++i){
        ones = zeroes = 0; // Reset.

        for(size_t j = 0, dim = tmp.size(); j < dim; ++j){   // Counting ones and zeroes on the
            if(tmp[j][i] == 1) ones++;                       // i-th bit in the carbon report.
            else zeroes++;
        }

        if(zeroes <= ones){                                  // Bit criteria carbon: least common bit.
            for(size_t j = 0, dim = tmp.size(); j < dim; ++j){
                if(tmp[j][i] == 0) carbon.push_back(tmp[j]); // Selecting valid carbon reports.
            }
        }
        else{ // Zeroes > ones.
            for(size_t j = 0, dim = tmp.size(); j < dim; ++j){
                if(tmp[j][i] == 1) carbon.push_back(tmp[j]); // Same here.
            }
        }

        tmp.resize(carbon.size());
        for(size_t j = 0, dim = tmp.size(); j < dim; ++j){tmp[j] = carbon[j];} // Overwrite the carbon report.
        carbon.resize(0);
    }
    return carbon[0];                                        // Only 1 report remains at the end.
}
//-------------------------------------------------FUNCTIONS-----------------------------------------------
std::vector<std::vector<short int>> read_from_file(std::istream& str){
    std::vector<std::vector<short int>> r; // Report.
    if(str.good()){
        std::string line, bn;     // Binary number.
        std::istringstream iss;   // Input stream to operate on strings.
        std::vector<short int> n; // Number.
        n.resize(SIZE);

        for(;!str.eof();){
            getline(str, line); // E.g. line = "1011"
            iss.clear();
            iss.str(line);
            iss >> bn;
            for(size_t i = 0; i < SIZE; ++i){
                if(bn[i] == '1') n[i] = 1;
                else n[i] = 0;
            }
            r.push_back(n);
        }
    }
    str.clear();
    return r;
}

long long int find_air_rate(std::vector<std::vector<short int>> const &r){
    long long int a_r = 0; // Air rate.
    int o, c;              // Oxygen and carbon dioxide.
    std::vector<short int> oxygen = find_oxygen_rate(r);
    std::vector<short int> carbon = find_carbon_rate(r);
    o = bit_vector_to_int(oxygen);
    c = bit_vector_to_int(carbon);
    a_r = o * c;
    return a_r;
}
