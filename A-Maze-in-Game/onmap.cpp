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

    switch (direction) {
    case UP:
        pos = this->getPositionMaze((desiredX)/TILE_SIZE, (desiredY)/TILE_SIZE);
        pos2 = this->getPositionMaze((desiredX+TILE_SIZE - 1)/TILE_SIZE, (desiredY)/TILE_SIZE);
        break;

    case DOWN:
        pos = this->getPositionMaze((desiredX)/TILE_SIZE, (desiredY + TILE_SIZE - 1)/TILE_SIZE);
        pos2 = this->getPositionMaze((desiredX+TILE_SIZE - 1)/TILE_SIZE, (desiredY + TILE_SIZE - 1)/TILE_SIZE);
        break;

    case LEFT:
        pos = this->getPositionMaze((desiredX)/TILE_SIZE, (desiredY)/TILE_SIZE);
        pos2 = this->getPositionMaze((desiredX)/TILE_SIZE, (desiredY+TILE_SIZE - 1)/TILE_SIZE);
        break;

    case RIGHT:
        pos = this->getPositionMaze((desiredX + TILE_SIZE - 1)/TILE_SIZE, (desiredY)/TILE_SIZE);
        pos2 = this->getPositionMaze((desiredX + TILE_SIZE - 1)/TILE_SIZE, (desiredY+TILE_SIZE - 1)/TILE_SIZE);
        break;

    default:
        qDebug ("Unkown Direction");
        return;
        break;
    }

    if (pos == INVALID) return;

    if (pos == WALL) return;
    if (pos2== WALL) return;


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
