#include "fluxo.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Fluxo w;
    w.show();
    return a.exec();
}
