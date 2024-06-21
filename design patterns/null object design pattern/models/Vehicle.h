#ifndef _VEHICLE_H
#define _VEHICLE_H

#include "common.h"

class Vehicle {
public:
    virtual int getTankCapacity() = 0;
    virtual int getSeatCapacity() = 0;
};

#endif //_VEHICLE_H