#ifndef _VEHICLE_H
#define _VEHICLE_H

#include "common.h"

class Vehicle
{
    int id_;
    int vehicleNumber_;
    VehicleType vehicleType_;
    string company_;
    string model_;
    int average_;
    int dailyRentalCost_;
    int hourlyRentalCost_;
    int noOfSeats_;
    VehicleStatus vehicleStatus_;
public:
    Vehicle(
        int id,
        int vehicleNumber,
        VehicleType vehicleType,
        string company,
        string model,
        int average,
        int dailyRentalCost,
        int hourlyRentalCost,
        int noOfSeats,
        VehicleStatus vehicleStatus) : id_(id),
                                       vehicleNumber_(vehicleNumber),
                                       vehicleType_(vehicleType),
                                       company_(company),
                                       model_(model),
                                       average_(average),
                                       dailyRentalCost_(dailyRentalCost),
                                       hourlyRentalCost_(hourlyRentalCost),
                                       noOfSeats_(noOfSeats),
                                       vehicleStatus_(vehicleStatus) {};

    bool isAvailable() {
        return this->vehicleStatus_ == VehicleStatus::ACTIVE;
    }

    VehicleType getVehicleType() {
        return this->vehicleType_;
    }
};

#endif //_VEHICLE_H