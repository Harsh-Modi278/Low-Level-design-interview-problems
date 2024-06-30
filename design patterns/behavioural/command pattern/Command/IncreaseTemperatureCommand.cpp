#include "Command.hpp"
#include "../Receiver/AirConditioner.cpp"

class IncreaseTemperatureCommand: public ICommand {
    AirConditoner* ac_;

public:
    IncreaseTemperatureCommand(AirConditoner* ac) : ac_(ac) {};
    void execute() override {
        int currentTemp = ac_->getTemperature();
        ac_->setTemperature(min(32, 1+currentTemp));
    }
};