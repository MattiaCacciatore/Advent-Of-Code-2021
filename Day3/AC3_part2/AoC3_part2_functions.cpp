// Mattia Cacciatore - Computer Science student at the University of Genoa - Italy
#include "AoC3_part2.h"
//---------------------------------ADVENT OF CODE 2021 - DAY 3 - PART II ----------------------------------
//------------------------------------------HELPER FUNCTIONS-----------------------------------------------
uint32_t bit_vector_to_int(std::vector<precision> v){
    uint32_t num = 0;
    std::reverse(v.begin(), v.end()); // E.g. 1100 --> 0011 so it can computes the result correctly.

    for(size_t i = 0; i < INPUT_SIZE; ++i){
        if(v[i] == 1){num += pow(2,i);}
    }
    return num;
}
//-------------------------------------------------FUNCTIONS-----------------------------------------------
std::vector<precision> find_oxygen_rate(std::vector<std::vector<precision>> const &r){
    std::vector<std::vector<precision>> oxygen(r), tmp;         // Oxygen report.
    uint64_t ones, zeroes;

    for(size_t i = 0; i < INPUT_SIZE; ++i){
        ones = zeroes = 0;                                      // Reset.

        for(size_t j = 0, dim = oxygen.size(); j < dim; ++j){   // Counting ones and zeroes on the
            if(oxygen[j][i] == 1) ones++;                       // i-th bit in the carbon report.
            else zeroes++;
        }

        if(ones >= zeroes){                                     // Bit criteria oxygen: most common bit.
            for(size_t j = 0, dim = oxygen.size(); j < dim; ++j){
                if(oxygen[j][i] == 1) tmp.push_back(oxygen[j]); // Selecting valid oxygen reports.
            }
        }
        else{ // Zeroes > ones.
            for(size_t j = 0, dim = oxygen.size(); j < dim; ++j){
                if(oxygen[j][i] == 0) tmp.push_back(oxygen[j]); // Same here.
            }
        }

        oxygen.resize(tmp.size());
        for(size_t j = 0, dim = oxygen.size(); j < dim; ++j){oxygen[j] = tmp[j];}  // Overwrite the oxygen report.
        tmp.resize(0);
    }
    return oxygen[0];                                           // Only 1 report remains at the end.
}

std::vector<precision> find_carbon_rate(std::vector<std::vector<precision>> const &r){
    std::vector<std::vector<precision>> carbon(r), tmp;         // Carbon report.
    uint64_t ones, zeroes;

    for(size_t i = 0; i < INPUT_SIZE; ++i){
        ones = zeroes = 0; // Reset.

        for(size_t j = 0, dim = carbon.size(); j < dim; ++j){   // Counting ones and zeroes on the
            if(carbon[j][i] == 1) ones++;                       // i-th bit in the carbon report.
            else zeroes++;
        }

        if(zeroes <= ones){                                     // Bit criteria carbon: least common bit.
            for(size_t j = 0, dim = carbon.size(); j < dim; ++j){
                if(carbon[j][i] == 0) tmp.push_back(carbon[j]); // Selecting valid carbon reports.
            }
        }
        else{ // Zeroes > ones.
            for(size_t j = 0, dim = carbon.size(); j < dim; ++j){
                if(carbon[j][i] == 1) tmp.push_back(carbon[j]); // Same here.
            }
        }

        carbon.resize(tmp.size());
        for(size_t j = 0, dim = carbon.size(); j < dim; ++j){carbon[j] = tmp[j];} // Overwrite the carbon report.
        tmp.resize(0);
    }
    return carbon[0];                                           // Only 1 report remains at the end.
}

std::vector<std::vector<precision>> read_from_file(std::string input){
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

uint64_t find_air_rate(std::vector<std::vector<precision>> const &r){
    uint64_t a_r = 0;  // Air rate.
    uint32_t o_r, c_r; // Oxygen and carbon dioxide rates.
    std::vector<precision> oxygen = find_oxygen_rate(r);
    std::vector<precision> carbon = find_carbon_rate(r);
    o_r = bit_vector_to_int(oxygen);
    c_r = bit_vector_to_int(carbon);
    a_r = o_r * c_r;
    return a_r;
}
