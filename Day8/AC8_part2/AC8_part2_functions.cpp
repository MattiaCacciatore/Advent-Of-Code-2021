// Mattia Cacciatore - Computer Science student at the University of Genoa - Italy
#include "AoC8_part2.h"
//---------------------------------ADVENT OF CODE 2021 - DAY 8 - PART II ----------------------------------
//-------------------------------------------HELPER  FUNCTIONS---------------------------------------------
std::vector<char> decrypt_digit_wires(std::vector<std::string> const e){
	std::vector<char> n_d;                           // Number display.
	n_d.resize(7);                                   // Display segments.
	std::string zero = "", one = "", four = "", five = "", seven = "";
	char s_one1, s_one2, s_four1, s_four2;           // Segment_one and segment_four.
	/*   0
	 *  5 1
	 *   6     Display format.
	 *  4 2
	 *   3
	 * Decryption phase consist in the search of five numbers: 1 then 7 then 4 then 0 then 5.
	 * Because 1 is the only digit with 2 segments (the most right), 7 has 3 segments but only
	 * one is different from 1, the upper segment (it can be found the subtraction of 1 segments).
	 * Then it's necessary to find the number 4 in order to know the middle and the top left
	 * segment (by the subtraction of 1 segments). Then the number 0 is essential in order to find
	 * the middle segment (it can be found looking for a string with length of six contains only
	 * one of two unique segments of 4, try to draw a picture if you're not convinced). At this point
	 * there're three segments (upper, middle and top left found by deduction deleting one of the two
	 * possible char for that segment, the other goes in the middle). At last 5 is required to find
	 * the bottom right and the lowest segment, and then the last two by deduction), it can be found
	 * looking for a string with length of five contains the 4 unique segments, the middle and the top left. */
        // Unique and easy numbers. One, four and seven. Digits are always ten.
	for(size_t i = 0; i < 10; ++i){
	    if(e[i].length() == 2) one = e[i];
	    else if(e[i].length() == 3) seven = e[i];
	    else if(e[i].length() == 4) four = e[i];
	}
	s_one1 = one[0];
	s_one2 = one[1];
        // Find upper segment in 7.
	for(size_t i = 0, j; i < seven.size(); ++i){
	    n_d[0] = seven[i];
	    for(j = 0; j < one.size(); ++j){
		if(n_d[0] == one[j]) break;
	    }
	    if(j == one.size()) break;                    // Upper segment found!
	}
        // Find the two unique segment in 4.
	for(size_t i = 0, j = 0; i < four.size(); ++i){
	    if(four[i] != s_one1 && four[i] != s_one2){
		if(j == 0){
		    s_four1 = four[i];                    // First segment.
		    ++j;
		}
		else{
		    s_four2 = four[i];                    // Second segment.
		    break;
		}
	    }
	}
        // Find 0.
	for(size_t i = 0, j, k; i < e.size(); ++i){
	    if(e[i].length() == 6){                       // It can be 0, 6 or 9.
		for(j = k = 0; j < e[i].length(); ++j){
		    if(e[i][j] == s_four1 || e[i][j] == s_four2) ++k;
		}
		if(k < 2) zero = e[i];                    // Found it!
	    }
	}
        // Find middle and top left segment by deduction.
	for(size_t i = 0; i < zero.size(); ++i){
	    if(zero[i] == s_four1) n_d[5] = s_four1;      // Top left segment found!
	    else if(zero[i] == s_four2) n_d[5] = s_four2;
	}
	n_d[6] = (n_d[5] == s_four1 ? s_four2 : s_four1); // Middle segment found!
        // Find 5.
	for(size_t i = 0; i < e.size(); ++i){
            if(e[i].length() == 5){                       // It can be 2, 3 or 5.
	        for(size_t j = 0; j < e[i].length(); ++j){
		    if(e[i][j] == n_d[5]) five = e[i];    // Found it!
	        }
	    }
	}

	for(size_t i = 0; i < five.size(); ++i){
	    if(five[i] != n_d[0] && five[i] != n_d[5] && five[i] != n_d[6] && five[i] != s_one1 && five[i] != s_one2)
		n_d[3] = five[i];                         // Found it! The lowest segment found!
	}

	for(size_t i = 0; i < five.size(); ++i){
	    if(five[i] != n_d[0] && five[i] != n_d[3] && five[i] != n_d[5] && five[i] != n_d[6])
		n_d[2] = five[i];                         // Found it! The Bottom right segment found!
	}

	for(size_t i = 0; i < one.size(); ++i){
	    if(one[i] != n_d[2])
		n_d[1] = one[i];                          // Found it by the subtraction! The top right segment found!
	}

	for(size_t i = 0; i < zero.size(); ++i){
	    if(zero[i] != n_d[0] && zero[i] != n_d[1] && zero[i] != n_d[2] && zero[i] != n_d[3] && zero[i] != n_d[5] && zero[i] != n_d[6])
		n_d[4] = zero[i];                         // Found it by the subtraction! The bottom left and last segment found!!!
	}
	return n_d;
}

