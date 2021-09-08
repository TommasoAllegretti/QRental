#ifndef ROADVEHICLE_H
#define ROADVEHICLE_H

#include "rentalobject.h"


class RoadVehicle: public RentalObject {
private:
    double roadFee;
    unsigned int passengersN;
    bool highwayPass;
public:
    RoadVehicle(unsigned int, unsigned int, QString, unsigned int, unsigned int, bool, double, QString, double, unsigned int, bool);

    double getRoadFee() const;
    unsigned int getPassengersN() const;
    bool getHighwayPass() const;

    void setPassengerN(unsigned int);
    void setHighwayPass(bool);
};

#endif // ROADVEHICLE_H
