#include "models/Slot.h"

Slot::Slot(int slotNumber, VehicleType slotType, int floor) {
    this->slotNumber = slotNumber;
    this->slotType = slotType;
    this->floor = floor;
    this->isAvailable = false;
    this->parkedVehicle = NULL;
}

int Slot::getSlotNumber() {
    return this->slotNumber;
}

VehicleType Slot::getSlotType() {
    return this->slotType;
}

Vehicle* Slot::getParkedVehicle() {
    return this->parkedVehicle;
}

bool Slot::isSlotAvailable() {
    return this->isAvailable;
}

int Slot::getFloor() {
    return this->floor;
}

void Slot::parkVehicle(Vehicle *vehicle)
{
    if (isAvailable)
    {
        if (vehicle->getVehicleType() == slotType)
        {
            string newTicketId = Ticket::generateTicket(this->floor->getFloorNumber(), this->slotNumber);
            Ticket* ticket = new Ticket(newTicketId, slot);
            parkedVehicle = vehicle;
            vehicle->parkingTicket = ticket;
            isAvailable = false;
        }
        else
        {
            cout << "invalid vehicle type for slot\n";
        }
    }
    else
    {
        cout << "slot: " << slotNumber << "on floor" << floor << "is not available\n";
    }
}