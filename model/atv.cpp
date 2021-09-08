#include "atv.h"

Atv::Atv(unsigned int rT =0, unsigned int i =0, QString n ="null", unsigned int k =0, unsigned int r =0, bool xI =false, double dP =0, QString iP ="", unsigned int tC =0, bool cS =false, bool cT =false)
    : OffRoadVehicle(rT, i, n, k, r, xI, dP, iP, tC), cleaningServ(cS), changeTires(cT) {

}

double Atv::getRentAmount() const {
    double tot = 0;
    tot += ((getDailyPrice() - (getKm()/5000)+(getRating()*5)+(getCleaningServ() ? 10 : 0))*getRentTime()) + (getExtraInsurance() ? 200 : 0) + (getChangeTires() ? 50 : 0) + (getTrackCredits()*15);
    return tot;
}

double Atv::getRefundAmount() const {
    double tot = 0;
    tot += (((getDailyPrice() - (getKm()/5000))*getRentTime())*0.2) + (getExtraInsurance() ? 20 : 0) + (getChangeTires() ? 10 : 0) + (getTrackCredits()*5);
    return tot;
}

Atv* Atv::clone() const {
    return new Atv(*this);
}


bool Atv::getCleaningServ() const{
    return cleaningServ;
}

bool Atv::getChangeTires() const{
    return changeTires;
}


void Atv::setCleaningServ(bool _cleaningServ){
    cleaningServ = _cleaningServ;
}

void Atv::setChangeTires(bool _changeTires){
    changeTires = _changeTires;
}
