#include "amazingwindow.h"



// Getters
OnMap AmazingWindow::getMap() const {
    return map;
}

QKeyEvent AmazingWindow::getKey() const {
    return key;
}


QBasicTimer AmazingWindow::getTimer() const {
    return timer;
}

// Setters
void AmazingWindow::setMap(const OnMap &value) {
    map = value;
}

void AmazingWindow::setKey(const QKeyEvent &value) {
    key = value;
}

void AmazingWindow::setTimer(const QBasicTimer &value) {
    timer = value;
}
