#include "curve.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    curve w;
    w.show();

    return a.exec();
}
