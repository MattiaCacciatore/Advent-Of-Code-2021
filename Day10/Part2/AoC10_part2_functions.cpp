// Mattia Cacciatore - Computer Science student at the University of Genoa - Italy
#include "AoC10_part2.h"
//---------------------------------ADVENT OF CODE 2021 - DAY 10 - PART II ---------------------------------
//------------------------------------------HELPER FUNCTIONS-----------------------------------------------
uint64_t calculate_score(std::string const &s){
    uint64_t t = 0;
    for(size_t i = 0, dim = s.size(); i < dim; ++i){
        t *= 5;
        if(s[i] == ')')      t += 1;
        else if(s[i] == ']') t += 2;
        else if(s[i] == '}') t += 3;
        else                 t += 4;
    }
    return t;
}
//----------------------------------------------FUNCTIONS--------------------------------------------------
std::vector<std::string> read_navigation_from_file(std::string input){
    std::vector<std::string> n_s; // Navigation subsystem.
    std::ifstream ifs(input);
    if(ifs.good()){
        std::string line;
        for(;!ifs.eof();){
            getline(ifs, line);
            n_s.push_back(line); // Complete line. Yep, it was kind of stupid idea
        }                        // to use vector<char> instead string in the previous
    }                            // challenge.
    ifs.clear();
    return n_s;
}

std::vector<std::string> parse_navigation_subsystem(std::vector<std::string> &c){
    std::vector<std::string> m_c; // Missing chars.
    std::string str;
    std::stack<char> s;           // Stack.
    char close;
    for(size_t i = 0, dim = c.size(); i < dim; ++i){
        for(size_t j = 0, length = c[i].size(); j < length; ++j){
            if(c[i][j] == '(' || c[i][j] == '[' || c[i][j] == '{' || c[i][j] == '<')
                s.push(c[i][j]);
            else{
                if((c[i][j] == ')' && s.top() != '(') || (c[i][j] == ']' && s.top() != '[')
                   || (c[i][j] == '}' && s.top() != '{')  || (c[i][j] == '>' && s.top() != '<')){
                    c[i].clear();
                    break;
                }
                s.pop();
            }
        }

        if(c[i].size() > 0){       // A not cleared line (uncompleted).
            for(size_t j = 0, s_length = s.size(); j < s_length; ++j){
                close = s.top();   // Stack pop up, First In Last Out.
                if(close == '(')      str += ")";
                else if(close == '[') str += "]";
                else if(close == '{') str += "}";
                else                  str += ">";
                s.pop();
            }
            m_c.push_back(str);
            str.clear();
        }
        else{                      // Corrupted line, need to clear the stack.
            for(size_t j = 0, s_length = s.size(); j < s_length; ++j) s.pop(); // Clear the stack.
        }

    }
    return m_c;
}

uint64_t calculate_middle_score(std::vector<std::string> const &c_l){
    uint64_t t = 0;
    std::vector<uint64_t> totals;
    for(size_t i = 0, dim = c_l.size(); i < dim; ++i){
        t = calculate_score(c_l[i]);
        totals.push_back(t);
    }
    std::sort(totals.begin(), totals.end());
    t = totals[totals.size() / 2];
    return t;
}
