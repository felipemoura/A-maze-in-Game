#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "onmap.h"
#include <QSet>

#define X_SIZE 680
#define Y_SIZE 480
#define BOUNDS 450

#define TILE_SIZE 16

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

protected:
    void paintEvent (QPaintEvent *);
    bool eventFilter(QObject *, QEvent *);

private:
    OnMap* onMap;
    Ui::MainWindow *ui;
    QSet<int> pressedKeys;
};

#endif // MAINWINDOW_H
