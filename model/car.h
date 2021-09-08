#ifndef CAR_H
#define CAR_H

#include "roadvehicle.h"

class Car: public RoadVehicle {
private:
    bool ac;
    bool autoWind;
    bool gps;
public:
    Car(unsigned int, unsigned int, QString, unsigned int, unsigned int, bool, double, QString, double, unsigned int, bool, bool, bool, bool);
    double getRentAmount() const override;
    double getRefundAmount() const override;

    Car* clone() const override;

    bool getAc() const;
    bool getAutoWind() const;
    bool getGps() const;

    void setAc(bool);
    void setAutoWind(bool);
    void setGps(bool);
};

#endif // CAR_H
