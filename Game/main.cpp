#include <iostream>

#include <random>
#include <time.h>
#include <conio.h>

#include <vector>

using namespace std;

const int worldsizeX = 100;
const int worldsizeY = 25;

struct item {
    string name;
};

struct character {
    int hp;
    int x;
    int y;
    vector<item> inventory;
};

void generateMap(char map[worldsizeY][worldsizeX], char playerMap[worldsizeY][worldsizeX]) {
    for (int row = 0; row < worldsizeY; row++) {
        for (int column = 0; column < worldsizeX; column++) {
            char symbol = ' ';
            int random = rand()%20;

            switch(random) {
                case 0: symbol = 't'; break;
                case 1: symbol = 's'; break;
                default: symbol = '.';
            }

            if (row == 0 ||
                column == 0 ||
                row == worldsizeY - 1 ||
                column == worldsizeX - 1) {

                symbol = '*';
            }

            map[row][column] = symbol;
            playerMap[row][column] = '*';
        }
    }
}

void showMap(char arr[worldsizeY][worldsizeX], character pl) {
    system("cls");
    for (int row = 0; row < worldsizeY; row++) {
        for (int column = 0; column < worldsizeX; column++) {
            if (pl.x == column && pl.y == row)
                cout << "@";
            else
                cout << arr[row][column];
        }
        cout << endl;
    }
}

bool isPlaceMovable(char arr[worldsizeY][worldsizeX], int x, int y) {
    return arr[y][x] == '.';
}

bool movePlayer(character* pl, char map[worldsizeY][worldsizeX], char action) {
    int currentPosX = pl->x;
    int currentPosY = pl->y;

    switch(action) {
        case 'w': currentPosY--; break;
        case 's': currentPosY++; break;
        case 'a': currentPosX--; break;
        case 'd': currentPosX++; break;
    }

    if (isPlaceMovable(map, currentPosX, currentPosY)) {
        pl->x = currentPosX;
        pl->y = currentPosY;
        return true;
    }

    return false;
}


// ***
// *@*
// ***

void progressPlayerMap(character *pl, char map[worldsizeY][worldsizeX], char playerMap[worldsizeY][worldsizeX]) {
    for (int row = -1; row < 2; row++) {
        for (int column = -1; column < 2; column++) {
            playerMap[pl->y + row][pl->x+column] = map[pl->y + row][pl->x + column];
        }
    }
}

void showInventory(character *pl) {
    system("cls");
    cout << "Inventory: " << endl;
    for (int current = 0; current < 20; current++)
        cout << "*";
    cout << endl;
    for (item bufferItem : pl->inventory) {
        cout << bufferItem.name << endl;
    }
}

int main()
{
    srand(time(0));

    char map[worldsizeY][worldsizeX];
    char playerMap[worldsizeY][worldsizeX];

    character player;
    player.x = worldsizeX / 2;
    player.y = worldsizeY / 2;

    item sword;
    sword.name = "Sword";

    player.inventory.push_back(sword);

    generateMap(map, playerMap);
    showMap(playerMap, player);

    while (true) {
        char action = getch();

        if (movePlayer(&player, map, action))
            progressPlayerMap(&player, map, playerMap);

        if (action == 'i') {
            showInventory(&player);
        }
        else
            showMap(playerMap, player);
    }

    return 0;
}
