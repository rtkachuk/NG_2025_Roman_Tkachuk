#include "publicchild.h"

void publicChild::testVariables()
{
    cout << "Public: " << m_publicMember << endl;
    //cout << "Private: " << m_privateMember << endl;
    cout << "Protected: " << m_protectedMember << endl;
    cout << "--------------------" << endl;
    setPrivateMember(2);
    cout << "Test access to Private member via getter: " << getPrivateMember() << endl;
}
