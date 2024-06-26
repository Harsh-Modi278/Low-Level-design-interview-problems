#include "../common.hpp"

class WeightMachine;

class WeightMachineAdapter {
    WeightMachine* weightMachine_;
public:
    WeightMachineAdapter(WeightMachine* weightMachine) : weightMachine_(weightMachine) {};
    double getWeightInKgs();
};