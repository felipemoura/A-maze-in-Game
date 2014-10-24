#ifndef AMAZINGWINDOW_H
#define AMAZINGWINDOW_H

#include <QKeyEvent>
#include <QTimerEvent>
#include <ui.h>
#include "onmap.h"

class AmazingWindow
{

private:
    OnMap map;
    QKeyEvent key;
    QBasicTimer timer;

   // Ui ui;
    void on_pushButton_clicked();
    void keyPressedEvent (QKeyEvent);

protected:
    void timerEvent(QTimerEvent);

public:
    // Constructor
    AmazingWindow();

    // Destructor
    ~AmazingWindow ();

    // Methods
    void newFrame();
    void process_display ();

    // Getters
    OnMap getMap() const;
    QKeyEvent getKey() const;
    QBasicTimer getTimer() const;

    // Setters
    void setMap(const OnMap &value);
    void setKey(const QKeyEvent &value);
    void setTimer(const QBasicTimer &value);
};

#endif // AMAZINGWINDOW_H
