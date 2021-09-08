#ifndef SHOWROOMVEHICLE_H
#define SHOWROOMVEHICLE_H

#include "rentalobject.h"

class ShowroomVehicle: public RentalObject {
private:
    QString showName;
    bool rentRoom;
    unsigned int specN;
    bool showSec;
public:
    ShowroomVehicle(unsigned int, unsigned int, QString, unsigned int, unsigned int, bool, double, QString, QString, bool, unsigned int, bool);
    double getRentAmount() const override;
    double getRefundAmount() const override;

    ShowroomVehicle* clone() const override;

    QString getShowName() const;
    bool getRentRoom() const;
    unsigned int getSpecN() const;
    bool getShowSec() const;

    void setShowName(QString);
    void setRentRoom(bool);
    void setSpecN(unsigned int);
    void setShowSec(bool);
};

#endif // SHOWROOMVEHICLE_H
