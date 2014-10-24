#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);

    ~MainWindow();
    
    int maze[30][30];
    int x[20][20];
    int y[20][20];

    int length;
    int height;
    int totalCells;



private:
    Ui::MainWindow *ui;
    void workOnCell(int,int);
};

#endif // MAINWINDOW_H
