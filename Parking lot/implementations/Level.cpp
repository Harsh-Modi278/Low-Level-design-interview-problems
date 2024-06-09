#include "models/Level.h"

class Level {
private:
    int floor;
    vector<ParkingSpot *> spots;
    map<SpotSize, vector<ParkingSpot*> > parkingSpots;

public:
    Level(int f, map<SpotSize, vector<ParkingSpot *>> parkingSpots) {
        this->floor = f;
        this->parkingSpots = parkingSpots;
    }

    void spotFreed(SpotSize size) {
        
    }
    
    bool ParkVehicle(Vehicle *v) {
        VehicleCategory category = v->getCategory();
        SpotSize spotSize = pickCorrectSlotForVehicleCategory(category);
        vector<ParkingSpot *> relevantParkingSpots = parkingSpots[spotSize];

        ParkingSpot* takeSpot = NULL;
        for (ParkingSpot* spot:relevantParkingSpots) {
            if (spot->IsAvailable()) {
                spot->ParkVehicle(v);
                takeSpot = spot;
                break;
            }
        }
    }

    SpotSize pickCorrectSlotForVehicleCategory(VehicleCategory category) {
        if (category == TwoWheeler) {
            return twoWheeler;
        }
        if (category == Hatchback || category == Sedan) {
            return small;
        }
        if (category == SUV) {
            return medium;
        }
        if (category == Bus) {
            return large;
        }
    }

    void AvailableParkingSpotsOfGivenSize(SpotSize sz, vector<ParkingSpot *> &availableParkingSpots) {
        for (ParkingSpot *spot : parkingSpots[sz]) {
            if (spot->IsAvailable())
            {
                availableParkingSpots.push_back(spot);
            }
        }

        return;
    }

    void displayAvailableSlots() {
        vector<ParkingSpot *> availableParkingSpots;

        AvailableParkingSpotsOfGivenSize(twoWheeler, availableParkingSpots);
        AvailableParkingSpotsOfGivenSize(small, availableParkingSpots);
        AvailableParkingSpotsOfGivenSize(medium, availableParkingSpots);
        AvailableParkingSpotsOfGivenSize(large, availableParkingSpots);
    }
};