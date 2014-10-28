#include "onmap.h"
#include "mainwindow.h"
#include <QDebug>

// Constructor
OnMap::OnMap()
{
    currentMaze= new MazeGeneration ();
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
    int xMiddle, yMiddle;


    //First we look if the bonus end:
    player1.testEndBonus();
    player2.testEndBonus();

    //Second we look at the collisions
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

    pos = this->currentMaze->getPositionMaze(xSquare, ySquare);
    pos2 = this->currentMaze->getPositionMaze(xSquare2, ySquare2);

    if (pos == INVALID) return;

    if ((pos == WALL)||(pos2==WALL)) {
        //We put the player just near the wall
        xMiddle=(desiredX + 0.5* TILE_SIZE )/TILE_SIZE;
        yMiddle=(desiredY + 0.5 * TILE_SIZE )/TILE_SIZE;
        if (option == PLAYER1) {

            player1.setX(xMiddle*TILE_SIZE);
            player1.setY(yMiddle*TILE_SIZE);

        } else {
            player2.setX(xMiddle*TILE_SIZE);
            player2.setY(yMiddle*TILE_SIZE);
        }
        return;
    }

    //We test the bonus after the wall to avoid the possibility of touching a bonus where it is not possible to commit.
    // Slow Bonus
    if (pos == SBONUS) {
        //We divide by 2 the quickness of the player
        if ((option == PLAYER1)&&(player1.bonusNow()==0)) {
            //We put 0 where the bonus is.
            this->currentMaze->setPositionMaze(xSquare,ySquare,0);
            //Position newSpeed= Position(player1.getSpeed().getX()/2,player1.getSpeed().getY()/2);
            Position newSpeed= Position(1,1);
            player1.setSpeed(newSpeed);
            player1.addBonus(pos);
        }
        if ((option == PLAYER2)&&(player2.bonusNow()==0)) {
            //We put 0 where the bonus is.
            this->currentMaze->setPositionMaze(xSquare,ySquare,0);
            //Position newSpeed= Position(player2.getSpeed().getX()/2,player2.getSpeed().getY()/2);
            Position newSpeed= Position(1,1);
            player2.setSpeed(newSpeed);
            player2.addBonus(pos);
        }
    }

    //FastBonus
    if (pos == FBONUS) {
        //We divide by 2 the quickness of the player
        if ((option == PLAYER1)&&(player1.bonusNow()==0)) {
            //We put 0 where the bonus is.
            this->currentMaze->setPositionMaze(xSquare,ySquare,0);
            //Position newSpeed= Position(player1.getSpeed().getX()*2,player1.getSpeed().getY()*2);
            Position newSpeed= Position(7,7);
            player1.setSpeed(newSpeed);
            player1.addBonus(pos);
        }
        if ((option == PLAYER2)&&(player2.bonusNow()==0)) {
            //We put 0 where the bonus is.
            this->currentMaze->setPositionMaze(xSquare,ySquare,0);
            //Position newSpeed= Position(player2.getSpeed().getX()*2,player2.getSpeed().getY()*2);
            Position newSpeed= Position(7,7);
            player2.setSpeed(newSpeed);
            player2.addBonus(pos);
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
    return this->currentMaze->getMaze();
}


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
    //maze = value;
}
