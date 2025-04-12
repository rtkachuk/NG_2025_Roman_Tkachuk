#include <iostream>

#include "functions.h"
#include "structures.h"

using namespace std;


int main()
{
    // Function for drawing Tree
    //drawTree(askSize());

    // Function for drawing Recursive Pyromid
    //drawSidePyromid(5);

    // Structures

    player steve;
    steve.hp = 100;
    steve.mana = 100;
    steve.protection = 6;
    steve.attack = 3;

    cout << "Select your name: ";
    cin.getline(steve.name, 10);

    makeDamage(&steve, 20);
    makeDamage(&steve, 20);
    showHp(steve);
    cout << endl;

    return 0;
}


//  *
// ***
//*****
