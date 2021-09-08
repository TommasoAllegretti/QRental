#include "car.h"

Car::Car(unsigned int rT =0, unsigned int i =0, QString n ="null", unsigned int k =0, unsigned int r =0, bool xI =false, double dP =0, QString iP ="", double rF =0, unsigned int pN =0, bool hP =false, bool a =false, bool aW =false, bool g =false)
    : RoadVehicle(rT, i, n, k, r, xI, dP, iP, rF, pN, hP), ac(a), autoWind(aW), gps(g) {

}

double Car::getRentAmount() const{
    double tot = 0;
    tot += ((getDailyPrice() - (getKm()/5000)+(getRating()*5) + (getPassengersN()*3) + (getAc() ? 2 : 0) + (getAutoWind() ? 1 : 0))*getRentTime()) + (getExtraInsurance() ? 200 : 0) + (getHighwayPass() ? 50 : 0) + getRoadFee() + (getGps() ? 10 : 0);
    return tot;
}

double Car::getRefundAmount() const {
    double tot = 0;
    tot += (((getDailyPrice() - (getKm()/5000) + (getPassengersN()*0.5))*getRentTime())*0.2) + (getExtraInsurance() ? 20 : 0) + (getHighwayPass() ? 25 : 0) + (getAc() && getAutoWind() && getGps() ? 10 : 0);
    return tot;
}

Car* Car::clone() const {
    return new Car(*this);
}

bool Car::getAc() const{
    return ac;
}

bool Car::getAutoWind() const{
    return autoWind;
}

bool Car::getGps() const{
    return gps;
}

void Car::setAc(bool _ac){
    ac = _ac;
}

void Car::setAutoWind(bool _autoWind){
    autoWind = _autoWind;
}

void Car::setGps(bool _gps){
    gps = _gps;
}
