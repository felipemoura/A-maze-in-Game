#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QDebug deb = qDebug();

    int i,j;

    length=30;
    height=30;

    deb << "Start to generate a maze\n";

    for (i=0; i<length;i++) {
        for(j=0; j<height;j++) {
            maze[i][j]=1;
        }
    }

    MainWindow::workOnCell(1,1);

    for (i=0; i<length;i++) {
        for(j=0; j<height;j++) {

            deb << maze[i][j] ;
        }
        deb << "\n";
    }

    deb << "End of the generation of the maze";
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::workOnCell(int xCell,int yCell)
{
    QDebug deb = qDebug();
    deb << "Start to work with cell " << "X :" << xCell << " Y : " << yCell << "\n";

    this->maze[xCell][yCell]=0;

    int order[4];

    int storage;

    int xToLook;
    int yToLook;

    int a;
    int b;

    // this->maze[xCell][yCell]=0;

    /* We first generate a sequence telling when in which order we
       visit the neighbours (each neighbour is identified by an integer) */

    for (i=0;i<4;i++) {
        order[i]=i;
    }

    for (i=0;i<20;i++) {
        a = rand() % 4;
        b = rand() % 4;
        storage = order[a];
        order[a] = order[b];
        order[b] = storage;
    }

    deb << "Order : ";
    for (i=0;i<4;i++) {
        deb << order[i];
    }
    deb << "\n";

    //We have to check the 4 neighbours:
    for (i = 0 ; i < 4 ; i++) {
        switch(order[i]) {

        case 0:
            xToLook=xCell+2;
            yToLook=yCell;
            break;
        case 1:
            xToLook=xCell;
            yToLook=yCell+2;
            break;
        case 2:
            xToLook=xCell-2;
            yToLook=yCell;
            break;
        case 3:
            xToLook=xCell;
            yToLook=yCell-2;
            break;
        default:
            deb << "Problem in the order generation";
            break;
        }

        //Check if the cell to look is in the limits:
        if ( (xToLook>=0) && (xToLook<length) && (yToLook>=0) && (yToLook<height) ) {
            if (this->maze[xToLook][yToLook]==1) {
                
                //We have to watch this cell
                this->maze [(xToLook + xCell) /2] [(yToLook + xCell) /2 ] = 0;

                workOnCell(xToLook,yToLook);
            }
        }


    }
}
