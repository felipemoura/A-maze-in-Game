#include "mazegeneration.h"
#include <QDebug>
#include <QString>
#include <string>
#include <time.h>

MazeGeneration::MazeGeneration()
{
    // Starting  Random Function
    srand(time(NULL));

    setSize (MAZE_SIZE);
    maze = mazeGeneration();
}

MazeGeneration::~MazeGeneration()
{
    int i;

    for (i = 0; i < getSize(); i++) {
        if (maze[i] != NULL) {
            delete [] maze[i];
        }
    }

    if (maze != NULL) {
        delete [] maze;
    }
}

int** MazeGeneration::mazeGeneration ()
{
    int i, j,a,b, nb_bonus = 0;

    maze = new int* [getSize()];

    for (i = 0; i < getSize(); i++) {
        maze[i] = new int [getSize()];
    }

    //qDebug( "Start to generate a maze" );

    for (i = 0; i < getSize(); i++) {
        for(j = 0; j < getSize(); j++) {
            maze[i][j] = 1;
        }
    }

    // Generates the maze recursively
    workOnCell( 1,1 );

    //Adds 5 bonuses
    while (nb_bonus < 15) {
        a=rand() % getSize();
        b=rand() % getSize();
        if ( (a==1) && (b==1) ){
            a=5;
            b=5;
        }

        if (maze[a][b] == 0) {
            maze[a][b] = 2 + rand() % 2;
            nb_bonus += 1;
            //qDebug("We add a bonus");
        }
    }
    return getMaze();
}
void MazeGeneration::addBonus()
{
    //We put a new bonus on the Map
    int a,b;
    int bonus_added=0;

    while (bonus_added ==0) {
        a=rand() % getSize();
        b=rand() % getSize();
        if (maze[a][b] == 0) {
            maze[a][b] = 2 + rand() % 2;
            bonus_added += 1;
            //qDebug("We add a bonus");
        }
    }
}
void MazeGeneration::workOnCell (int xCell,int yCell)
{
    int i;
    int order[4];
    int storage;
    int xToLook, yToLook;
    int a, b;

    maze[xCell][yCell] = 0;

    //We first generate a sequence telling when in which order we visit the neighbours (each neighbour is identified by an integer)
    for (i = 0; i < 4; i++) {
        order[i] = i;
    }

    for (i = 0; i < NUMBER_OF_GENERATIONS ; i++) {
        a=rand() % 4;
        b=rand() % 4;

        storage=order[a];
        order[a]=order[b];
        order[b]=storage;
    }

    //We have to check the 4 neighbours:
    for (i = 0; i < 4; i++) {

        switch(order[i]) {

        case 0:
            xToLook = xCell + 2;
            yToLook = yCell;
            break;
        case 1:
            xToLook = xCell;
            yToLook = yCell + 2;
            break;
        case 2:
            xToLook = xCell - 2;
            yToLook = yCell;
            break;
        case 3:
            xToLook = xCell;
            yToLook = yCell - 2;
            break;
        default:
            qDebug( "Problem in the order generation" );
            break;
        }

        //Check if the cell to look is in the limits:
        if ( (xToLook >= 0) && (xToLook < ( getSize() -1)) && (yToLook >= 0) && (yToLook < (getSize() -1)) ) {
            if (maze[xToLook][yToLook] == 1) {

                //We have to watch this cell
                maze [(xToLook + xCell) /2][(yToLook + yCell) /2]=0;
                workOnCell (xToLook, yToLook);
            }
        }

    }
}

int MazeGeneration::getPositionMaze(int posX, int posY)
{
    if ( (posX >= ZERO) && (posY >= ZERO) && (posX < MAZE_SIZE) && (posY < MAZE_SIZE) ) {
        return this->maze[posX][posY];
    } else {
        return INVALID;
    }
}

void MazeGeneration::setPositionMaze(int posX, int posY, int value)
{
    if ( (posX >= ZERO) && (posY >= ZERO) && (posX < MAZE_SIZE) && (posY < MAZE_SIZE) ){
        maze[posX][posY]=value;
    } else {
        qDebug("Cell out of bound");
    }
}

// Getters
int **MazeGeneration::getMaze() const
{
    return maze;
}

int MazeGeneration::getSize() const
{
    return size;
}

// Setters
void MazeGeneration::setSize(int value)
{
    size = value;
}