#include "player.h"

// Constructors
Player::Player()
{

}


// Destructors
~Player()
{

}

// Getters
//
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
//
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
