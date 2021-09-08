#include "rental.h"

Rental::Rental() {
    lst.push_back(new ShowroomVehicle(0, lst.size(), "BMW R45 CafeRacer", 0, 5, true, 100.00, "//RentalSW//resources//bmwr45.jpg", "", false, 0, false));

    lst.push_back(new Car(0, lst.size(), "Fiat Punto", 0, 3, true, 55.00, "//RentalSW//resources//fiatpunto.jpg", 10, 0, false, false, false, false));

    lst.push_back(new Atv(0, lst.size(), "ATV 250", 500, 2, true, 60.00, "//RentalSW//resources//atv250.jpg", 0, false, false));

    lst.push_back(new RMotorcycle(0, lst.size(), "Aprilia RSV", 1000, 3, true, 35.00, "//RentalSW//resources//apriliarsv.jpg", 5, 1, false, false));

    lst.push_back(new ORMotorcycle(0, lst.size(), "Ktm EXC", 1000, 3, true, 35.00, "//RentalSW//resources//ktmexc.jpg", 0, false, ""));

    lst.push_back(new ShowroomVehicle(0, lst.size(), "Delorean", 0, 2, true, 60.00, "//RentalSW//resources//delorean.jpg", "", true, 0, false));

    lst.push_back(new RMotorcycle(0, lst.size(), "Harley Davidson", 1000, 3, true, 35.00, "//RentalSW//resources//harley.jpg", 15, 1, false, false));

    lst.push_back(new Car(0, lst.size(), "Ford Fiesta", 0, 3, true, 55.00, "//RentalSW//resources//fordfiesta.jpg", 5, 0, false, false, false, false));

    lst.push_back(new Car(0, lst.size(), "Fiat Panda", 0, 3, true, 55.00, "//RentalSW//resources//fiatpanda.jpg", 10, 0, false, false, false, false));

    lst.push_back(new ORMotorcycle(0, lst.size(), "Husqvarna", 1000, 3, true, 35.00, "//RentalSW//resources//husqvarna.jpg", 0, false, ""));

    lst.push_back(new ShowroomVehicle(0, lst.size(), "Triumph Spitfire", 0, 2, true, 60.00, "//RentalSW//resources//triumphspitfire.jpeg", "", true, 0, false));

    lst.push_back(new Atv(0, lst.size(), "ATV 125", 500, 2, true, 60.00, "//RentalSW//resources//atvblue.jpg", 0, false, false));

    lst.push_back(new RMotorcycle(0, lst.size(), "Kawasaki Z500", 1000, 3, true, 35.00, "//RentalSW//resources//kawasakiz500.jpg", 11, 1, false, false));

    lst.push_back(new RMotorcycle(0, lst.size(), "Ducati Monster", 1000, 3, true, 35.00, "//RentalSW//resources//ducatimonster.jpg", 7, 1, false, false));

    lst.push_back(new ShowroomVehicle(0, lst.size(), "Dominator Scrambler", 0, 2, true, 60.00, "//RentalSW//resources//dominatorscrambler.jpg", "", true, 0, false));

}

Container<DeepPtr<RentalObject>>::iterator Rental::getBegin(){
    return lst.begin();
}

Container<DeepPtr<RentalObject>>::iterator Rental::getEnd(){
    return lst.end();
}






