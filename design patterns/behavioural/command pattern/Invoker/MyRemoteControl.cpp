#include "../Command/TurnOnAcCommand.cpp"
#include "../Command/TurnOffAcCommand.cpp"
#include "../Command/IncreaseTemperatureCommand.cpp"


class MyRemoteControl {
    ICommand* command_;
    stack<ICommand*> acCommandsHistory;
public:
    MyRemoteControl() {}

    void setCommand(ICommand* cmd) {
        command_ = cmd;
    }

    void pressButton() {
        command_->execute();
        acCommandsHistory.push(command_);
    }

    void undo() {
        if (!acCommandsHistory.empty()) {
            ICommand* lastCmd = acCommandsHistory.top();
            acCommandsHistory.pop();

            lastCmd->undo();
        }
    }
};