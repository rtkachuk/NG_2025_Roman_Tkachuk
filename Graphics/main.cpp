#include "showtime.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Showtime w;
    w.show();
    return a.exec();
}
