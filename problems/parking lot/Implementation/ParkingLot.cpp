#include "models/ParkingLot.h"

ParkingLot *ParkingLot::parkingLot_ = nullptr;

ParkingLot* ParkingLot::getParkingLot(int id, int cntfloors, int slotsPerFloor) {
    if (ParkingLot::parkingLot_ == nullptr) {
        ParkingLot::parkingLot_ = new ParkingLot(id, cntfloors, slotsPerFloor);
        cout<<"created parking lot"<<id<<" with"<<cntfloors<<" number of floors and "<<slotsPerFloor<<" slots per floor\n";
    }
    return parkingLot_;
}

void ParkingLot::addFloor(Floor* newFloor) {
    if (newFloor) {
        floors.push_back(newFloor);
    }
}

Slot* ParkingLot::park(Vehicle* vehicle) {
    for (int i=0;i<(int)floors.size();i++) {
        Slot *freeSlot = floors[i]->findFreeSlot(vehicle->getVehicleType());
        if (freeSlot) {
            freeSlot->parkVehicle(vehicle);
        }
    }
}

