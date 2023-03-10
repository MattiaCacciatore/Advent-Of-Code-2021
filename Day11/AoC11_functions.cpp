// Mattia Cacciatore - Computer Science student at the University of Genoa - Italy
#include "AoC11.h"
//--------------------------------- ADVENT OF CODE 2021 - DAY 11 ------------------------------------------
//-----------------------------------------HELPER FUNCTIONS------------------------------------------------
/* Increment the energy of all octopuses by 1. */
void increment_energy(){
    for(size_t i = 0; i < CAVERN_SIZE; ++i){
        for(size_t j = 0; j < CAVERN_SIZE; ++j){
            cavern[i][j].energy++;
        }
    }
}

/* Given the coordinates of one octopus, it increment the energy of all adjacent octopuses by 1. */
void increment_adjacent_energy(ssize_t r, ssize_t c){
	if((r - 1) >= 0){
		// TOP LEFT.
		if((c - 1) >= 0) cavern[r-1][c-1].energy++;
		// TOP.
		cavern[r-1][c].energy++;
		// TOP RIGHT.
		if((c + 1) < CAVERN_SIZE) cavern[r-1][c+1].energy++;
	}
	// RIGHT.
	if((c + 1) < CAVERN_SIZE) cavern[r][c+1].energy++;
	
	if((r + 1) < CAVERN_SIZE){
		// BOTTOM RIGHT.
		if((c + 1) < CAVERN_SIZE) cavern[r+1][c+1].energy++;
		// BOTTOM.
		cavern[r+1][c].energy++;
		// BOTTOM LEFT.
		if((c - 1) >= 0) cavern[r+1][c-1].energy++;
	}
	// LEFT.
	if((c - 1) >= 0) cavern[r][c-1].energy++;	
}

uint64_t flashes_dumbo_octopuses(){
	uint64_t no_flashes = 0; // Number of flashes. Reset.
    	// (CAVERN_SIZE * 2) is an overestimation of the number of step needed to spread all flashes.
	for(size_t s = 0; s < (CAVERN_SIZE * 2); ++s){
		for(size_t i = 0; i < CAVERN_SIZE; ++i){
        		for(size_t j = 0; j < CAVERN_SIZE; ++j){
                		// Only in the first step it incresases the energy of all octopuses by 1, then
                		// it'll spread the flashes.
        			if(s == 0) cavern[i][j].energy++;
        	
        			if(cavern[i][j].energy > 9 && !cavern[i][j].flashed){
        				cavern[i][j].flashed = true;
        				no_flashes++;
        				increment_adjacent_energy(i,j);
				}
        		}
    		}
	}
	return no_flashes;
}

/* Reset the entire matrix. */
void reset_energy(){
    for(size_t i = 0; i < CAVERN_SIZE; ++i){
        for(size_t j = 0; j < CAVERN_SIZE; ++j){
            if(cavern[i][j].flashed){
                cavern[i][j].energy = 0;
                cavern[i][j].flashed = false;
            }
        }
    }
}

bool check_all_flashed(){
	for(size_t i = 0; i < CAVERN_SIZE; ++i){
        	for(size_t j = 0; j < CAVERN_SIZE; ++j){
            		if(!cavern[i][j].flashed) return false;
        	}
    	}
   	return true;
}
//------------------------------------------------FUNCTIONS------------------------------------------------
void read_cavern_from_file(std::string input){
	std::ifstream ifs(input);
    	if(ifs.good()){
        	int fe;                     // Fish's energy.
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
                    			fe = (cave[i] - '0');   // Getting the energy value.
                    			cavern[r][c].energy = fe;
                    			cavern[r][c].flashed = false;
                		}
            			iss >> cave;
			}
        	}
    	}
    	ifs.clear();
}

std::vector<uint64_t> count_flashes(uint64_t steps){
	std::vector<uint64_t> res; // Results.
	res.push_back(0); // Total flashes.
	res.push_back(0); // First step when all octopuses flash.
	bool first_flash = true;
    	for(uint64_t s = 0; s < steps; ++s){
        	res[0] += flashes_dumbo_octopuses(); // First step.
        	if(first_flash && check_all_flashed()){
        		res[1] = s + 1;
        		first_flash = false;
			}
        	reset_energy();            // Second and last step.
    	}
    	return res;
}
