#include "Slot.h"

class Floor {
    int floor;
    int cntSlots;
    vector<Slot*> slots;
public:
    int getFloorNumber();
    int getFreeSlotsCount(VehicleType vehicleType);
    void displayFreeSlots(VehicleType vehicleType);
    void displayOccupiedSlots(VehicleType vehicleType);
    void addSlot(Slot*);
    Slot *findFreeSlot(VehicleType vehicleType);
};