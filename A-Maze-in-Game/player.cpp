#include "player.h"
#include "mazegeneration.h"

// Constructors
Player::Player()
{
    this->speed.setX(4);
    this->speed.setY(4);
<<<<<<< HEAD
    this->numberOfBonus = 0;
=======
    this->numberOfBonus=0;
>>>>>>> FETCH_HEAD
}

Player::Player (Position desiredPosition, Position desiredSpeed, string desiredUsername)
{
    setPosition(desiredPosition);
    setSpeed(desiredSpeed);
    setUsername(desiredUsername);
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


<<<<<<< HEAD
    if ((this->bonus.msecsTo ( QTime::currentTime()) > 5000 ) && (numberOfBonus == 1) ) {
        //qDebug("%d",bonus.msecsTo ( QTime::currentTime()));
=======
    if ((this->bonus.msecsTo ( QTime::currentTime())>5000)&&(numberOfBonus==1))
    {
        qDebug("%d",bonus.msecsTo ( QTime::currentTime()));
>>>>>>> FETCH_HEAD
        numberOfBonus=0;
        this->speed=Position(4,4);
        /*
        if (typeBonus==SBONUS)
        {
            Position newSpeed= Position(this->getSpeed().getX()*2,this->getSpeed().getY()*2);
            this->setSpeed(newSpeed);

        }else
        {
            Position newSpeed= Position(this->getSpeed().getX()*2,this->getSpeed().getY()*2);
            this->setSpeed(newSpeed);

        }
        if (typeBonus==FBONUS)
        {
            Position newSpeed= Position(this->getSpeed().getX()/2,this->getSpeed().getY()/2);
            this->setSpeed(newSpeed);

        }else
        {
            Position newSpeed= Position(this->getSpeed().getX()/2,this->getSpeed().getY()/2);
            this->setSpeed(newSpeed);

        }
        */

    }

}

void Player::applyBonus (int)
{

}

void Player::timerEvent (QTimerEvent)
{

}

// Getters
Position Player::getPosition() const {
    return position;
}

Position Player::getSpeed() const {
    return speed;
}

string Player::getUsername() const {
    return username;
}



// Setters
void Player::setPosition(const Position &value) {
    position = value;
}

void Player::setSpeed(const Position &value) {
    speed = value;
}

void Player::setUsername(const string &value) {
    username = value;
}


