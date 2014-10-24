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
    AmazingWindow();

    void newFrame();
    void process_display ();
};

#endif // AMAZINGWINDOW_H
