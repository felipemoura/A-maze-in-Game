#ifndef POSITION_H
#define POSITION_H

class Position
{

private:
    int x;
    int y;

public:
    int getX ();
    int getY ();

    void setX (int);
    void setY (int);

    Position ();
    Position (int,int);
};

#endif // POSITION_H
