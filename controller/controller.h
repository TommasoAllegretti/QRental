#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QObject>
#include <QGraphicsScene>
#include "routes/routes.h"

class Controller: public QObject {
    Q_OBJECT
public:
    Controller(QObject* parent = 0);
    virtual QGraphicsScene* getScene() const =0;
signals:
    void goToScene(Routes r);
};

#endif // CONTROLLER_H
