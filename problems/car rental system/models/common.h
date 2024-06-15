#ifndef _COMMON_H
#define _COMMON_H

#include <iostream>
#include <vector>
#include <string>
using namespace std;

enum VehicleType {
    CAR,
    BIKE
};

enum VehicleStatus {
    ACTIVE,
    INACTIVE
};

enum ReservationStatus {
    SCHEDULED,
    INPROGRESS,
    COMPLETED,
    CANCELLED
};

enum ReservationType {
    HOURLY,
    DAILY
};

VehicleType vehicleTypesList[] = {VehicleType::CAR, VehicleType::BIKE};

#endif //_COMMON_H