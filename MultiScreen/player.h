#ifndef PLAYER_H
#define PLAYER_H

class Player
{
public:
    Player(int , int, int , int );
    void desiredPosition(int[20][20]);


    int posX;
    int posY;
    int speedX;
    int speedY;
    int heightGame;
    int widthGame;
    int sizeMaze;
    int sizePlayer;
};

#endif // PLAYER_H
