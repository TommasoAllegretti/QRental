#ifndef RENTAL_H
#define RENTAL_H

#include "container.h"
#include "deepptr.h"
#include "rentalobject.h"
#include "showroomvehicle.h"
#include "car.h"
#include "rmotorcycle.h"
#include "ormotorcycle.h"
#include "atv.h"

class Rental {
private:
    Container<DeepPtr<RentalObject>> lst;
public:
    Rental();
    Container<DeepPtr<RentalObject>>::iterator getBegin();
    Container<DeepPtr<RentalObject>>::iterator getEnd();
};

#endif // RENTAL_H
