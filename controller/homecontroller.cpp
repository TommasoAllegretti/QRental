#include "homecontroller.h"

HomeController::HomeController() : Controller(), scene(new Home){
    connect(scene, &Home::openProduct, this, [=](){emit goToScene(Routes::ProductScreen);});
    connect(scene, &Home::openMyRents, this, [=](){emit goToScene(Routes::MyRentsScreen);});
}

QGraphicsScene* HomeController::getScene() const { return scene; }
