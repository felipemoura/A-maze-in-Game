#ifndef POSITION_H
#define POSITION_H

/* Position Class

    Objective is to hold information about x Position and y Position in the maze


                    */

#define START_POSITION 16*26

class Position
{

private:
    // Postion in the maze
    int x;
    int y;

public:
    // Constructors
    Position ();
    Position (int,int);

    // Destructor
    //~Position ();

    // Getters
    int getX() const;
    int getY() const;

    // Setters
    void setX(int value);
    void setY(int value);

};

#endif // POSITION_H
