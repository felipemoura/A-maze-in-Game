#include "player.h"

// Constructors
Player::Player()
{
    this->speed.setX(2);
    this->speed.setY(2);
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

QBasicTimer Player::getTimerSlow() const {
    return timerSlow;
}

QBasicTimer Player::getTimerFast() const {
    return timerFast;
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

void Player::setTimerSlow(const QBasicTimer &value) {
    timerSlow = value;
}

void Player::setTimerFast(const QBasicTimer &value) {
    timerFast = value;
}
