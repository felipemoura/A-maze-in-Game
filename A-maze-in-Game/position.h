#ifndef POSITION_H
#define POSITION_H

class Position
{

private:
    int x;
    int y;

public:
    // Constructor
    Position ();
    Position (int,int);

    // Destructor
    ~Position ();

    // Getters
    int getX() const;
    int getY() const;

    // Setters
    void setX(int value);
    void setY(int value);
};

#endif // POSITION_H
