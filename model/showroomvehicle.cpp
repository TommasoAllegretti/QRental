#include "showroomvehicle.h"

ShowroomVehicle::ShowroomVehicle(unsigned int rT =0, unsigned int i =0, QString n ="null", unsigned int k =0, unsigned int r =0, bool xI =false, double dP =0, QString iP ="", QString sN ="", bool rR =false, unsigned int spN =0, bool sS =false)
    : RentalObject(rT, i, n, k, r, xI, dP, iP), showName(sN), rentRoom(rR), specN(spN), showSec(sS) {

}

double ShowroomVehicle::getRentAmount() const{
    double tot = 0;
    tot += ((getDailyPrice() - (getKm()/5000)+(getRating()*5)+(getShowSec()*20))*getRentTime()) + (getExtraInsurance() ? 200 : 0) + getSpecN() + (getShowSec()*100);
    return tot;
}

double ShowroomVehicle::getRefundAmount() const {
    double tot = 0;
    tot += (((getDailyPrice() - (getKm()/5000))*getRentTime())*0.2) + (getExtraInsurance() ? 20 : 0);
    return tot;
}

ShowroomVehicle* ShowroomVehicle::clone() const {
    return new ShowroomVehicle(*this);
}


QString ShowroomVehicle::getShowName() const {
    return showName;
}

bool ShowroomVehicle::getRentRoom() const {
    return rentRoom;
}

unsigned int ShowroomVehicle::getSpecN() const {
    return specN;
}

bool ShowroomVehicle::getShowSec() const {
    return showSec;
}

void ShowroomVehicle::setShowName(QString _showName) {
    showName = _showName;
}

void ShowroomVehicle::setRentRoom(bool _rentRoom){
    rentRoom = _rentRoom;
}

void ShowroomVehicle::setSpecN(unsigned int _specN){
    specN = _specN;
}

void ShowroomVehicle::setShowSec(bool _showSec) {
    showSec = _showSec;

}
