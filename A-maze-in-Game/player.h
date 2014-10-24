#ifndef PLAYER_H
#define PLAYER_H

#include <QBasicTimer>
#include <QTimerEvent>
#include <string>
#include "position.h"

using namespace std;

class Player
{


private:

    Position position;
    Position speed;

    string username;

    QBasicTimer timerSlow;
    QBasicTimer timerFast;

    void timerEvent (QTimerEvent);

public:
    // Getters
    Position getSpeed ();
    Position getPosition ();
    string getString ();
    QBasicTimer getTimerSlow ();
    QBasicTimer getTimerFas ();

    // Setters
    void setSpeed (Position);
    void setPosition (Position);
    void setUsername (string);
    void setTimerSlow (QBasicTimer);
    void setTimerFast (QBasicTimer);

    // Constructors
    Player ();
    Player (Position, Position, string, QBasicTimer, QBasicTimer);

    // Destructors
    ~Player();

    // Methods
    Position desiredPosition ();
    void applyBonut (int);

};

#endif // PLAYER_H
