#ifndef PLAYER_H
#define PLAYER_H

#include <QBasicTimer>
#include <QTimerEvent>
#include <string>
#include <QTime>
#include "position.h"

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
    Player (Position, Position, string);

    // Destructors
    ~Player();

    // Getters
    Position getPosition() const;
    Position getSpeed() const;

    string getUsername() const;

    QBasicTimer EndSlow;
    QBasicTimer EndFast;

    // Setters
    void setSpeed(const Position &value);
    void setPosition(const Position &value);

    void setUsername(const string &value);

    void setTimerSlow(const QBasicTimer &value);
    void setTimerFast(const QBasicTimer &value);
    int bonusNow();
    void addBonus(int );
    void testEndBonus();
    // Methods
    Position desiredPosition ();
    void applyBonus (int);
};

#endif // PLAYER_H
