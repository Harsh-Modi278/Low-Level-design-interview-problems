#include "Level.h"

class ParkingLot
{
    vector<Level *> floors;
    static ParkingLot *instancePtr;

public:
    ParkingLot(vector<Level *> floors);

    // delete the copy contructor
    ParkingLot(ParkingLot &ParkingLot) = delete;

    static ParkingLot *getInstance(vector<Level *> floors);

    void addFloor(int floor, map<SpotSize, vector<ParkingSpot *>> parkingSpots);

    void removeFloor(int floorIdx);

    bool ParkVehicle(Vehicle *v);

    void displayFreeSlots();
};