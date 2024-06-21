#include "Vehicle.h"

class NullVehicle: public Vehicle {
public:

    // 3) null object does nothing or returns default values
    // here we're returning default values
    int getTankCapacity() {
        return 0;
    }
    
    int getSeatCapacity() {
        return 0;
    }
};