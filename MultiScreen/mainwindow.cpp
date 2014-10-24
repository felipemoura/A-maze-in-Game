#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "onmap.h"
#include <QThread>
#include <QString>

//http://qt-project.org/doc/qt-4.8/widgets-tetrix.html
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}
void MainWindow::timerEvent(QTimerEvent *event)
{
    newFrame();
    event->Drop;
}
void MainWindow::on_pushButton_clicked()
{
    //Welcome Screen
    ui->stackedWidget->setCurrentIndex(0);


}

void MainWindow::on_pushButton_2_clicked()
{
    //Menu
    ui->stackedWidget->setCurrentIndex(1);
}
void MainWindow::on_pushButton_3_clicked()
{
    //Game
    ui->stackedWidget->setCurrentIndex(3);
    current.player1->speedX=5;
    current.player1->speedY=0;
    timer.start(25, this);
    number=0;


}
void MainWindow::on_pushButton_4_clicked()
{
    //help
    ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::newFrame()
{

        current.Update();
        MainWindow::process_display();
        this->repaint(); //Display
        this->ui->player2->setText(QString::number(this->current.player2->speedY));
        this->ui->player1->setText(QString::number(this->current.player1->speedX));
        timer.start(25, this);


}
void MainWindow::process_display()
{
    //setGeometry ( int x, int y, int w, int h )
    ui->player1->setGeometry(QRect(current.player1->posX, current.player1->posY, 100, 10));
    ui->player2->setGeometry(QRect(current.player2->posX, current.player2->posY, 100, 10));

}


MainWindow::~MainWindow()
{
    delete ui;
}
