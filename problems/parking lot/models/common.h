#ifndef _COMMON_H
#define _COMMON_H

#include <iostream>
#include <vector>
#include <string>
using namespace std;

enum VehicleType {
    CAR,
    BIKE,
    TRUCK
};

VehicleType vehicleTypesList[] = {VehicleType::CAR, VehicleType::BIKE, VehicleType::TRUCK};

#endif //_COMMON_H