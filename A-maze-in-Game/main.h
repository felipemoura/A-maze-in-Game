#ifndef MAIN_H
#define MAIN_H

#include <QMainWindow>
#include <ui.h>
#include "amazingwindow.h"

namespace Ui {
class Main;
}

class Main : public QMainWindow
{
    Q_OBJECT

public:
    explicit Main(QWidget *parent = 0);
    ~Main();

private:
    Ui::Main *ui;

    //QApplicaition app;
   // AmazingWindow window;
};

#endif // MAIN_H
