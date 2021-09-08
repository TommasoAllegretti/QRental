#include "roadvehicle.h"

RoadVehicle::RoadVehicle(unsigned int rT =0, unsigned int i =0, QString n ="null", unsigned int k =0, unsigned int r =0, bool xI =false, double dP =0, QString iP ="", double rF =0, unsigned int pN =0, bool hP =false)
    : RentalObject(rT, i, n, k, r, xI, dP, iP), roadFee(rF), passengersN(pN), highwayPass(hP) {

}

double RoadVehicle::getRoadFee() const{
    return roadFee;
}

unsigned int RoadVehicle::getPassengersN() const{
    return passengersN;
}

bool RoadVehicle::getHighwayPass() const{
    return highwayPass;
}


void RoadVehicle::setPassengerN(unsigned int _passengersN){
    passengersN = _passengersN;
}

void RoadVehicle::setHighwayPass(bool _highwayPass){
    highwayPass = _highwayPass;
}
