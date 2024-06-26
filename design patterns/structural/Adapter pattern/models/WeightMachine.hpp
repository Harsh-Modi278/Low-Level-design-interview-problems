#ifndef _WEIGHT_MACHINE_H_
#define _WEIGHT_MACHINE_H_

#include "../common.hpp"

// Adaptee interface or existing interface
class WeightMachine {
public:
    virtual double getWeightInPounds() = 0;
};

#endif //_WEIGHT_MACHINE_H_