#include "models/Parkinglot.h"

class ParkingLot {
    vector<Level *> floors;
    static ParkingLot* instancePtr;

public:
    ParkingLot(vector<Level *> floors) {
        this->floors = floors;
        this->instancePtr = NULL;
    }

    // delete the copy contructor
    ParkingLot (ParkingLot &ParkingLot) = delete;

    static ParkingLot* getInstance(vector<Level *> floors) {
        if (instancePtr == NULL) {
            instancePtr = new ParkingLot(floors);
        }

        return instancePtr;
    }

    void addFloor(int floor, map<SpotSize, vector<ParkingSpot *>> parkingSpots){
        Level* parkingLevel = new Level(floor, parkingSpots);
        this->floors.push_back(parkingLevel);
    }

    void removeFloor(int floorIdx) {
        int cntFloors = floors.size();
        swap(floors[cntFloors-1], floors[floorIdx]);
        floors.pop_back();
    }

    bool ParkVehicle(Vehicle *v) {
        for (Level *l : floors) {
            if (l->ParkVehicle(v))
            {
                break;
            }
        }
    }

    void displayFreeSlots();
};