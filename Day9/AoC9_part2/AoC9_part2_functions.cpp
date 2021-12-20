// Mattia Cacciatore - Computer Science student at the University of Genoa - Italy
#include "AoC9_part2.h"

static size_t x_size = 0;  // Map size.
static size_t y_size = 0;
//---------------------------------ADVENT OF CODE 2021 - DAY 9 - PART II ----------------------------------
//------------------------------------------HELPER FUNCTIONS-----------------------------------------------
void set_map_size(std::vector<std::vector<precision>> const &m){
    x_size = m[0].size();
    y_size = m.size();
}
// Recursive.
uint64_t sum_basin_r(std::vector<std::vector<precision>> &m, ssize_t x_pos, ssize_t y_pos){
    uint64_t b_s = 0;                            // Basin size
    if(x_pos >= 0 && y_pos >= 0 && x_pos < x_size && y_pos < y_size && m[y_pos][x_pos] < 9){
        b_s++;
        m[y_pos][x_pos] = 9;                     // Y before X because map orientation.
        // Marking the current cell, in this way it's possible to track the basin.
        // Hint of marking cells here:
        // https://www.reddit.com/r/adventofcode/comments/rchdq4/2021_day_9_part_2_the_floor_is_lava/
        b_s += sum_basin_r(m, x_pos, y_pos - 1); // Top.
        b_s += sum_basin_r(m, x_pos + 1, y_pos); // Right.
        b_s += sum_basin_r(m, x_pos, y_pos + 1); // Bottom.
        b_s += sum_basin_r(m, x_pos - 1, y_pos); // Left.
    }
    return b_s;
}

std::vector<ssize_t> find_all_low_points(std::vector<std::vector<precision>> const &m){
    std::vector<ssize_t> low_points_coordinates;
    precision n, up, down, left, right;
    for(ssize_t r = 0, row = m.size(); r < row; ++r){
        for(ssize_t c = 0, col = m[r].size(); c < col; ++c){
            n = m[r][c];
            if(n < 9){
                up = down = left = right = 10;           // Reset.
                if(c > 0){left = m[r][c - 1];}
                if(c + 1 < col){right = m[r][c + 1];}
                if(r > 0){up = m[r - 1][c];}
                if(r + 1 < row){down = m[r + 1][c];}

                if(n < up && n < down && n < left & n < right){
                    low_points_coordinates.push_back(c); // Hot spot. Low point.
                    low_points_coordinates.push_back(r); // Storing coordinates in couple.
                }
            }
        }
    }
    return low_points_coordinates;
}
//----------------------------------------------FUNCTIONS--------------------------------------------------
std::vector<std::vector<precision>> read_map_from_file(std::string input){
	std::vector<std::vector<precision>> m; // Map.
	std::ifstream ifs(input);
    if(ifs.good()){
        precision h;                       // Height.
        std::vector<precision> c;          // Caves.
        std::string line, cave;
        std::istringstream iss;

        for(;!ifs.eof();){
            ifs.clear();
            getline(ifs, line);
            iss.clear();
            iss.str(line);
            iss >> cave;
            for(;iss;){
                for(size_t i = 0, dim = cave.size(); i < dim; ++i){
                    h = (cave[i] - '0');   // Getting the number.
                    c.push_back(h);
                }
                m.push_back(c);            // Cave complete.
                c.clear();
            	iss >> cave;
			}
        }
    }
    ifs.clear();
    return m;
}

uint64_t mul_largest_basins(std::vector<std::vector<precision>> &m){
    uint64_t mul = 0;
    std::vector<ssize_t> l_p_c = find_all_low_points(m); // Low_points_coordinates.
    std::vector<uint64_t> l_b;                           // Large basins.
    set_map_size(m);
    for(size_t i = 0, dim = l_p_c.size(); i < dim; i += 2){
        mul = sum_basin_r(m, l_p_c[i], l_p_c[i + 1]);
        l_b.push_back(mul);
    }
    std::sort(l_b.begin(), l_b.end());
    size_t last_index = l_b.size() - 1;
    if(last_index > 2) mul = l_b[last_index] * l_b[last_index - 1] * l_b[last_index - 2];
    else mul = 0;
    return mul;
}
