// Mattia Cacciatore - Computer Science student at the University of Genoa - Italy
#include "AoC4_part1.h"
//---------------------------------ADVENT OF CODE 2021 - DAY 4 - PART I -----------------------------------
//------------------------------------------HELPER FUNCTIONS-----------------------------------------------
std::vector<std::vector<precision>> create_card(){
    std::vector<std::vector<precision>> matrix;
    matrix.resize(BINGO_SIZE);
    for(size_t i = 0; i < BINGO_SIZE; ++i){matrix[i].resize(BINGO_SIZE);}
    return matrix;
}

bool check_bingo(std::vector<std::vector<precision>> const &card){
    for(size_t r = 0, c = 0; r < BINGO_SIZE; ++r){ // Row checking.
        for(c = 0; c < BINGO_SIZE; ++c){
            if(card[r][c] != -1) break;
        }
        if(c == BINGO_SIZE) return true;           // BINGO! (five numbers in a row). Take that squid!
    }

    for(size_t r = 0, c = 0; c < BINGO_SIZE; ++c){ // Column checking.
        for(r = 0; r < BINGO_SIZE; ++r){
            if(card[r][c] != -1) break;
        }
        if(r == BINGO_SIZE) return true;           // BINGO! (five numbers in a column). Take that squid!
    }
    return false;                                  // Ooooooh :(
}

bool mark_number(std::vector<std::vector<precision>> &card, precision n){
    for(size_t r = 0, c = 0; r < BINGO_SIZE; ++r){
        for(c = 0; c < BINGO_SIZE; ++c){
            if(card[r][c] == n) card[r][c] = -1; // Marks the number.
            if(check_bingo(card)) return true;   // then it checks if we've won against the squid.
        }
    }
    return false;                                // Oooooooh :(
}

uint32_t sum_all_numbers(std::vector<std::vector<precision>> const &card){
    uint32_t sum = 0;
    for(size_t r = 0, c = 0; r < BINGO_SIZE; ++r){
        for(c = 0; c < BINGO_SIZE; ++c){
            if(card[r][c] > 0) sum += card[r][c];
        }
    }
    return sum;
}
//-------------------------------------------------FUNCTIONS-----------------------------------------------
std::vector<std::vector<std::vector<precision>>> read_cards_from_file(std::string input){
    std::vector<std::vector<std::vector<precision>>> cards;
    std::ifstream ifs(input);
    if(ifs.good()){
        std::string line;
        std::istringstream iss;                                     // Input stream to operate on string.
        std::vector<std::vector<precision>> card = create_card();

        for(;!ifs.eof();){
            for(uint32_t c = 0, r = 0; r < BINGO_SIZE; ++r){        // Column and row.
                getline(ifs, line);
                iss.clear();
                iss.str(line);
                for(c = 0; c < BINGO_SIZE; ++c){iss >> card[r][c];} // Inserting a single row.
            }
            getline(ifs, line);                                     // Empty space between cards.
            cards.push_back(card);
        }
    }
    ifs.clear();
    return cards;
}

std::vector<precision> read_numbers_from_file(std::string input){
    std::vector<precision> w_n; // Wild numbers.
    std::ifstream ifs(input);
    if(ifs.good()){
        precision n;
        std::string line;
        std::istringstream iss; // Input stream to operate on string.

        getline(ifs, line);     // In a single line.
        iss.clear();
        iss.str(line);
        iss >> n;               // Extracting the i-th number
        for(;iss;){
            w_n.push_back(n);   // and pushing it in the vector.
            iss >> n;
        }
    }
    ifs.clear();
    return w_n;
}

uint64_t play_bingo(std::vector<std::vector<std::vector<precision>>> &cards, std::vector<precision> const &numbers){
    uint64_t res = -1;
    for(size_t i = 0, rounds = numbers.size(); i < rounds; ++i){
        for(size_t j = 0, n_c = cards.size(); j < n_c; ++j){
            if(mark_number(cards[j], numbers[i])){             // Marks all cards with the i-th wild number.
                uint32_t card_sum = sum_all_numbers(cards[j]); // Cards[j] --> winner card.
                res = card_sum * numbers[i];
                return res;
            }
        }
    }
    return res;
}
