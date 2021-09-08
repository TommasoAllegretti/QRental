#include "rmotorcycle.h"

RMotorcycle::RMotorcycle(unsigned int rT =0, unsigned int i =0, QString n ="null", unsigned int k =0, unsigned int r =0, bool xI =false, double dP =0, QString iP ="", double rF =0, unsigned int pN =0, bool hP =false, unsigned int nS =0)
    : RoadVehicle(rT, i, n, k, r, xI, dP, iP, rF, pN, hP), nStates(nS) {

}

double RMotorcycle::getRentAmount() const{
    double tot = 0;
    tot += ((getDailyPrice() - (getKm()/5000)+(getRating()*5) + (getPassengersN()*3))*getRentTime()) + (getExtraInsurance() ? 200 : 0) + (getHighwayPass() ? 50 : 0) + getRoadFee() + (getNStates() * 20);
    return tot;
}

double RMotorcycle::getRefundAmount() const {
    double tot = 0;
    tot += (((getDailyPrice() - (getKm()/5000) + (getPassengersN()*0.5))*getRentTime())*0.2) + (getExtraInsurance() ? 20 : 0) + (getHighwayPass() ? 25 : 0) + (getNStates() * 5);
    return tot;
}

RMotorcycle* RMotorcycle::clone() const {
    return new RMotorcycle(*this);
}

unsigned int RMotorcycle::getNStates() const {
    return nStates;
}

void RMotorcycle::setNStates(unsigned int _nStates) {
    nStates = _nStates;
}
