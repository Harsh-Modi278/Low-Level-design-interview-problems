#include <models/ParkingSpot.h>

class ParkingSpot {
private:
    Vehicle *v = NULL;
    SpotSize spotSize;
    int n;
    bool isAvailable = true;

public:
    ParkingSpot(int n, SpotSize sz) {
        this->spotSize = sz;
        this->n = n;
        this->v = NULL;
    }

    bool IsAvailable() {
        return isAvailable;
    }

    bool ParkVehicle(Vehicle *v) {
        this->v = v;
        isAvailable = false;
        v->parkInSpot(this);
    }
    
    void removeVehicle() {
        this->v = NULL;
        isAvailable = true;
    }
};