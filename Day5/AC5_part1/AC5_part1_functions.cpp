#include "AC5_part1.h"
//---------------------------------ADVENT OF CODE 2021 - DAY 5 - PART I -----------------------------------
//-------------------------------------------HELPER FUNCTIONS----------------------------------------------
void mark_vent(std::vector<std::vector<int>> &v_m, std::vector<int> const &v){
    int x1, y1, x2, y2, x_max, x_min, y_max, y_min;
    x1 = v[0];
    y1 = v[1];
    x2 = v[2];
    y2 = v[3];
    if(x1 == x2 || y1 == y2){              // Horizontal and vertical vents.
        x_max = x1 > x2 ? x1 : x2;
        x_min = x1 < x2 ? x1 : x2;
        y_max = y1 > y2 ? y1 : y2;
        y_min = y1 < y2 ? y1 : y2;
        for(int x = x_min; x <= x_max; ++x){
            for(int y = y_min; y <= y_max; ++y){
                v_m[x][y] = v_m[x][y] + 1; // Mapping the vent.
            }
        }
    }
}
//-------------------------------------------------FUNCTIONS-----------------------------------------------
std::vector<std::vector<int>> read_vents_from_file(std::istream& str){
    std::vector<std::vector<int>> vents;
    if(str.good()){
        std::string line;
        char garbage;       // See input.
        int x1, y1, x2, y2; // Coordinates.
        std::istringstream iss;

        for(;!str.eof();){
            str.clear();
            getline(str, line);
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
            std::vector<int> vent = {x1, y1, x2, y2};
            vents.push_back(vent);
        }
    }
    str.clear();
    return vents;
}

std::vector<std::vector<int>> create_map(size_t dim){
    std::vector<std::vector<int>> v_map;  // Map 2D dim * dim.
    v_map.resize(dim);
    for(size_t i = 0; i < dim; ++i){v_map[i].resize(dim);}
    return v_map;
}

void mark_all_vents(std::vector<std::vector<int>> &vents_map, std::vector<std::vector<int>> &vents){
    for(size_t i = 0, dim = vents.size(); i < dim; ++i){
            mark_vent(vents_map, vents[i]);
    }
}

long long int count_vents_in_map(std::vector<std::vector<int>> const &v_m, size_t x_max, size_t y_max){
    long long int v = 0;
    for(size_t x = 0; x < x_max; ++x){
        for(size_t y = 0; y < y_max; ++y){
            if(v_m[x][y] > 1) ++v;
        }
    }
    return v;
}
