#include <iostream>
#include <string>
#include "CardT.h"
#include "Array2T.h"
#include "ArrayT.h"



using namespace std;

int main() {
    Array2T <string> a{3,2};

    cout << a.Rows() << endl;
    cout << a.Columns() << endl;


    string stuff{"o"};

    //fill with rand
    for (size_t i = 0; i < a.Rows(); i++) {
        for (size_t j = 0; j < a.Columns(); j++) {
            a[i,j] = stuff;
            cout << a[i,j] << endl;
            stuff += "o";
        }
    }

    cout << "printing array" << endl;
    for (size_t i = 0; i < a.Rows(); i++) {
        for (size_t j = 0; j < a.Columns(); j++) {
            cout << setw(10) << a[i,j];
        }
        cout << endl;
    }
    cout << endl;



    Array2T <string> b{3,2};
    b = a;
    cout << "printing array b " << endl;
    for (size_t i = 0; i < b.Rows(); i++) {
        for (size_t j = 0; j < b.Columns(); j++) {
            cout << setw(10) << a[i,j];
        }
        cout << endl;
    }

    Array2T <CardT<string>> t{3,2};
    string card {"O"};
    string printstr = "x";
    
    // CardT <int> c{};
    cout << "printing array cards " << endl;
    for (size_t i = 0; i < t.Rows(); i++) {
        for (size_t j = 0; j < t.Columns(); j++) {
            t[i,j].Data(card);
            if (!(t[i,j].Faceup())) {
                printstr = "x";
            } else {
                printstr = t[i,j].Data();
            }
            cout << setw(10) << printstr;
        }
        cout << endl;
    }

    t[0,0].Faceup(true);
    t[1,1].Faceup(true);

    cout << "printing array cards some up" << endl;
    for (size_t i = 0; i < t.Rows(); i++) {
        for (size_t j = 0; j < t.Columns(); j++) {
            t[i,j].Data(card);
            if (!(t[i,j].Faceup())) {
                printstr = "x";
            } else {
                printstr = t[i,j].Data();
            }
            cout << setw(10) << printstr;
        }
        cout << endl;
    }


    ArrayT<int> deck;
    //6 will be rows * cols
    for (size_t i = 0; i < 6; ++i) {
        deck.PushBack(i % 3);
    }

    Array2T <CardT<int>> g{3,2};

    cout << "printing array T cards " << endl;
    for (size_t i = 0; i < g.Rows(); i++) {
        for (size_t j = 0; j < g.Columns(); j++) {
            g[i,j].Data(deck[i+j]);
            if (!(g[i,j].Faceup())) {
                printstr = "x";
            } else {
                printstr = g[i,j].Data();
            }
            cout << setw(10) << printstr;
        }
        cout << endl;
    }


    g[0,0].Faceup(true);
    g[0,1].Faceup(true);
    g[1,0].Faceup(true);
    g[1,1].Faceup(true);
    g[2,0].Faceup(true);
    g[2,1].Faceup(true);

    int printint;

        cout << "printing array T cards " << endl;
                cout << "-";

            for (size_t i = 0; i < g.Columns(); ++i) {
                cout << setw(10) << i;
            }
            cout << endl;
    for (size_t i = 0; i < g.Rows(); i++) {
            cout  << i;

        for (size_t j = 0; j < g.Columns(); j++) {
            g[i,j].Data(deck[i+j]);
            if (!(g[i,j].Faceup())) {
                printstr = "x";
                cout << setw(10) << printstr;
            } else {
                printint = g[i,j].Data();
                cout << setw(10) << printint;
            }
        }
        cout << endl;
    }
    //makes deck with 6 cards, 0s 2s and 4s;

    


    return 0;
}
