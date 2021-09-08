#include "offroadvehicle.h"

OffRoadVehicle::OffRoadVehicle(unsigned int rT = 0, unsigned int i =0, QString n ="null", unsigned int k =0, unsigned int r =0, bool xI =false, double dP =0, QString iP ="", unsigned int tC =0)
    : RentalObject(rT, i, n, k, r, xI, dP, iP), trackCredits(tC) {

}


unsigned int OffRoadVehicle::getTrackCredits() const{
    return trackCredits;
}

void OffRoadVehicle::setTrackCredits(unsigned int _trackCredits){
    trackCredits = _trackCredits;
}
