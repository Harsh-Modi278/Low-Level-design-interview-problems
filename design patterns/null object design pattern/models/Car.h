#include "Vehicle.h"

class Car: public Vehicle {
public:
    int getTankCapacity() {
        return 40;
    }

    int getSeatCapacity() {
        return 7;
    }
};