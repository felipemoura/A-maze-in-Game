#ifndef ONMAP_H
#define ONMAP_H

#include <QFrame>
#include "player.h"
#include "mazegeneration.h"

class OnMap
{

public:
    // Constructor
    OnMap ();

    // Destructor
    ~OnMap ();

    // Getters
    Player getPlayer2() const;
    Player getPlayer1() const;

    QFrame getWidget() const;

    int getWidthGame() const;
    int getHeightGame() const;

    int getSizeSquare() const;
    int getSizeMaze() const;

    int **getMaze() const;

    // Setters
    void setPlayer1(const Player &value);
    void setPlayer2(const Player &value);

    void setWidget(const QFrame &value);

    void setWidthGame(int value);
    void setHeightGame(int value);

    void setSizeSquare(int value);
    void setSizeMaze(int value);

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
