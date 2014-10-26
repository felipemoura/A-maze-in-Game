#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "onmap.h"

#include <QtGui>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    onMap = new OnMap ();
    update();

    ui->setupUi(this);

    this->setWindowTitle(tr("A-Maze-in-Game"));
    this->setFixedSize(QSize(X_SIZE, Y_SIZE));
    this->installEventFilter(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent *event)
{    
    QPainter p(this);

    int i,j;
    int **aux = onMap->getMaze ();

    for (i = 0; i < MAZE_SIZE ; i++) {
        for (j = 0; j < MAZE_SIZE; j++) {
            if (aux[i][j] == 1) {
                p.fillRect ( TILE_SIZE*i, TILE_SIZE*j, TILE_SIZE,TILE_SIZE, QColor(0,0,0,255));
            } else {
                p.fillRect (TILE_SIZE*i, TILE_SIZE*j, TILE_SIZE, TILE_SIZE, QColor(255,255,255,255));
            }
        }
    }

    Player player = this->onMap->getPlayer1();
    p.fillRect (player.getX(), player.getY(), TILE_SIZE, TILE_SIZE, QColor(128,128,128,255));

    player = this->onMap->getPlayer2();
    p.fillRect (player.getX(), player.getY(), TILE_SIZE, TILE_SIZE, QColor(128,128,128,255));
}

// Filter of KeyEvent
bool MainWindow::eventFilter(QObject *object, QEvent *event)
{
    Player player;
    Position speed;

    if (event->type() == QEvent::KeyPress) {
        QKeyEvent *keyEvent = static_cast<QKeyEvent *>(event);


        // Player 2 Keys
        // Up
        if ( (keyEvent->key() == Qt::Key_W) || (keyEvent->key() == Qt::Key_Z) ) {
            player = this->onMap->getPlayer2();
            speed = player.getSpeed();

            if ((player.getY() - speed.getY()) > 0 ){
                this->onMap->collision (PLAYER2, player.getX(), (player.getY() - speed.getY()) );
            }

            
            //            if ((player.getY() - speed.getY()) > 0 ){
            //                player.setY(player.getY() - speed.getY());
            //            }
            //            this->onMap->setPlayer2(player);
        }

        // Left
        if( (keyEvent->key() == Qt::Key_A) || (keyEvent->key() == Qt::Key_Q) ) {
            player = this->onMap->getPlayer2();
            speed = player.getSpeed();

            if ((player.getX() - speed.getX()) > 0 ) {
                this->onMap->collision (PLAYER2, (player.getX() - speed.getX()), player.getY() );
            }

            //            if ((player.getX() - speed.getX()) > 0 ){
            //                player.setX(player.getX() - speed.getX());
            //            }
            //            this->onMap->setPlayer2(player);
        }

        // Down
        if(keyEvent->key() == Qt::Key_S) {
            player = this->onMap->getPlayer2();
            speed = player.getSpeed();

            if (player.getY() + speed.getY() < (BOUNDS)) {
                this->onMap->collision (PLAYER2, player.getX(), (player.getY() + speed.getY()) );
            }

            //            if (player.getY() + speed.getY() < (BOUNDS)) {
            //                player.setY(player.getY() + speed.getY());
            //            }
            //            this->onMap->setPlayer2(player);
        }

        // Right
        if(keyEvent->key() == Qt::Key_D) {
            player = this->onMap->getPlayer2();
            speed = player.getSpeed();

            if ((player.getX() + speed.getX()) < BOUNDS) {
                this->onMap->collision (PLAYER2, (player.getX() + speed.getX()), player.getY() );
            }

            //            if ((player.getX() + speed.getX()) < BOUNDS) {
            //                player.setX(player.getX() + speed.getX());
            //            }
            //            this->onMap->setPlayer2(player);
        }

        // Player 1 Keys
        // Up
        if(keyEvent->key() == Qt::Key_Up) {
            player = this->onMap->getPlayer1();
            speed = player.getSpeed();

            if ((player.getY() - speed.getY()) > 0 ){
                this->onMap->collision (PLAYER1, player.getX(), (player.getY() - speed.getY()) );
            }

            //            if ((player.getY() - speed.getY()) > 0 ){
            //                player.setY(player.getY() - speed.getY());
            //            }
            //            this->onMap->setPlayer1(player);
        }

        // Down
        if(keyEvent->key() == Qt::Key_Down) {
            player = this->onMap->getPlayer1();
            speed = player.getSpeed();

            if (player.getY() + speed.getY() < (BOUNDS)) {
                this->onMap->collision (PLAYER1, player.getX(), (player.getY() + speed.getY()) );
            }

            //            if ((player.getY() + speed.getY()) < BOUNDS ) {
            //                player.setY(player.getY() + speed.getY());
            //            }
            //            this->onMap->setPlayer1(player);
        }

        // Left
        if(keyEvent->key() == Qt::Key_Left) {
            player = this->onMap->getPlayer1();
            speed = player.getSpeed();

            if ((player.getX() - speed.getX()) > 0 ) {
                this->onMap->collision (PLAYER1, (player.getX() - speed.getX()), player.getY() );
            }

            //            if ((player.getX() - speed.getX()) > 0 ){
            //                player.setX(player.getX() - speed.getX());
            //            }
            //            this->onMap->setPlayer1(player);
        }

        // Right
        if(keyEvent->key() == Qt::Key_Right) {
            player = this->onMap->getPlayer1();
            speed = player.getSpeed();

            if ((player.getX() + speed.getX()) < BOUNDS) {
                this->onMap->collision (PLAYER1, (player.getX() + speed.getX()), player.getY() );
            }

            //            if ((player.getX() + speed.getX()) < BOUNDS) {
            //                player.setX(player.getX() + speed.getY());
            //            }
            //            this->onMap->setPlayer1(player);
        }

        update();

        return true;
    }

    return false;
}
