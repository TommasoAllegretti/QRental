#ifndef MYRENTSCONTROLLER_H
#define MYRENTSCONTROLLER_H

#include <QObject>
#include <QGraphicsScene>
#include "controller.h"
#include "view/myrents.h"

class MyRentsController: public Controller {
    Q_OBJECT
private:
    MyRents* scene;
public:
    MyRentsController();
    QGraphicsScene* getScene() const;
};

#endif // MYRENTSCONTROLLER_H
