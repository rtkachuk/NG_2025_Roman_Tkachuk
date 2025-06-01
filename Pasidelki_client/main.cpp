#include "pasidelki.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Pasidelki w;
    w.show();
    return a.exec();
}
