#include "mainwindow.h"
#include <QApplication>
#include <QDebug>
#include "onmap.h"

int main(int argc, char *argv[])
{
    OnMap* maze = new OnMap ();

    QDebug q = qDebug();

    int **aux = maze->getMaze ();

    for (int i = 0 ; i < 30 ; i++) {
        for (int j = 0 ; j < 30 ; j++) {
            q << aux[i][j];
        }
        q << endl;
    }



    QApplication a(argc, argv);
    MainWindow w;
    w.show();



    return a.exec();
}
