#include "models/common.h"
#include "models/Car.h"
#include "models/NullVehicle.h"

void printVehicleDetails(Vehicle* v) {
    // 2) now we don't need to have null check here
    cout<<"tank capacity: "<<v->getTankCapacity()<<" \n";
    cout<<"seat capacity: "<<v->getSeatCapacity()<<" \n";
}

int32_t main() {
    Vehicle* car = new Car();

    // business logic
    // 1) instead of assigning nullptr we assign a NullObject which inherits from the same base class (Vehicle here)
    Vehicle* v = new NullVehicle();

    printVehicleDetails(car);
    printVehicleDetails(v);
    return 0;
}