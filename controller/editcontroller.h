#ifndef EDITCONTROLLER_H
#define EDITCONTROLLER_H

#include <QObject>
#include <QGraphicsScene>
#include "controller.h"
#include "view/edit.h"


class EditController: public Controller {
    Q_OBJECT
private:
    Edit* scene;
public:
    EditController();
    QGraphicsScene* getScene() const;
};

#endif // EDITCONTROLLER_H
