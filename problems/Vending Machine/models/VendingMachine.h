#ifndef _VENDING_MACHINE_H
#define _VENDING_MACHINE_H

#include "../Inventory.cpp"
#include "Coin.h"

class State;

class VendingMachine {
    State* vendingMachineState_;
    Inventory* inventory_;
    vector<Coin*> coinStorage_;
    map<int, int> totalCoinsMap;

public:
    VendingMachine(int inventoryCapacity);

    void setCoinStorage(vector<Coin*> coinStorage);

    void setCoinStorageEmpty();

    void addCoin(Coin* coin);

    void changeState(State* newState);

    vector<Coin*> getCoinStorage();

    Inventory* getInventory();

    State* getCurrentState();
};

#endif //_VENDING_MACHINE_H