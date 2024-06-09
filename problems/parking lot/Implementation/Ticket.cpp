#include "models/Ticket.h"
#include "models/common.h"

string Ticket::generateTicket(int floorNumber, int slotNumber) {
    return "PR1234" + to_string(floorNumber) + to_string(slotNumber);
}

Ticket::Ticket(string ticketId, Slot* slot) {
    this->ticketId = ticketId;
    this->slot = slot;
}