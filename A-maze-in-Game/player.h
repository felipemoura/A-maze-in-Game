#ifndef PLAYER_H
#define PLAYER_H

#include <QBasicTimer>
#include <QTimerEvent>
#include <string>
#include "position.h"

class Player
{


private:

    Position position;
    Position speed;

    std::string username;

    QBasicTimer timerSlow;
    QBasicTimer timerFast;

    void timerEvent (QTimerEvent);

public:

    Player();
    Position desiredPosition ();
    void applyBonut (int);

};

#endif // PLAYER_H
