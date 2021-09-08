#include "productcontroller.h"

ProductController::ProductController() : Controller(), scene(new Product) {
    connect(scene, &Product::openHome, this, [=](){emit goToScene(Routes::HomeScreen);});
}

QGraphicsScene* ProductController::getScene() const { return scene; }
