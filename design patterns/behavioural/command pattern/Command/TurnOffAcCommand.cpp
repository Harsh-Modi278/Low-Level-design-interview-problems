#include "Command.hpp"
#include "../Receiver/AirConditioner.cpp"

class TurnOffAcCommand: public ICommand {
    AirConditoner* ac_;

public:
    TurnOffAcCommand(AirConditoner* ac) : ac_(ac) {};
    void execute() override {
        ac_->turnOffAc();
    }
    void undo() override {
        ac_->turnOnAc();
    }
};