#include "myrentscontroller.h"

MyRentsController::MyRentsController(): Controller(), scene(new MyRents) {
    connect(scene, &MyRents::openHome, this, [=](){emit goToScene(Routes::HomeScreen);});
    connect(scene, &MyRents::restorePage, this, [=](){emit goToScene(Routes::MyRentsScreen);});
}

QGraphicsScene* MyRentsController::getScene() const { return scene; }