int32_t decrypt_digit_display(std::vector<std::string> const& e_d, std::vector<char> const& d_d){
    std::string d = "";
    int32_t n;                                      // It's big enough.
    for(size_t i = 10; i < 14; ++i){                // 10 digits, 4 digits on display.
        if(e_d[i].size() == 2) d += "1";             // Trivial cases.
        else if(e_d[i].size() == 3) d += "7";
        else if(e_d[i].size() == 4) d += "4";
        else if(e_d[i].size() == 5){                 // It can be 2, 3 or 5.
            if(e_d[i].find(d_d[4]) != std::string::npos) d += "2";
            else if(e_d[i].find(d_d[5]) != std::string::npos) d += "5";
            else d += "3";
        }
        else if(e_d[i].size() == 6){                 // It can be 0, 6 or 9.
            if(e_d[i].find(d_d[1]) == std::string::npos) d += "6";
            else if(e_d[i].find(d_d[4]) == std::string::npos) d += "9";
            else d += "0";
        }
        else d += "8";
    }
    n = std::stoi(d);
    return n;
}
//----------------------------------------------FUNCTIONS--------------------------------------------------
void print_digit(std::vector<char> const d){
    if(d.size() > 6){
        std::cout << "\n\n\n";
        std::cout << " " << d[0] << d[0] << d[0] << d[0] << " \n";
        std::cout << d[5] << "    " << d[1] << "\n";
        std::cout << d[5] << "    " << d[1] << "\n";
        std::cout << " " << d[6] << d[6] << d[6] << d[6] << " \n";
        std::cout << d[4] << "    " << d[2] << "\n";
        std::cout << d[4] << "    " << d[2] << "\n";
        std::cout << " " << d[3] << d[3] << d[3] << d[3] << " \n";
    }
}

std::vector<std::vector<std::string>> read_digit_from_file(std::string input){
    std::vector<std::vector<std::string>> e_d;       // Encrypt digits.
    std::ifstream ifs(input);
    if(ifs.good()){
        std::string line, digit;
        std::istringstream iss;
        std::vector<std::string> s_d;                // Single display.

        for(;!ifs.eof();){
            ifs.clear();
            getline(ifs, line);
            iss.clear();
            iss.str(line);
            iss >> digit;
            for(size_t j = 0; iss && j < DIG_SIZE; ++j){
            	if(digit == "|") --j;               // Garbage, see input.
            	else s_d.push_back(digit);          // Storing 10 unique digit and
            	iss >> digit;                       // 4 digit display.
	     } // E.g. (decrypted) s_d = {5, 3, 1, 0, 8, 7, 2, 4, 6, 9, | 5, 4, 3, 2}
	     e_d.push_back(s_d);
	     s_d.clear();
        }
    }
    ifs.clear();
    return e_d;
}

uint64_t sum_all_digits(std::vector<std::vector<std::string>> const& e_d){
    uint64_t sum = 0;
    int32_t n = 0;
    std::vector<char> d_e;  // Digit_encoding.
    for(size_t i = 0, dim = e_d.size(); i < dim; ++i){
        d_e = decrypt_digit_wires(e_d[i]);
        n = decrypt_digit_display(e_d[i], d_e);
        sum += n;
    }
    return sum;
}
