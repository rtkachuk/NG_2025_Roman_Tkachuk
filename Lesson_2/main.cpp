#include <iostream>

using namespace std;

int main()
{
    // int amount = 0;
    // cout << "Enter amount: ";
    // cin >> amount;

    // int row = 0;
    // int column = 0;
    // while (row < amount) {
    //     while (column < amount) {
    //         if (row != column)
    //             cout << "*";
    //         else
    //             cout << " ";
    //         column++;
    //     }
    //     cout << endl;
    //     column = 0;
    //     row++;
    // }

    // ========================================

    // int values[10];
    // for (int index = 0; index < 10; index++) {
    //     cout << "Enter " << index + 1 << " value: ";
    //     cin >> values[index]; // 0 .. 9
    // }

    // for (int index = 0; index < 10; index++) {
    //     cout << "Doubled " << index + 1 << " value: " << values[index] * 2 << endl;
    // }

    // ========================================

    int matrix[5][5];
    for (int row = 0; row < 5; row++) {
        for (int column = 0; column < 5; column++) {
            matrix[row][column] = column + row;
        }
    }

    for (int row = 0; row < 5; row++) {
        cout << "[" << row << "]: ";
        for (int column = 0; column < 5; column++) {
            cout << matrix[row][column] << " ";
        }
        cout << endl;
    }

    // ========================================

    // int matrix[10][10];

    // for (int row = 0; row < 10; row++) {
    //     for (int column = 0; column < 10; column++) {
    //         if (row - column > 0)
    //             matrix[row][column] = row - column;
    //         else
    //             matrix[row][column] = column - row;
    //     }
    // }

    // for (int row = 0; row < 10; row++) {
    //     for (int column = 0; column < 10; column++) {
    //         cout << matrix[row][column] << " ";
    //     }
    //     cout << endl;
    // }

    return 0;
}
