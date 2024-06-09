#include "models/Vehicle.h"

Vehicle::Vehicle(int regNumber, string color, VehicleType vehicleType) {
    this->regNumber = regNumber;
    this->color = color;
    this->vehicleType = vehicleType;
}

VehicleType Vehicle::getVehicleType() {
    return this->vehicleType;
}

void Vehicle::setParkingTicket(Ticket *ticket){
    this->parkingTicket = ticket;
}