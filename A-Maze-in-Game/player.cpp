#include "player.h"
#include "mazegeneration.h"

// Constructors
Player::Player()
{
    this->speed.setX(4);
    this->speed.setY(4);
    this->numberOfBonus = 0;
}

// Destructors
Player::~Player()
{

}

// Methods
Position Player::desiredPosition ()
{
    Position a;
    return(a);
}
int Player::bonusNow()
{
    return numberOfBonus;
}

void Player::addBonus(int type)
{
    this->bonus=QTime::currentTime ();
    numberOfBonus+=1;
    typeBonus=type;
}

void Player::testEndBonus()
{
    if ((this->bonus.msecsTo ( QTime::currentTime()) > 5000 ) && (numberOfBonus == 1) ) {
        numberOfBonus=0;
        this->speed=Position(4,4);
    }
}

// Getters
Position Player::getPosition() const {
    return position;
}

Position Player::getSpeed() const {
    return speed;
}


// Setters
void Player::setPosition(const Position &value) {
    position = value;
}

void Player::setSpeed(const Position &value) {
    speed = value;
}
