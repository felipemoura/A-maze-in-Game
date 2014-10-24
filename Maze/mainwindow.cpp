#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QString>
#include <string>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    int i,j;
    length=30;
    height=30;
    qDebug( "Start to generate a maze" );
    for (i=0; i<length;i++)
    {
        for(j=0; j<height;j++)
        {
            maze[i][j]=1;
        }
    }

    MainWindow::workOnCell(1,1);
     QString s = "value";
    for (i=0; i<length;i++)
    {
        s="";
        for(j=0; j<height;j++)
        {

           s+=QString::number(maze[i][j]);



        }
         qDebug(s.toLatin1());

    }
    qDebug( "End of the generation of the maze" );

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::workOnCell(int xCell,int yCell)
{
int i,j;
//qDebug("Start to work with cell %d %d \n",xCell,yCell);
    maze[xCell][yCell]=0;
            int order[4];
            int storage;
            int xToLook;
            int yToLook;
            int a;
            int b;

            this->maze[xCell][yCell]=0;

           //We first generate a sequence telling when in which order we visit the neighbours (each neighbour is identified by an integer)

           for (i=0;i<4;i++)
            {
                order[i]=i;
            }
           for (i=0;i<20;i++)
            {
                a=rand() % 4;
                b=rand() % 4;
                storage=order[a];
                order[a]=order[b];
                order[b]=storage;
            }
            for (i=0;i<4;i++)
            {

                //qDebug("%d",order[i]);
            }
            //qDebug("\n");

            //We have to check the 4 neighbours:
            for (i=0;i<4;i++)
            {

                switch(order[i])
                {

                case 0:
                    xToLook=xCell+2;
                    yToLook=yCell  ;
                    break;
                case 1:
                    xToLook=xCell;
                    yToLook=yCell+2;
                    break;
                case 2:
                    xToLook=xCell-2;
                    yToLook=yCell  ;
                    break;
                case 3:
                    xToLook=xCell;
                    yToLook=yCell-2;
                    break;
                default:
                    qDebug( "Problem in the order generation" );
                    break;
                }
                qDebug("%d from %d %d",i,xCell,yCell);
                //Check if the cell to look is in the limits:
                if ((xToLook>=0)&&(xToLook<length-1)&&(yToLook>=0)&&(yToLook<height-1))
                {
                    if (this->maze[xToLook][yToLook]==1)
                    {
                        //We have to watch this cell
                        this->maze[(xToLook+xCell)/2][(yToLook+yCell)/2]=0;
                        workOnCell(xToLook,yToLook);
                        qDebug("Fin de %d %d, i= %d",xToLook,yToLook,i);
                    }
                }

            }


}
