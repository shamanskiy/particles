#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QKeyEvent>

#include <iostream>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    particles(),
    drawer(particles,this),
    solver(),
    timer(this),
    time(0),
    timeStep(40),
    isActive(false)
{
    ui->setupUi(this);
    setCentralWidget(&drawer);
    timer.setInterval(abs(timeStep));

    connect(&timer,SIGNAL(timeout()),SLOT(makeTimeStep()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::keyPressEvent(QKeyEvent *event){
    if (event->key()==Qt::Key_Space)
    {
        if(isActive)
            timer.stop();
        else
            timer.start();

        isActive = !isActive;
    }
    if (event->key()==Qt::Key_M)
    {
        drawer.toggleMesh();
    }
    if (event->key()==Qt::Key_R)
    {
        timeStep = -1*timeStep;
    }

    event->accept();
}

void MainWindow::makeTimeStep()
{
    time += timeStep;
    solver.makeStep(particles,0.001*timeStep);
    particles.checkWalls();
    drawer.update();
}
