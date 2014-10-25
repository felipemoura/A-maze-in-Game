#include "position.h"

/* Position Class

    Objective is to hold information about x Position and y Position in the maze

                    */

// Constructor with no parameters
Position::Position()
{
    setX(START_POSITION);
    setY(START_POSITION);
}

// Constructor with position as parameters
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
