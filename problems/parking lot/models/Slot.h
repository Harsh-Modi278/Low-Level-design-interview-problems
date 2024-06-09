
#include "Ticket.h"
#include "Vehicle.h"

#ifndef _SLOT_H

#define _SLOT_H
class Slot {
    int slotNumber;
    Vehicle* parkedVehicle;
    VehicleType slotType;
    bool isAvailable;
    int floor;
public:
    Slot(int slotNumber, VehicleType slotType, int floor);
    int getSlotNumber();
    VehicleType getSlotType();
    Vehicle* getParkedVehicle();
    bool isSlotAvailable();
    int getFloor();

    void parkVehicle(Vehicle* vehicle);
};
#endif //_SLOT_H