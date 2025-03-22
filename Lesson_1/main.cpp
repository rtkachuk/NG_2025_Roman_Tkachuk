#include <iostream>

using namespace std;

int main()
{
    // int age = 0;
    // cout << "Enter your age: ";
    // cin >> age;

    // if (age > 5) {
    //     cout << "Bistro v shkolu";
    // } else {
    //     cout << "Rano v shkolu";
    // }

    // cout << ", no ti molodec";

    int amount = 0;
    cout << "Enter amount of stars: ";
    cin >> amount;


    // for (int counter = 0; amount > counter; counter++) {
    //     cout << amount << ":::" << counter << ":::" << "*" << endl;
    // }

    int counter = 0;
    while (amount > counter) {
        cout << amount << ":::" << counter << ":::" << "*" << endl;
        counter++;
    }

    cout << endl;

    return 0;
}
