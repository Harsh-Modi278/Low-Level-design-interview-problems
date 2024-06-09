#include <iostream>
#include <vector>
#include "ParkingSpot.h"
#include <map>
using namespace std;

class Level
{
private:
    int floor;
    vector<ParkingSpot *> spots;
    map<SpotSize, vector<ParkingSpot *>> parkingSpots;

public:
    Level(int f, map<SpotSize, vector<ParkingSpot *>> parkingSpots);

    void spotFreed(SpotSize size);

    bool ParkVehicle(Vehicle *v);

    SpotSize pickCorrectSlotForVehicleCategory(VehicleCategory category);

    void AvailableParkingSpotsOfGivenSize(SpotSize sz, vector<ParkingSpot *> &availableParkingSpots);

    void displayAvailableSlots();
};