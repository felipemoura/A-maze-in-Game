#include "position.h"

Position::Position()
{
    this->setX (0);
    this->setY (0);
 }

Position::int getX()
{
    return this->x;
}

Position::int getY()
{
    return this->y;
}

Position::void setX (int x)
{
    this->x = x;
}

Position::void setY (int y)
{
    this->y = y;
}

Position::Position (int x, int y)
{
    this->x.setX(x);
    this->y.setY(y);
}
