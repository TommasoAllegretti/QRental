#include "ormotorcycle.h"

ORMotorcycle::ORMotorcycle(unsigned int rT =0, unsigned int i =0, QString n ="null", unsigned int k =0, unsigned int r =0, bool xI =false, double dP =0, QString iP ="", unsigned int tC =0, bool pI =false, QString rN ="")
    : OffRoadVehicle(rT, i, n, k, r, xI, dP, iP, tC), prevInjuries(pI), raceName(rN) {

}

double ORMotorcycle::getRentAmount() const{
    double tot = 0;
    tot += ((getDailyPrice() - (getKm()/5000)+(getRating()*5))*getRentTime()) + (getExtraInsurance() ? 200 : 0) + (getTrackCredits()*15) + (getPrevInjuries() ? 50 : 0);
    return tot;
}

double ORMotorcycle::getRefundAmount() const {
    double tot = 0;
    tot += (((getDailyPrice() - (getKm()/5000))*getRentTime())*0.2) + (getExtraInsurance() ? 20 : 0) + (getTrackCredits()*5);
    return tot;
}

ORMotorcycle* ORMotorcycle::clone() const {
    return new ORMotorcycle(*this);
}


bool ORMotorcycle::getPrevInjuries() const{
    return prevInjuries;
}

QString ORMotorcycle::getRaceName() const{
    return raceName;
}

void ORMotorcycle::setPrevInjuries(bool _prevInjuries){
    prevInjuries = _prevInjuries;
}

void ORMotorcycle::setRaceName(QString _raceName) {
    raceName = _raceName;
}
