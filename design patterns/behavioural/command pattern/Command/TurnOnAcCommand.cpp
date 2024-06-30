#include "Command.hpp"
#include "../Receiver/AirConditioner.cpp"

class TurnOnAcCommand: public ICommand {
    AirConditoner* ac_;

public:
    TurnOnAcCommand(AirConditoner* ac) : ac_(ac) {};
    void execute() override {
        ac_->turnOnAc();
    }
    void undo() override {
        ac_->turnOffAc();
    }
};