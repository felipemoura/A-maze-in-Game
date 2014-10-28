#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "onmap.h"

#include <QtGui>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    onMap = new OnMap ();

    ui->setupUi(this);

    this->setFinished(false);
    this->setWinner(ZERO);
    this->setWindowTitle(tr("A-Maze-in-Game"));
    this->setFixedSize(QSize(X_SIZE, Y_SIZE));
    this->installEventFilter(this);

    update();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent *event)
{
    QPainter p(this);
    int i,j;
<<<<<<< HEAD
    int **aux = NULL;
    static int winnerX = 27;
    static int winnerY = 27;

    if (!(this->getFinished())) {

        aux = onMap->getMaze ();

        for (i = 0; i < MAZE_SIZE ; i++) {
            for (j = 0; j < MAZE_SIZE; j++) {

                switch (aux[i][j]) {
                case 1: //Wall
                    p.fillRect ( TILE_SIZE*i, TILE_SIZE*j, TILE_SIZE,TILE_SIZE, QColor(0,0,0,255));
                    break;
                case 0://Nothing
                    p.fillRect (TILE_SIZE*i, TILE_SIZE*j, TILE_SIZE, TILE_SIZE, QColor(255,255,255,255));
                    break;
                case 2://Bonus Slow
                    p.fillRect (TILE_SIZE*i, TILE_SIZE*j, TILE_SIZE, TILE_SIZE, QColor(128,0,128,255));
                    break;
                case 3://Bonus Fast
                    p.fillRect (TILE_SIZE*i, TILE_SIZE*j, TILE_SIZE, TILE_SIZE, QColor(0,255,0,255));
                    break;
                default:
                    qDebug("This should not be in the maze");
                }
=======
    int **aux = onMap->getMaze ();

    for (i = 0; i < MAZE_SIZE ; i++) {
        for (j = 0; j < MAZE_SIZE; j++) {
            switch (aux[i][j])
            {
            case 1: //Wall
                p.fillRect ( TILE_SIZE*i, TILE_SIZE*j, TILE_SIZE,TILE_SIZE, QColor(0,0,0,255));
                break;
            case 0://Nothing
                p.fillRect (TILE_SIZE*i, TILE_SIZE*j, TILE_SIZE, TILE_SIZE, QColor(255,255,255,255));
                break;
            case 2://Bonus Slow
                p.fillRect (TILE_SIZE*i, TILE_SIZE*j, TILE_SIZE, TILE_SIZE, QColor(128,0,128,255));
                break;
            case 3://Bonus Fast
                p.fillRect (TILE_SIZE*i, TILE_SIZE*j, TILE_SIZE, TILE_SIZE, QColor(0,255,0,255));
                break;
            default:
                qDebug("This should not be in the maze");
>>>>>>> FETCH_HEAD
            }
        }

        // Painting player 1
        Player player = this->onMap->getPlayer1();

        // Testing if reach exit
        if ( (((player.getX() + 10)/TILE_SIZE) == winnerX) && (((player.getY()+ 10)/TILE_SIZE) == winnerY) ){
            this->setFinished(true);
            this->setWinner(PLAYER1);
            return;
        }

        p.fillRect (player.getX(), player.getY(), TILE_SIZE, TILE_SIZE, QColor(255,0,0,255));

        // painting player 2
        player = this->onMap->getPlayer2();

        if ( (((player.getX()+ 10)/TILE_SIZE) == winnerX ) && (((player.getY()+ 10)/TILE_SIZE) == winnerY) ){
            this->setFinished(true);
            this->setWinner(PLAYER2);
            return;
        }

        p.fillRect (player.getX(), player.getY(), TILE_SIZE, TILE_SIZE, QColor(0,0,255,255));

        // Exit Tile
        p.setFont(QFont("Arial", 8, QFont::Bold));
        p.setPen(QPen(QColor(255,0,0,255)));
        p.drawText(TILE_SIZE*27, TILE_SIZE*27, TILE_SIZE,TILE_SIZE,Qt::AlignHCenter | Qt::AlignVCenter , tr("Exit") , NULL);


    } else {
        p.setFont(QFont("Arial", 40, QFont::Bold));
        p.setPen(QPen(QColor(255,0,0,255)));

        if ( this->getWinner() == PLAYER1 ) {
            p.drawText(200,200, 400, 200,NULL, tr("Player 1 won !") , NULL);

        } else if ( this->getWinner() == PLAYER2 ) {
            p.drawText(200,200, 400, 200,NULL, tr("Player 2 won !") , NULL);
        } else {
            p.drawText(200,200, 400, 200,NULL, tr("Error in the winner function!") , NULL);

        }
    }
}


// Filter of KeyEvent
bool MainWindow::eventFilter(QObject *object, QEvent *event)
{
    Player player;
    Position speed;

    if (event->type() == QEvent::KeyPress) {
        QKeyEvent *keyEvent = static_cast<QKeyEvent *>(event);
        pressedKeys += ((QKeyEvent*)event)->key();


        // Player 2 Keys
        // Up
        if ( (keyEvent->key() == Qt::Key_W) || (keyEvent->key() == Qt::Key_Z) || pressedKeys.contains(Qt::Key_Z) || pressedKeys.contains(Qt::Key_W) ) {
            player = this->onMap->getPlayer2();
            speed = player.getSpeed();

            if ((player.getY() - speed.getY()) > 0 ){
                this->onMap->collision (PLAYER2, UP, player.getX(), (player.getY() - speed.getY()) );
            }
        }

        // Left
        if( (keyEvent->key() == Qt::Key_A) || (keyEvent->key() == Qt::Key_Q) || pressedKeys.contains(Qt::Key_A) || pressedKeys.contains(Qt::Key_Q) ) {
            player = this->onMap->getPlayer2();
            speed = player.getSpeed();

            if ((player.getX() - speed.getX()) > 0 ) {
                this->onMap->collision (PLAYER2, LEFT, (player.getX() - speed.getX()), player.getY() );
            }
        }

        // Down
        if(keyEvent->key() == Qt::Key_S || pressedKeys.contains(Qt::Key_S)) {
            player = this->onMap->getPlayer2();
            speed = player.getSpeed();

            if (player.getY() + speed.getY() < (BOUNDS)) {
                this->onMap->collision (PLAYER2, DOWN, player.getX(), (player.getY() + speed.getY()) );
            }
        }

        // Right
        if(keyEvent->key() == Qt::Key_D || pressedKeys.contains(Qt::Key_D) ) {
            player = this->onMap->getPlayer2();
            speed = player.getSpeed();

            if ((player.getX() + speed.getX()) < BOUNDS) {
                this->onMap->collision (PLAYER2, RIGHT, (player.getX() + speed.getX()), player.getY() );
            }
        }

        // Player 1 Keys
        // Up
        if ( (keyEvent->key() == Qt::Key_Up ) || pressedKeys.contains(Qt::Key_Up) ) {
            player = this->onMap->getPlayer1();
            speed = player.getSpeed();

            if ((player.getY() - speed.getY()) > 0 ){
                this->onMap->collision (PLAYER1, UP,  player.getX(), (player.getY() - speed.getY()) );
            }
        }

        // Down
        if ( (keyEvent->key() == Qt::Key_Down) || pressedKeys.contains(Qt::Key_Down) ) {
            player = this->onMap->getPlayer1();
            speed = player.getSpeed();

            if (player.getY() + speed.getY() < (BOUNDS)) {
                this->onMap->collision (PLAYER1, DOWN, player.getX(), (player.getY() + speed.getY()) );
            }
        }

        // Left
        if ( (keyEvent->key() == Qt::Key_Left) || pressedKeys.contains(Qt::Key_Left) ) {
            player = this->onMap->getPlayer1();
            speed = player.getSpeed();

            if ((player.getX() - speed.getX()) > 0 ) {
                this->onMap->collision (PLAYER1, LEFT, (player.getX() - speed.getX()), player.getY() );
            }
        }

        // Right
        if ( (keyEvent->key() == Qt::Key_Right) || pressedKeys.contains(Qt::Key_Right) ){
            player = this->onMap->getPlayer1();
            speed = player.getSpeed();

            if ((player.getX() + speed.getX()) < BOUNDS) {
                this->onMap->collision (PLAYER1, RIGHT, (player.getX() + speed.getX()), player.getY() );
            }
        }

        update();

        return true;

    } else if (event->type() == QEvent::KeyRelease) {
        pressedKeys -= ((QKeyEvent*)event)->key();
        update();

        return true;

    } else {
        update();
        return false;

    }
}

void MainWindow::on_pushButton_clicked()
{
    onMap = new OnMap ();
    this->setWinner(ZERO);
    this->setFinished(false);
    update();
}
int MainWindow::getWinner() const
{
    return winner;
}

void MainWindow::setWinner(int value)
{
    winner = value;
}

bool MainWindow::getFinished() const
{
    return finished;
}

void MainWindow::setFinished(bool value)
{
    finished = value;
}

