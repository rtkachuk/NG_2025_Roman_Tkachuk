#include <iostream>
#include <string>

#include "exampleparent.h"
#include "publicchild.h"

using namespace std;

class item {
public:
    item(string name, int attack, int def, int max_durability);

    void showInfo();
    void damageItem(int damage);

    string getName() { return m_name; };
private:
    string m_name;
    int m_attack;
    int m_def;
    int m_durability;
    int m_max_durability;
};


item::item(string name, int attack, int def, int max_durability) {
    m_name = name;
    m_attack = attack;
    m_def = def;
    m_durability = max_durability;
    m_max_durability = max_durability;
}

void item::showInfo()
{
    cout << "Item: " << m_name << endl;
    cout << "-------------------------" << endl;
    cout << "Attack: " << m_attack << endl;
    cout << "Defence: " << m_def << endl;
    cout << "Status: " << (float(m_durability) / float(m_max_durability)) * 100 << "%" << endl;
}

void item::damageItem(int damage)
{
    damage = damage * -1;
    if (damage < 0) {
        m_durability = m_durability + damage;
    }
}

int main()
{
    // item sword("sword", 5, 1, 100);
    // sword.showInfo();
    // sword.damageItem(35);
    // sword.showInfo();

    // sword.getName();

    exampleParent testParent;
    cout << "TestParent Public member: " << testParent.m_publicMember << endl;
    //cout << "TestParent Private member: " << testParent.m_privateMember << endl;
    //cout << "TestParent Protected member: " << testParent.m_protectedMember << endl;

    publicChild testPublicChild;
    testPublicChild.hello();
    cout << endl;
    testPublicChild.testVariables();
    cout << endl;
    cout << testPublicChild.m_publicMember;

    return 0;
}

