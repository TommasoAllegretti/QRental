#ifndef MYRENTS_H
#define MYRENTS_H

#include <QGraphicsScene>
#include <QBrush>
#include <QLabel>
#include <QImage>
#include <QDir>
#include <QPushButton>

#include "model/showroomvehicle.h"
#include "model/ormotorcycle.h"
#include "globals/globals.h"

class MyRents: public QGraphicsScene {
    Q_OBJECT
private:
    void loadHomeBtn();
    void loadBG();
    void loadMyRentsPage();
public:
    MyRents();
signals:
    void openHome();
    void restorePage();
};

#endif // MYRENTS_H
