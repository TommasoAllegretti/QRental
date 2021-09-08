#ifndef PRODUCTCONTROLLER_H
#define PRODUCTCONTROLLER_H

#include <QObject>
#include <QGraphicsScene>
#include "controller.h"
#include "view/product.h"


class ProductController: public Controller {
    Q_OBJECT
private:
    Product* scene;
public:
    ProductController();
    QGraphicsScene* getScene() const;
};

#endif // PRODUCTCONTROLLER_H
