#pragma once
#include <iostream>
using namespace std;

//
// Drawing Tree
//

void drawLine(int size, char symbol) {
    // for (int index = 0; index < size; index++) {
    //     cout << symbol;
    // }

    // Recursion

    if (size > 0) {
        drawLine(size -1, symbol);
        cout << symbol;
    }
}

int askSize() {
    int size = 0;
    cout << "Enter size: ";
    cin >> size;
    return size;
}

void drawPyromid(int size) {
    for (int row = 1; row < size + 1; row++) {
        drawLine(size - row, ' ');
        drawLine(row * 2 - 1, '*');
        cout << endl;
    }
}

void drawStump(int size) {
    drawLine(size - 1, ' ');
    cout << "*";
}

void drawTree(int size) {
    drawPyromid(size);
    drawStump(size);
    cout << endl;
}

//
// Recursion
//

void drawSidePyromid(int size) {
    if (size > 0) {
        drawLine(size, '*');
        cout << endl;
        drawSidePyromid(size-1);
        drawLine(size, '*');
        cout << endl;
    }
}
