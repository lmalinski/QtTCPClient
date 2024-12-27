#include "clientmw.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ClientMW w;
    w.show();
    return a.exec();
}
