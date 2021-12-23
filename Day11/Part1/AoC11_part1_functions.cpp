// Mattia Cacciatore - Computer Science student at the University of Genoa - Italy
#include "AoC11_part1.h"
//---------------------------------ADVENT OF CODE 2021 - DAY 11 - PART I ----------------------------------
//---------------------------------------------HELPER FUNCTIONS--------------------------------------------
void increment_energy(){
    for(size_t i = 0; i < CAVERN_SIZE; ++i){
        for(size_t j = 0; j < CAVERN_SIZE; ++j){
            cavern[i][j].energy++;
        }
    }
}

uint64_t flashes_dumbo_octopuses(){
    uint64_t f = 0;
    for(size_t i = 0; i < CAVERN_SIZE; ++i){
        for(size_t j = 0; j < CAVERN_SIZE; ++j){
            if(cavern[i][j].energy > 9 && !cavern[i][j].flashed){ // Flash!
                ++f;
 //--------------------------------------TO REDO - IT DOESN'T WORK---------------------------------------
                cavern[i][j].flashed = true; // Read the README file.
                for(ssize_t y = i - 1; y <= i + 1; ++y){
                    for(ssize_t x = j - 1; y <= j + 1; ++x){
                        if(x < 0 || y < 0 || x >= CAVERN_SIZE || y >= CAVERN_SIZE) continue;
                        else cavern[y][x].energy++;
                    }
                }
                i = j = 0; // Trivial reset.
//-------------------------------------------------------------------------------------------------------
            }
        }
    }
    return f;
}

void reset_energy(){
    for(size_t i = 0; i < CAVERN_SIZE; ++i){
        for(size_t j = 0; j < CAVERN_SIZE; ++j){
            if(cavern[i][j].energy > 9){
                cavern[i][j].energy = 0;
            }
            cavern[i][j].flashed = false;
        }
    }
}
//------------------------------------------------FUNCTIONS------------------------------------------------
void read_cavern_from_file(std::string input){
	std::ifstream ifs(input);
    if(ifs.good()){
        int e;                     // Fish's energy.
        size_t r = 0, c = 0;
        std::string line, cave;
        std::istringstream iss;

        for(;!ifs.eof();){
            getline(ifs, line);
            iss.clear();
            iss.str(line);
            iss >> cave;
            for(;iss; ++r){
                for(size_t i = 0, dim = cave.size(), c = 0; i < dim; ++i, ++c){
                    e = (cave[i] - '0');   // Getting the energy value.
                    cavern[r][c].energy = e;
                    cavern[r][c].flashed = false;
                }
            	  iss >> cave;
			      }
        }
    }
    ifs.clear();
}

uint64_t count_flashes(uint64_t steps){
    uint64_t t_f = 0;                     // Total flashes.
    for(uint64_t s = 0; s < steps; ++s){
        increment_energy();               // First step.
        t_f += flashes_dumbo_octopuses(); // Second step.
        reset_energy();                   // Third and last step.
    }
    return t_f;
}
