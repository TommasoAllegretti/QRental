#ifndef MAINWINDOWVIEW_H
#define MAINWINDOWVIEW_H

#include <QGraphicsView>

class MainWindowView: public QGraphicsView {
public:
    MainWindowView();
    void resizeEvent(QResizeEvent*);
};

#endif // MAINWINDOWVIEW_H
