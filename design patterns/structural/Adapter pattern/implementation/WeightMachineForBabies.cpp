#include "../models/WeightMachine.hpp"

// concrete class of Adaptee>>
class WeightMachineForBabies: public WeightMachine {
public:
    double getWeightInPounds() {
        return (double)28.00;
    }
};