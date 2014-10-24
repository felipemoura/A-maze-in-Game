#ifndef ONMAP_H
#define ONMAP_H

#include <QFrame>
#include "player.h"
#include "mazegeneration.h"

class OnMap
{
public:
    OnMap();

    Player getPlayer2() const;
    void setPlayer2(const Player &value);

    Player getPlayer1() const;
    void setPlayer1(const Player &value);

    int getWidthGame() const;
    void setWidthGame(int value);

    int getHeightGame() const;
    void setHeightGame(int value);

    int getSizeSquare() const;
    void setSizeSquare(int value);

    int getSizeMaze() const;
    void setSizeMaze(int value);

    int **getMaze() const;
    void setMaze(int **value);

private:

    Player player1;
    Player player2;

    QFrame widget;

    int widthGame;
    int heightGame;

    int sizeSquare;
    int sizeMaze;

    int ** maze;

    void update ();
    void collision ();

};

#endif // ONMAP_H
