#ifndef ONMAP_H
#define ONMAP_H
#include "player.h"

class OnMap
{
public:
    OnMap();
    void Collide()  ;
    void Update();

    Player* player1;
    Player* player2;
    int CurrentMap[20][20];
    //Has 0 if the square is a free space, 1 if it is a wall 2 if it is a slow bonus and 3 if it is a fast bonus.
    int heightGame;
    int widthGame;
    int sizeMaze;
    int sizePlayer;
};

#endif // ONMAP_H
