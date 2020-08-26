#-------------------------------------------------
#
# Project created by QtCreator 2017-12-25T22:10:32
#
#-------------------------------------------------

QT       += core gui
CONFIG += console c++11

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Particles
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    source/ParticleSystem.cpp \
    source/Particle.cpp \
    source/Drawer.cpp \
    source/EulerODE.cpp \
    source/BaseODE.cpp \
    source/Force.cpp \
    source/RungeKuttaODE.cpp \
    source/Wall.cpp

HEADERS  += mainwindow.h \
    source/ParticleSystem.h \
    source/Particle.h \
    source/Drawer.h \
    source/EulerODE.h \
    source/BaseODE.h \
    source/BaseSystem.h \
    source/Force.h \
    source/RungeKuttaODE.h \
    source/Wall.h

FORMS    += mainwindow.ui
