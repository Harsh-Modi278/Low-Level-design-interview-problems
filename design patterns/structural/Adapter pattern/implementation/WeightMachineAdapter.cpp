#include "../models/WeightMachineAdapter.hpp"
#include "WeightMachineForBabies.cpp"

double WeightMachineAdapter::getWeightInKgs(){
    double weightInPounds = weightMachine_->getWeightInPounds();

    //convert to kgs
    double weightInKgs = weightInPounds * (double)0.45;
    return weightInKgs;
}