// Mattia Cacciatore - Computer Science student at the University of Genoa - Italy
#include "AoC10_part1.h"
//---------------------------------ADVENT OF CODE 2021 - DAY 10 - PART I ----------------------------------
//----------------------------------------------FUNCTIONS--------------------------------------------------
std::vector<std::vector<char>> read_navigation_from_file(std::string input){
	std::vector<std::vector<char>> n; // Navigation.
	std::ifstream ifs(input);
    if(ifs.good()){
        char chunk;
        std::vector<char> c_l;        // Chunks line.
        std::string line;
        std::istringstream iss;

        for(;!ifs.eof();){
            getline(ifs, line);
            iss.clear();
            iss.str(line);
            iss >> chunk;
            for(;iss;){
                c_l.push_back(chunk); // Complete line.
            	iss >> chunk;
			}
            n.push_back(c_l);
			c_l.clear();
        }
    }
    ifs.clear();
    return n;
}

std::vector<char> parse_navigation_subsystem(std::vector<std::vector<char>> const &c){
    std::stack<char> s;            // Stack.
    std::vector<char> v;
    for(size_t i = 0, dim = c.size(); i < dim; ++i){
        for(size_t j = 0, length = c[i].size(); j < length; ++j){
            if(c[i][j] == '(' || c[i][j] == '[' || c[i][j] == '{' || c[i][j] == '<')
                s.push(c[i][j]);
            else{
                if((c[i][j] == ')' && s.top() != '(') || (c[i][j] == ']' && s.top() != '[')
                   || (c[i][j] == '}' && s.top() != '{')  || (c[i][j] == '>' && s.top() != '<')){
                    v.push_back(c[i][j]);
                    break;         // Next line of chunks.
                }
                s.pop();
            }
        }
        for(;!s.empty();) s.pop(); // Reset the stack.
    }
    return v;
}

uint64_t calculate_syntax_error_score(std::vector<char> const &c){
    uint64_t total = 0;
    for(size_t i = 0, dim = c.size(); i < dim; ++i){
        if(c[i] == ')') total += 3; // Score.
        else if(c[i] == ']') total += 57;
        else if(c[i] == '}') total += 1197;
        else if(c[i] == '>') total += 25137;
    }
    return total;
}
