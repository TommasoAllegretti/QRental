#ifndef RMOTORCYCLE_H
#define RMOTORCYCLE_H

#include "roadvehicle.h"

class RMotorcycle: public RoadVehicle {
private:
    unsigned int nStates;
public:
    RMotorcycle(unsigned int, unsigned int, QString, unsigned int, unsigned int, bool, double, QString, double, unsigned int, bool, unsigned int);
    double getRentAmount() const override;
    double getRefundAmount() const override;

    RMotorcycle* clone() const override;

    unsigned int getNStates() const;

    void setNStates(unsigned int);

};

#endif // RMOTORCYCLE_H
