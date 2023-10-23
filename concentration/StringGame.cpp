#include <iostream>
#include <string>
#include "CardT.h"
#include "Array2T.h"
#include "ArrayT.h"
#include "ConcentrationT.h"
#include "PlayerT.h"
#include "vector"

using namespace std;

void RowsCols(size_t & rows, size_t & cols);
void FillDeck(size_t rows, size_t cols, ArrayT<string> & deck);
void Players(size_t & players);
const vector<string> CARDS{"Bennett", "Meyer", "Tucker", "Molnar", "Hoggard", "Kilburn", "Puharic", "Quinn"};

int main() {

    srand(time(NULL));

    ArrayT<string> deck;

    size_t rows{},cols{},players{};
    RowsCols(rows,cols);
    FillDeck(rows,cols,deck);
    Players(players);

    ConcentrationT <string> game (rows, cols, players, deck);
    game.Play();

    return 0;
}


void RowsCols(size_t & rows, size_t & cols){
    cout << "Enter rows => ";
    cin >> rows;
    cout << endl;

    cout << "Enter cols => ";
    cin >> cols;
    cout << endl;

    int n = rows * cols;
    while (n % 2 != 0 or n > 8 ) {
        cout << "rows * cols must be even, and for stringGame smaller than 8, enter again" << endl;
        cout << "Enter rows => ";
        cin >> rows;
        cout << endl;

        cout << "Enter cols => ";
        cin >> cols;
        cout << endl;
        n = rows * cols;
    }
}

void FillDeck(size_t rows, size_t cols, ArrayT<string> & deck) {
    for (size_t i = 0; i < (rows*cols)/2; ++i) {
        deck.PushBack(CARDS[i]);
        deck.PushBack(CARDS[i]);
    }
}

void Players(size_t & players) {
    cout << "Enter players => ";
    cin >> players;
    cout << endl;
}
