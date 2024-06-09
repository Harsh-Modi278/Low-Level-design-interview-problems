#include "models/Floor.h"

int Floor::getFloorNumber() {
    return this->floor;
}

int Floor::getFreeSlotsCount(VehicleType vehicleType) {
    int cntFreeSlots = 0;
    for (int i=0;i<(int)slots.size();i++) {
        if (slots[i]->getParkedVehicle()->getVehicleType() != vehicleType) continue;
        cntFreeSlots += (slots[i]->isSlotAvailable());
    }

    return cntFreeSlots;
}

void Floor::displayFreeSlots(VehicleType vehicleType) {
    cout<<"free slots on floor:"<<this->getFloorNumber()<<"\n";
    for (int i = 0; i < (int)slots.size(); i++) {
        if (!slots[i]->isSlotAvailable() || slots[i]->getParkedVehicle()->getVehicleType() != vehicleType)
            continue;
        cout<<slots[i]->getSlotNumber()<<" ";
    }
    cout<<"\n";
}

void Floor::displayOccupiedSlots(VehicleType vehicleType) {
    cout << "displayOccupiedSlots: \n";
    for (int i = 0; i < (int)slots.size(); i++) {
        if (slots[i]->isSlotAvailable() || slots[i]->getParkedVehicle()->getVehicleType() != vehicleType)
            continue;
        cout << slots[i]->getSlotNumber() << " ";
    }
    cout << "\n";
}

void Floor::addSlot(Slot* newSlot) {
    if (newSlot) {
        slots.push_back(newSlot);
    }
}

Slot *Floor::findFreeSlot(VehicleType vehicleType)
{
    for (int i = 0; i < (int)slots.size(); i++) {
        if (slots[i]->isSlotAvailable()) {
            return slots[i];
        }
    }

    return NULL;
}