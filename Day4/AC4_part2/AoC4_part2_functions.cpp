// Mattia Cacciatore - Computer Science student at the University of Genoa - Italy
#include "AoC4_part2.h"
//---------------------------------ADVENT OF CODE 2021 - DAY 4 - PART II ----------------------------------
//-------------------------------------------HELPER FUNCTIONS----------------------------------------------
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
        if(c == BINGO_SIZE) return true;           // BINGO! (five numbers in a row).
    }

    for(size_t r = 0, c = 0; c < BINGO_SIZE; ++c){ // Column checking.
        for(r = 0; r < BINGO_SIZE; ++r){
            if(card[r][c] != -1) break;
        }
        if(r == BINGO_SIZE) return true;           // BINGO! (five numbers in a column).
    }
    return false;
}

bool mark_number(std::vector<std::vector<precision>> &card, precision n){
    for(size_t r = 0, c = 0; r < BINGO_SIZE; ++r){
        for(c = 0; c < BINGO_SIZE; ++c){
            if(card[r][c] == n) card[r][c] = -1; // Marks the number.
            if(check_bingo(card)) return true;
        }
    }
    return false;
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
        char garbage;           // See input.
        std::string line;
        std::istringstream iss;

        getline(ifs, line);     // In a single line.
        iss.clear();
        iss.str(line);
        iss >> n;               // Extracting the i-th number...
        for(;iss;){
	        iss >> garbage;     // ,
            w_n.push_back(n);   // ...and pushing it in the vector.
            iss >> n;
        }
    }
    ifs.clear();
    return w_n;
}

uint64_t lose_bingo(std::vector<std::vector<std::vector<precision>>> &cards, std::vector<precision> const &numbers){
    std::vector<std::vector<std::vector<precision>>> winning_cards;
    std::vector<precision> winning_numbers;
    for(size_t i = 0, prev = 0, rounds = numbers.size(); i < rounds; ++i){
        for(size_t j = 0, n_c = cards.size(); j < n_c; ++j){ // Number of cards.
            if(mark_number(cards[j], numbers[i])){           // Marks all cards with the i-th wild number.
                if(!cards[j].empty()){                       // A new winner card.
                    winning_cards.push_back(cards[j]);
                    winning_numbers.push_back(numbers[i]);
                    cards[j].clear();                        // Removes the j-th winner card.
                }
            }
        }
    }
    uint32_t sum = sum_all_numbers(winning_cards[winning_cards.size() - 1]);  // Last winning card is what we're looking for.
    precision last_number = winning_numbers[winning_numbers.size() - 1];      // Same here.
    uint64_t res = sum * last_number;
    return res;
}

