#include <iostream>
#include <string>
#include "CardT.h"
#include "Array2T.h"
#include "ArrayT.h"
#include "ConcentrationT.h"
#include "PlayerT.h"

using namespace std;

void RowsCols(size_t & rows, size_t & cols);
void FillDeck(size_t rows, size_t cols, ArrayT<int> & deck);
void Players(size_t & players);

int main() {

    srand(time(NULL));

    ArrayT<int> deck;

    size_t rows{},cols{},players{};
    RowsCols(rows,cols);
    FillDeck(rows,cols,deck);
    Players(players);

    ConcentrationT <int> game (rows, cols, players, deck);
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
    while (n % 2 != 0) {
        cout << "rows * cols must be even, enter again" << endl;
        cout << "Enter rows => ";
        cin >> rows;
        cout << endl;

        cout << "Enter cols => ";
        cin >> cols;
        cout << endl;
        n = rows * cols;
    }
}

void FillDeck(size_t rows, size_t cols, ArrayT<int> & deck) {
    for (size_t i = 0; i < rows*cols; ++i) {
        deck.PushBack(i % ((rows*cols)/2));
    }
}

void Players(size_t & players) {
    cout << "Enter players => ";
    cin >> players;
    cout << endl;
}
