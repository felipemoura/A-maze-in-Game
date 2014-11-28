#ifndef ONMAP_H
#define ONMAP_H

#include "player.h"
#include "mazegeneration.h"

#define PLAYER1 1
#define PLAYER2 2

#define UP 1
#define DOWN 2
#define LEFT 3
#define RIGHT 4

class OnMap : public Player, public MazeGeneration
{

public:
    // Methods
    void collision (int, int, int, int);

    // Constructor
    OnMap ();

    // Destructor
    ~OnMap ();

    // Getters
    Player getPlayer2() const;
    Player getPlayer1() const;

    int getWidthGame() const;
    int getHeightGame() const;

    int getSizeSquare() const;
    int getSizeMaze() const;

    int **getMaze() const;

    // Setters
    void setPlayer1(const Player &value);
    void setPlayer2(const Player &value);

    void setWidthGame(int value);
    void setHeightGame(int value);

    void setSizeSquare(int value);
    void setSizeMaze(int value);


private:
    Player player1;
    Player player2;

    int widthGame;
    int heightGame;

    int sizeSquare;
    int sizeMaze;

    MazeGeneration* currentMaze;
};

#endif // ONMAP_H
