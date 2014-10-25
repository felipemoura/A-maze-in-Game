#include "onmap.h"

// Constructor
OnMap::OnMap()
{
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

void OnMap::collision ()
{

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
