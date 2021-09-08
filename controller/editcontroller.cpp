#include "editcontroller.h"

EditController::EditController(): Controller(), scene(new Edit) {

}

QGraphicsScene* EditController::getScene() const { return scene; }
