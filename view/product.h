#ifndef PRODUCT_H
#define PRODUCT_H

#include <QGraphicsScene>
#include <QPalette>
#include <QBrush>
#include <QPushButton>
#include <QLabel>
#include <QDir>
#include <QLineEdit>
#include <QCheckBox>
#include <QComboBox>
#include <QSpinBox>
#include <QMessageBox>

#include "globals/globals.h"
#include "model/rental.h"

class Product: public QGraphicsScene {
    Q_OBJECT
private:
    void loadBG();
    void loadHomeBtn();
    void limitMessage();
    void loadProdPage(Rental*);
public:
    Product();
signals:
    void openHome();
};

#endif // PRODUCT_H
