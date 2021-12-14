#include "AC4_part1.h"
//---------------------------------ADVENT OF CODE 2021 - DAY 4 - PART I -----------------------------------
//------------------------------------------HELPER FUNCTIONS-----------------------------------------------
std::vector<std::vector<short int>> create_card(){
    std::vector<std::vector<short int>> matrix;
    matrix.resize(BINGO_SIZE);
    for(size_t i = 0; i < BINGO_SIZE; ++i){matrix[i].resize(BINGO_SIZE);}
    return matrix;
}

bool check_bingo(std::vector<std::vector<short int>> const &card){
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

bool mark_number(std::vector<std::vector<short int>> &card, short int n){
    for(size_t r = 0, c = 0; r < BINGO_SIZE; ++r){
        for(c = 0; c < BINGO_SIZE; ++c){
            if(card[r][c] == n) card[r][c] = -1; // Marks the number
            if(check_bingo(card)) return true;   // then it checks if we've won against the squid.
        }
    }
    return false;                                // Oooooooh :(
}

int sum_all_numbers(std::vector<std::vector<short int>> const &card){
    int sum = 0;
    for(size_t r = 0, c = 0; r < BINGO_SIZE; ++r){
        for(c = 0; c < BINGO_SIZE; ++c){
            if(card[r][c] != -1) sum += card[r][c];
        }
    }
    return sum;
}
//-------------------------------------------------FUNCTIONS-----------------------------------------------
std::vector<std::vector<std::vector<short int>>> read_cards_from_file(std::istream& str){
    std::vector<std::vector<std::vector<short int>>> cards;
    if(str.good()){
        std::string line;
        std::istringstream iss;                                     // Input stream to operate on string.
        std::vector<std::vector<short int>> card = create_card();

        for(;!str.eof();){
            for(int c = 0, r = 0; r < BINGO_SIZE; ++r){             // Column and row.
                getline(str, line);
                iss.clear();
                iss.str(line);
                for(c = 0; c < BINGO_SIZE; ++c){iss >> card[r][c];} // Inserting a single row.
            }
            str.clear();
            getline(str, line);                                     // Empty space between cards.
            if(line != ""){
                std::cerr << "Invalid input format!\n";
                cards.resize(0);
                return cards;
            }
            cards.push_back(card);
        }
    }
    str.clear();
    return cards;
}

std::vector<short int> read_numbers_from_file(std::istream& str){
    std::vector<short int> w_n; // Wild numbers.
    if(str.good()){
        short int n;
        std::string line;
        std::istringstream iss; // Input stream to operate on string.

        getline(str, line);     // In a single line.
        iss.clear();
        iss.str(line);
        iss >> n;               // Extracting the i-th number
        for(;iss;){
            w_n.push_back(n);   // and pushing it in the vector.
            iss >> n;
        }
    }
    str.clear();
    return w_n;
}

long long int play_bingo(std::vector<std::vector<std::vector<short int>>> &cards, std::vector<short int> const &numbers){
    long long int res = -1;
    for(size_t i = 0, rounds = numbers.size(); i < rounds; ++i){
        for(size_t j = 0, n_c = cards.size(); j < n_c; ++j){
            if(mark_number(cards[j], numbers[i])){       // Marks all cards with the i-th wild number.
                int card_sum = sum_all_numbers(cards[j]); // Cards[j] --> winner card.
                res = card_sum * numbers[i];
                return res;
            }
        }
    }
    return res;
}
