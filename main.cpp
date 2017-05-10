#include "MainMediaViewer.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainMediaViewer w;
    w.show();

    return a.exec();
}
