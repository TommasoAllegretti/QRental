#include "rentalobject.h"

RentalObject::RentalObject(unsigned int rT =0, unsigned int i =0, QString n ="null", unsigned int k =0, unsigned int r =0, bool xI =false, double dP =0, QString iP ="")
                        : rentTime(rT), id(i), name(n), km(k), rating(r), extraInsurance(xI), dailyPrice(dP), imgPath(iP) {

}

unsigned int RentalObject::getRentTime() const {
    return rentTime;
}

unsigned int RentalObject::getId() const {
    return id;
}

QString RentalObject::getName() const {
    return name;
}

unsigned int RentalObject::getKm() const{
    return km;
}

unsigned int RentalObject::getRating() const{
    return rating;
}

bool RentalObject::getExtraInsurance() const{
    return extraInsurance;
}

double RentalObject::getDailyPrice() const{
    return dailyPrice;
}


QString RentalObject::getImgPath() const {
    return imgPath;
}

void RentalObject::setExtraInsurance(bool _extraInsurance) {
    extraInsurance = _extraInsurance;
}

void RentalObject::setRentTime(unsigned int _rentTime) {
    rentTime = _rentTime;
}
