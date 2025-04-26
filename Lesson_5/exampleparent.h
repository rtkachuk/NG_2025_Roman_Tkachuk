#ifndef EXAMPLEPARENT_H
#define EXAMPLEPARENT_H

#include <iostream>

using namespace std;

class exampleParent
{
public:
    exampleParent();
    void hello() { cout << "Hello world!"; }

    void setPrivateMember(int value) { m_privateMember = value; }
    int getPrivateMember() { return m_privateMember; }

    int m_publicMember;
private:
    int m_privateMember;
protected:
    int m_protectedMember;
};

#endif // EXAMPLEPARENT_H
