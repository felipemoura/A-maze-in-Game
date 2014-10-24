#include "player.h"

// Constructors
Player::Player()
{

    Position position;
    Position speed;

    string username;

    QBasicTimer timerSlow;
    QBasicTimer timerFast;

}

Player::Player(Position position, Position speed, string username, QBasicTimer timerSlow, QBasicTimer timerFast)
{
    this->setPosition(position);
    this->setUsername(speed);
    this->setUsername(username);
    this->setTimerSlow(timerSlow);
    this->setTimerFast(timerFast);
}

// Destructors
~Player()
{

}

// Getters
Player::Position getSpeed () {
    return this->speed;
}

Player::Position getPosition () {
    return this->posistion;
}

Player::string getUsername () {
    return this->username
}

Player::QBasicTimer getTimerSlow () {
    return this->timerSlow;
}

Player::QBasicTimer getTimerFast () {
    return this->timerFast;
}

// Setters
//
Player::void setSpeed (Position speed) {
    this->speed = speed;
}

Player::void setPosition (Position position) {
    this->position = position;
}

Player::void setUsername (string username) {
    this->username = username;
}

Player::void setTimerSlow (QBasicTimer timerSlow) {
    this->timerSlow = timerSlow;
}

Player::void setTimerFast (QBasicTimer timerFast) {
    this->timerFast = timerFast;
}

// Methods
Player::Position desiredPosition ()
{

}

Player::void applyBonut (int)
{

}

Player::void timerEvent (QTimerEvent)
{

}
