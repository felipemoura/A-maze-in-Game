#ifndef PLAYER_H
#define PLAYER_H

#include <QBasicTimer>
#include <QTimerEvent>
#include <string>
#include <QTime>
#include "position.h"

/* Player Class

    Objective is to hold all information about player
        Position
        Bonuses Activated
        Timers
*/

using namespace std;

class Player : public Position
{

private:
    Position position;
    Position speed;

    string username;
    int numberOfBonus;
    int typeBonus;
    QTime bonus;
    void timerEvent (QTimerEvent);

public:
    // Constructors
    Player ();

    // Destructors
    ~Player();

    // Methods
    Position desiredPosition ();
    int bonusNow();
    void addBonus(int );
    void testEndBonus();

    // Timers
    QBasicTimer EndSlow;
    QBasicTimer EndFast;

    // Getters
    Position getPosition() const;
    Position getSpeed() const;

    // Setters
    void setSpeed(const Position &value);
    void setPosition(const Position &value);

};

#endif // PLAYER_H
