#include "models/VendingMachine.h"
#include "models/VendingMachineStates/IdleState.cpp"

VendingMachine::VendingMachine(int inventoryCapacity) {
    // set to idle state
    vendingMachineState_ = new IdleState();

    // init inventory
    inventory_ = new Inventory(inventoryCapacity);
    
    // init empty coin storage
    coinStorage_.clear();

    // empty the map which stores final result
    totalCoinsMap.clear();
}

void VendingMachine::setCoinStorage(vector<Coin*> coinStorage) {        
    coinStorage_ = coinStorage;
}

void VendingMachine::setCoinStorageEmpty() {
    // before emptying the vector, populate the map for final result
    for (Coin* c: coinStorage_) {
        totalCoinsMap[c->getValue()]++;
    }
    coinStorage_.clear();
}

void VendingMachine::addCoin(Coin* coin) {
    coinStorage_.push_back(coin);
}

void VendingMachine::changeState(State* newState) {
    vendingMachineState_ = newState;
}

vector<Coin*> VendingMachine::getCoinStorage() {
    return coinStorage_;
}

Inventory* VendingMachine::getInventory() {
    return inventory_;
}

State* VendingMachine::getCurrentState() {
    return vendingMachineState_;
}