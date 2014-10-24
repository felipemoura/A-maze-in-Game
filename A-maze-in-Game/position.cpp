#include "position.h"


// Constructor
Position::Position()
{
    setX(0);
    setY(0);
}

Position::Position (int value1, int value2)
{
    setX(value1);
    setY(value2);
}


// Getters
int Position::getY() const {
    return y;
}

int Position::getX() const {
    return x;
}

// Setters
void Position::setX(int value) {
    x = value;
}

void Position::setY(int value) {
    y = value;
}
