#include "AC4_part2.h"
//---------------------------------ADVENT OF CODE 2021 - DAY 4 - PART II ----------------------------------
//-------------------------------------------HELPER FUNCTIONS----------------------------------------------
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

bool mark_number(std::vector<std::vector<short int>> &card, short int n){
    for(size_t r = 0, c = 0; r < BINGO_SIZE; ++r){
        for(c = 0; c < BINGO_SIZE; ++c){
            if(card[r][c] == n) card[r][c] = -1; // Marks the number then it checks if
            if(check_bingo(card)) return true;   // we got a winning card.
        }
    }
    return false;
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
            cards.push_back(card);                                  // Inserting the new card.
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

        getline(str, line);     // In a single line (see input).
        iss.clear();
        iss.str(line);
        iss >> n;               // Extracting the i-th number.
        for(;iss;){
            w_n.push_back(n);   // and pushing it into vector.
            iss >> n;
        }
    }
    str.clear();
    return w_n;
}

long long int lose_bingo(std::vector<std::vector<std::vector<short int>>> &cards, std::vector<short int> const &numbers){
    std::vector<std::vector<std::vector<short int>>> winning_cards;
    std::vector<short int> winning_numbers;
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
    int sum = sum_all_numbers(winning_cards[winning_cards.size() - 1]);  // Last winning card is what we're looking for.
    short int last_number = winning_numbers[winning_numbers.size() - 1]; // Same here.
    long long int res = sum * last_number;
    return res;
}
