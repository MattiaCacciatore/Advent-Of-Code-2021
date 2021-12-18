// Mattia Cacciatore - Computer Science student at the University of Genoa - Italy
#include "AoC5_part2.h"
//---------------------------------ADVENT OF CODE 2021 - DAY 5 - PART II ----------------------------------
//-------------------------------------------HELPER FUNCTIONS----------------------------------------------
void mark_vent(std::vector<std::vector<precision>> &v_m, std::vector<precision> const &v){
    if(v.size() != 4) return;
    precision x1 = v[0], y1 = v[1], x2 = v[2], y2 = v[3], x_max, x_min, y_max, y_min;

    if(x1 == x2 || y1 == y2){               // Horizontal and vertical vents.
        x_max = x1 > x2 ? x1 : x2;
        x_min = x1 < x2 ? x1 : x2;
        y_max = y1 > y2 ? y1 : y2;
        y_min = y1 < y2 ? y1 : y2;
        for(size_t x = x_min; x <= x_max; ++x){
            for(size_t y = y_min; y <= y_max; ++y){v_m[x][y]++;} // Mapping.
        }
    }
    else if(abs(x1 - x2) == abs(y1 - y2)){ // Diagonal vents.
        if(x1 < x2 && y1 < y2){            // Bottom left to top right.
            for(ssize_t x = x1, y = y1; x <= x2 && y <= y2; ++x, ++y){v_m[x][y]++;}
        }
        else if(x1 < x2 && y1 > y2){       // Top left to bottom right.
            for(ssize_t x = x1, y = y1; x <= x2 && y >= y2; ++x, --y){v_m[x][y]++;}
        }
        else if(x1 > x2 && y1 < y2){       // Bottom right to top left.
            for(ssize_t x = x1, y = y1; x >= x2 && y <= y2; --x, ++y){v_m[x][y]++;}
        }
        else{                              // x1 > x2 && y1 > y2 Top right to bottom left.
            for(ssize_t x = x1, y = y1; x >= x2 && y >= y2; --x, --y){v_m[x][y]++;}
        }
    }
}
//-------------------------------------------------FUNCTIONS-----------------------------------------------
std::vector<std::vector<precision>> read_vents_from_file(std::string input){
    std::vector<std::vector<precision>> vents;
    std::ifstream ifs(input);
    if(ifs.good()){
        char garbage;             // See input.
        precision x1, y1, x2, y2; // Coordinates.
        std::string line;
        std::istringstream iss;

        for(;!ifs.eof();){
            ifs.clear();
            getline(ifs, line);
            iss.clear();
            iss.str(line);
            iss >> x1;
            iss >> garbage; // ,
            iss >> y1;
            iss >> garbage; // -
            iss >> garbage; // >
            iss >> x2;
            iss >> garbage; // ,
            iss >> y2;
            std::vector<precision> vent = {x1, y1, x2, y2};
            vents.push_back(vent);
        }
    }
    ifs.clear();
    return vents;
}

std::vector<std::vector<precision>> create_map(size_t dim){
    std::vector<std::vector<precision>> v_map;
    v_map.resize(dim);
    for(size_t i = 0; i < dim; ++i){v_map[i].resize(dim);}
    return v_map;
}

void mark_all_vents(std::vector<std::vector<precision>> &vents_map, std::vector<std::vector<precision>> &vents){
    for(size_t i = 0, dim = vents.size(); i < dim; ++i){
        mark_vent(vents_map, vents[i]);
    }
}

uint64_t count_vents_in_map(std::vector<std::vector<precision>> const &v_m, size_t x_max, size_t y_max){
    uint64_t v = 0;
    for(size_t x = 0; x < x_max; ++x){
        for(size_t y = 0; y < y_max; ++y){
            if(v_m[x][y] > 1) ++v;
        }
    }
    return v;
}
