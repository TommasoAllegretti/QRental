#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "routes/routes.h"
#include "mainwindowview.h"
#include "controller/controller.h"

class MainWindow : public QMainWindow {
    Q_OBJECT

private:
    MainWindowView* view;
    Controller* controller;

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
    void setScreen(Routes r);
};

#endif // MAINWINDOW_H
