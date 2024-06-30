#include "common.hpp"
#include "Receiver/AirConditioner.cpp"
#include "Invoker/MyRemoteControl.cpp"

int32_t main() {
    // ac - receiver
    AirConditoner* ac = new AirConditoner();

    //remote - invoker
    MyRemoteControl* remote = new MyRemoteControl();

    //turn ac on - command
    ICommand* turnAcOnCmd = new TurnOnAcCommand(ac);
    remote->setCommand(turnAcOnCmd);

    remote->pressButton();
    remote->undo();
    return 0;
}