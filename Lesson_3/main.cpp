#include <iostream>

using namespace std;

int main()
{
    char smthsus[10000];
    cout << "Enter your line: ";
    cin.getline(smthsus, 10000);
    cout << "Your input: " << smthsus << endl;

    int aCount = 0;
    int index = 0;

    while (smthsus[index] != 0) {
        if (smthsus[index] == 'a')
            aCount++;
        index++;
    }

    cout << "Your message contains " << aCount << " letters 'a'";

    return 0;
}
