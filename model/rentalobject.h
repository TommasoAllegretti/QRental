#ifndef RENTALOBJECT_H
#define RENTALOBJECT_H

#include <string>
#include <QString>
#include "container.h"

class RentalObject{
private:
    unsigned int rentTime;
    unsigned int id;
    QString name;
    unsigned int km;
    unsigned int rating;
    bool extraInsurance;
    double dailyPrice;
    QString imgPath;
protected:
public:
    RentalObject(unsigned int, unsigned int, QString, unsigned int, unsigned int, bool, double, QString);
    virtual ~RentalObject() =default;


    virtual double getRentAmount() const = 0;
    virtual double getRefundAmount() const = 0;

    virtual RentalObject* clone() const =0;

    unsigned int getRentTime() const;
    unsigned int getId() const;
    QString getName() const;
    unsigned int getKm() const;
    unsigned int getRating() const;
    bool getExtraInsurance() const;
    double getDailyPrice() const;
    QString getImgPath() const;

    void setExtraInsurance(bool);
    void setRentTime(unsigned int);
};

#endif // RENTALOBJECT_H
