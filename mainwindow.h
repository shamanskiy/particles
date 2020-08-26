#pragma once

#include <QMainWindow>
#include <QTimer>

#include "source/Drawer.h"
#include "source/ParticleSystem.h"
#include "source/EulerODE.h"
#include "source/RungeKuttaODE.h"

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
    virtual void keyPressEvent(QKeyEvent *event);

protected slots:
    void makeTimeStep();


private:
    Ui::MainWindow *ui;

    ParticleSystem particles;
    Drawer drawer;
    RungeKuttaODE solver;
    QTimer timer;
    int time;
    int timeStep;
    bool isActive;

};
