#ifndef OFFROADVEHICLE_H
#define OFFROADVEHICLE_H

#include "rentalobject.h"

class OffRoadVehicle: public RentalObject {
private:
    unsigned int trackCredits;
public:
    OffRoadVehicle(unsigned int, unsigned int, QString, unsigned int, unsigned int, bool, double, QString, unsigned int);

    unsigned int getTrackCredits() const;

    void setTrackCredits(unsigned int);
};

#endif // OFFROADVEHICLE_H
