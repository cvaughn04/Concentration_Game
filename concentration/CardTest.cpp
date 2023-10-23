#include <iostream>
#include <string>
#include "CardT.h"
#include "AbilityT.h"


using namespace std;

int main() {

    CardT <int> c {};

    c.Data(5);
    cout << c.Data() << endl;

    c.Faceup(true);
    cout << c.Faceup() << endl;


    CardT <string> c2 {};

    c2.Data("bollocks");
    cout << c2.Data() << endl;

    c2.Faceup(true);
    cout << c2.Faceup() << endl;
    c2.Faceup(false);
    cout << c2.Faceup() << endl;



    return 0;
}