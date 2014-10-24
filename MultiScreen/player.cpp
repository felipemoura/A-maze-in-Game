#include "player.h"

Player::Player(int _widthGame, int _heightGame, int _sizeSquare, int _sizeMaze)
{
    this->widthGame=_widthGame;
    this->heightGame=_heightGame;
    this->sizePlayer=_sizeSquare;
    this->sizeMaze=_sizeMaze;

    this->posX=4;
    this->posY=4 ;
    this->speedX=0;
    this->speedY=1;

}
void Player::desiredPosition(int CurrentMap[20][20] )
{
    int desiredX,desiredY;
    int value=this->posX+this->speedX;
    if (value<0)
    {
        value=0;
        this->speedX=-this->speedX;
    }
    if (value>(this->widthGame-this->sizePlayer))
    {
        value=this->widthGame-this->sizePlayer;
        this->speedX=-this->speedX;
    }
    this->posX =value;

    value=this->posY+this->speedY;
    if (value<0)
    {
        value=0;
        this->speedY=-this->speedY;
    }
    if (value>(this->heightGame-this->sizePlayer))
    {
        value=this->heightGame-this->sizePlayer;
        this->speedY=-this->speedY;
    }
    this->posY =value;
}
