#ifndef CONCENTRATIONT
#define CONCENTRATIONT

#include "ArrayT.h"
#include "Array2T.h"
#include "CardT.h"
#include "PlayerT.h"
#include "AbilityT.h"
#include <iostream>

const int SET_WIDTH{10};

template<typename T>
class ConcentrationT {
    public:

        ConcentrationT(size_t r, size_t c, size_t p, ArrayT<T> d);
        void Play();

        void ShuffleDeck();
        void Report(ArrayT<PlayerT> players);
        void PrintBoard();
        void FillBoard();
        bool ValidateCard(size_t r, size_t c);
        bool Match(size_t r, size_t c, size_t r2, size_t c2);
        bool CheckWin();
        
        

    private:
        size_t  rows{0},
                columns{0},
                capacity{0};

        size_t plyrs{0};
        ArrayT<T> deck{0};
        Array2T<CardT<T>> board{};
};

template<typename T>
ConcentrationT<T>::ConcentrationT(size_t r, size_t c, size_t p, ArrayT<T> d) {
    rows = r;
    columns = c;
    capacity = rows * columns;
    plyrs = p;
    deck = d;  

    Array2T<CardT<T>> tmp{rows,columns};
    board = tmp;
      
}

template<typename T>
void ConcentrationT<T>::FillBoard() {
    
    for (size_t i = 0; i < rows; ++i) {
        for (size_t j = 0; j < columns; ++j) {
            board[i,j].Data(deck[(i*columns) + j]);
        }
    }

}

template<typename T>
void ConcentrationT<T>::PrintBoard() {
    std::cout << "-";
    for (size_t i = 0; i < board.Columns(); ++i) {
        std::cout << std::setw(SET_WIDTH) << i;
    }
    std::cout << std::endl;
    
    for (size_t i = 0; i < board.Rows(); i++) {
        std::cout << i;

        for (size_t j = 0; j < board.Columns(); j++) {
            if (board[i,j].Faceup()) {
                std::cout << std::setw(SET_WIDTH) << board[i,j].Data();
            } else {
                std::cout << std::setw(SET_WIDTH) << "x";
            }
        }
        std::cout << std::endl;
    }
}

template<typename T>
void ConcentrationT<T>::Play() {
    ArrayT<PlayerT> players {};
    for (size_t i = 0; i < plyrs; ++i) {
        PlayerT tmp;
        players.PushBack(tmp);
    }

    size_t lastPlayerIdx = plyrs - 1;

    bool won {false};
    bool wrong {false};
    bool rerun {false};
    size_t r, c, r2, c2;

    ShuffleDeck();
    FillBoard();

    for (size_t i = 0; (i < players.Size() and !won) or (plyrs == 1 and !won); ++i) {
        // for (int k = 0; k < 30; ++k) {
        //     std::cout << std::endl;
        // }
        if (rerun) {
            i -= 1;
        }
        rerun = false;

        PrintBoard();

        std::cout << std::endl << "Player " << i + 1 << "'s turn" << std::endl;
        wrong = false;

        while (!wrong) {

            std::cout << "Enter position of first card seperated by a comma => ";
            std::cin >> r;
            std::cin.ignore(1,',');
            std::cin >> c;
            std::cout << std::endl;

            while (!(ValidateCard(r,c))) {
                std::cout << "Enter position of first card seperated by a comma => ";
                std::cin >> r;
                std::cin.ignore(1,',');
                std::cin >> c;
                std::cout << std::endl;
            }

            board[r,c].Faceup(true);
            PrintBoard();

            std::cout << "Enter position of second card seperated by a comma => ";
            std::cin >> r2;
            std::cin.ignore(1,',');
            std::cin >> c2;
            std::cout << std::endl;

            while (!(ValidateCard(r2,c2))) {
                std::cout << "Enter position of second card seperated by a comma => ";
                std::cin >> r2;
                std::cin.ignore(1,',');
                std::cin >> c2;
                std::cout << std::endl;
            }

            board[r2,c2].Faceup(true);
            PrintBoard();

            if (!(Match(r,c,r2,c2))) {
                wrong = true;

            } else {
                players[i].Score(players[i].Score() + 1);
                std::cout << "Player " << i + 1 << "'s score icreased to " << players[i].Score() << "." << std::endl;
                if (CheckWin()) {
                    won = true;
                    wrong = true;
                }
            }
        }

        if (i == lastPlayerIdx and !won) {
            i = 0;
            rerun = true;
        }
        
    }

    Report(players);

}

template<typename T>
bool ConcentrationT<T>::ValidateCard(size_t r, size_t c) {
    bool valid {true};

    if (board[r,c].Faceup()) {
        std::cout << "Card is already face up, Enter valid card." << std::endl;
        valid = false;
    } else if ((r >= rows) or  (c >= columns)) {
        std::cout << "Index out of bounds, Enter a valid card" << std::endl;
        valid = false;
    }

    return valid;
}

template<typename T>
bool ConcentrationT<T>::Match(size_t r, size_t c, size_t r2, size_t c2) {
    bool match {true};

    if (board[r,c].Data() == board[r2,c2].Data()) {
        std::cout << "The cards match, you get a point." << std::endl;
    } else {
        std::cout << "The cards dont match." << std::endl;
        board[r,c].Faceup(false);
        board[r2,c2].Faceup(false);
        match = false;

    }

    return match;
}


template<typename T>
bool ConcentrationT<T>::CheckWin() {
    bool won {true};

    for (size_t i = 0; i < rows; ++i) {
        for (size_t j = 0; j < columns; ++j) {
            if (not (board[i,j].Faceup())) {
                won = false;
            }
        }
    }

    return won;
}

template<typename T>
void ConcentrationT<T>::Report(ArrayT<PlayerT> players) {
    int currentWinnerIdx {0};

    std::cout << std::endl << "Game Finished Reporting Scores:" << std::endl;
    for (size_t i = 0; i < plyrs; ++i) {
        std::cout << "Player " << i + 1 << "'s Score: " << players[i].Score() << std::endl;

        if (i != 0) {
            if (players[i].Score() > players[i-1].Score()) {
                currentWinnerIdx = i;
            }
        }
    }

    std::cout << std::endl << "Player " << currentWinnerIdx + 1 << " wins!" << std::endl;
    

}

template<typename T>
void ConcentrationT<T>::ShuffleDeck() {
    for(size_t i = 0; i < deck.Size(); ++i) {
       size_t j = rand() % deck.Size();
       auto tmp = deck[i];
       deck[i] = deck[j];
       deck[j] = tmp;
    }
}

#endif