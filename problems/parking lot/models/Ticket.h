#ifndef _TICKET_H
#define _TICKET_H

#include "common.h"

class Slot;

class Ticket {
    string ticketId;
    Slot* slot;
public:
    Ticket(string, Slot *);
    static string generateTicket(int floorNumber, int slotNumber);
};

#endif //_TICKET_H