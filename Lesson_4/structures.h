#pragma once
#include <iostream>

using namespace std;

struct player {
    char name[10];
    int hp;
    int mana;
    int protection;
    int attack;
};

void makeDamage(player *pl, int damage) {
    int hitPoints = (damage - pl->protection);
    pl->hp = pl->hp - hitPoints;
    cout << "Player " << pl->name << " has been damaged " << hitPoints << endl;
}

void showHp(player pl) {
    cout << pl.name << " has " << pl.hp << " HP left" << endl;
}
