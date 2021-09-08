#ifndef ATV_H
#define ATV_H

#include "offroadvehicle.h"

class Atv: public OffRoadVehicle {
private:
    bool cleaningServ;
    bool changeTires;
public:
    Atv(unsigned int, unsigned int, QString, unsigned int, unsigned int, bool, double, QString, unsigned int, bool, bool);
    double getRentAmount() const override;
    double getRefundAmount() const override;

    Atv* clone() const override;

    bool getCleaningServ() const;
    bool getChangeTires() const;

    void setCleaningServ(bool);
    void setChangeTires(bool);
};

#endif // ATV_H
