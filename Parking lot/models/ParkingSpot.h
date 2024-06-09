#include <Vehicle.h>
class Level;

enum SpotSize
{
    twoWheeler,
    small,
    medium,
    large
};

class ParkingSpot
{
private:
    Vehicle *v = NULL;
    SpotSize spotSize;
    int spotNbr;
    Level *l;
    int n;
    bool isAvailable = true;

public:
    ParkingSpot(int n, SpotSize sz);

    bool IsAvailable();

    bool ParkVehicle(Vehicle *v);

    void removeVehicle();
};