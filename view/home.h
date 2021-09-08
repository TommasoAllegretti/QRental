#ifndef HOME_H
#define HOME_H

#include <QDir>
#include <QGraphicsScene>
#include <QPushButton>
#include <QPalette>
#include <QBrush>
#include <QDebug>
#include <QLabel>
#include <QVBoxLayout>
#include <QImage>

#include "model/rental.h"
#include "globals/globals.h"

class Home: public QGraphicsScene {
    Q_OBJECT
private:
    void loadButton();
    void loadBG();
    void loadProducts(Rental*);
    void loadMenuBar();
    void updateId(unsigned int);
public:
    Home();
signals:
    void openProduct();
    void openMyRents();
};

#endif // HOME_H
