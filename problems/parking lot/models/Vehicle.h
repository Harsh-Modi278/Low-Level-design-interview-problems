#include "common.h"

#ifndef _VEHICLE_H

#define _VEHICLE_H

class Ticket;

class Vehicle {
    int regNumber;
    string color;
    VehicleType vehicleType;
    Ticket* parkingTicket;
public:
    Vehicle(int, string, VehicleType);
    VehicleType getVehicleType();
    void setParkingTicket(Ticket* ticket); 
};

#endif //_VEHICLE_H