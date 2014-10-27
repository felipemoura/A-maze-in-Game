#include "onmap.h"
#include "mainwindow.h"
#include <QDebug>

// Constructor
OnMap::OnMap()
{
    //Player ();

    MazeGeneration* desiredMaze = new MazeGeneration ();
    setMaze( desiredMaze->getMaze() );

    setWidthGame(desiredMaze->getSize());
    setHeightGame(desiredMaze->getSize());
}

// Destructor
OnMap::~OnMap()
{

}

// Methods
void OnMap::update ()
{

}

void OnMap::collision (int option, int direction, int desiredX, int desiredY)
{
    int pos;
    int pos2;
    int xSquare,ySquare;
    int xSquare2,ySquare2;


    switch (direction) {
    case UP:
        xSquare=(desiredX)/TILE_SIZE;
        ySquare=(desiredY)/TILE_SIZE;
        xSquare2=(desiredX+TILE_SIZE - 1)/TILE_SIZE;
        ySquare2= (desiredY)/TILE_SIZE;
        break;

    case DOWN:
        xSquare=(desiredX)/TILE_SIZE;
        ySquare=(desiredY + TILE_SIZE - 1)/TILE_SIZE;
        xSquare2=(desiredX+TILE_SIZE - 1)/TILE_SIZE;
        ySquare2=(desiredY + TILE_SIZE - 1)/TILE_SIZE;
        break;

    case LEFT:
        xSquare=(desiredX)/TILE_SIZE;
        ySquare=(desiredY)/TILE_SIZE;
        xSquare2=(desiredX)/TILE_SIZE;
        ySquare2=(desiredY+TILE_SIZE - 1)/TILE_SIZE;
        break;

    case RIGHT:
        xSquare=(desiredX + TILE_SIZE - 1)/TILE_SIZE;
        ySquare=(desiredY)/TILE_SIZE;
        xSquare2=(desiredX + TILE_SIZE - 1)/TILE_SIZE;
        ySquare2=(desiredY + TILE_SIZE - 1)/TILE_SIZE;
        break;

    default:
        qDebug ("Unkown Direction");
        return;
        break;
    }

      pos = this->getPositionMaze(xSquare, ySquare);
      pos2 = this->getPositionMaze(xSquare2, ySquare2);

    if (pos == INVALID) return;

    if (pos == WALL) return;
    if (pos2== WALL) return;

    //We test the bonus after the wall to avoid the possibility of touching a bonus where it is not possible to commit.
    if (pos == SBONUS)
    {
        //We put 0 where the bonus is
        maze[xSquare][ySquare]=0;
        //We divide by 2 the quickness of the player
         if (option == PLAYER1) {
         qDebug("%d",player1.getSpeed().getX());
            Position newSpeed= Position(player1.getSpeed().getX()/2,player1.getSpeed().getY()/2);
            player1.setSpeed(newSpeed);
            qDebug("%d",player1.getSpeed().getX());
        } else {
            Position newSpeed= Position(player2.getSpeed().getX()/2,player2.getSpeed().getY()/2);
            player2.setSpeed(newSpeed);
        }

    }
     if (pos == FBONUS)
    {
        //We put 0 where the bonus is
        maze[xSquare][ySquare]=0;
        //We multiply by two the quickness of the player
         if (option == PLAYER1) {
            qDebug("%d",player1.getSpeed().getX());
            Position newSpeed= Position(2*player1.getSpeed().getX(),2*player1.getSpeed().getY());
            player1.setSpeed(newSpeed);
            qDebug("%d",player1.getSpeed().getX());

        } else {
            Position newSpeed= Position(player2.getSpeed().getX()*2,2*player2.getSpeed().getY());
            player2.setSpeed(newSpeed);
        }

    }

    if (option == PLAYER1) {

        player1.setX(desiredX);
        player1.setY(desiredY);

    } else {
        player2.setX(desiredX);
        player2.setY(desiredY);
    }
}

// Getters
//
Player OnMap::getPlayer2() const {
    return player2;
}

Player OnMap::getPlayer1() const {
    return player1;
}

int OnMap::getWidthGame() const {
    return widthGame;
}

int OnMap::getHeightGame() const {
    return heightGame;
}

int OnMap::getSizeSquare() const {
    return sizeSquare;
}

int OnMap::getSizeMaze() const {
    return sizeMaze;
}

int **OnMap::getMaze() const {
    return maze;
}

//QFrame OnMap::getWidget() const {
//    return widget;
//}


// Setters
//
void OnMap::setPlayer2(const Player &value) {
    player2 = value;
}

void OnMap::setPlayer1(const Player &value) {
    player1 = value;
}

void OnMap::setWidthGame(int value) {
    widthGame = value;
}

void OnMap::setHeightGame(int value) {
    heightGame = value;
}

void OnMap::setSizeSquare(int value) {
    sizeSquare = value;
}

void OnMap::setSizeMaze(int value) {
    sizeMaze = value;
}

void OnMap::setMaze(int **value){
    maze = value;
}


//void OnMap::setWidget(const QFrame &value) {
//    widget = value;
//}
