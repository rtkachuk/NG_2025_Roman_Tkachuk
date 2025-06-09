#include "dbdemo.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    DbDemo w;
    w.show();
    return a.exec();
}
