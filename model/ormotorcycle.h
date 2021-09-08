#ifndef ORMOTORCYCLE_H
#define ORMOTORCYCLE_H

#include "offroadvehicle.h"

class ORMotorcycle: public OffRoadVehicle {
private:
    bool prevInjuries;
    QString raceName;
public:
    ORMotorcycle(unsigned int, unsigned int, QString, unsigned int, unsigned int, bool, double, QString, unsigned int, bool, QString);
    double getRentAmount() const override;
    double getRefundAmount() const override;

    ORMotorcycle* clone() const override;

    bool getPrevInjuries() const;
    QString getRaceName() const;

    void setPrevInjuries(bool);
    void setRaceName(QString);
};

#endif // ORMOTORCYCLE_H
