#ifndef IDLE_STATE
#define IDLE_STATE

#include "State.h"

class IdleState: public State {
public:
    IdleState() {
        cout<<"\nVending machine is in idle state\n";
    }

    IdleState(VendingMachine* vendingMachine) {
        cout<<"\nVending machine is in idle state\n";
        vendingMachine->setCoinStorageEmpty();
    }

    void clickOnInsertCointButton(VendingMachine* vendingMachine);

    void insertCoin(VendingMachine* vendingMachine, Coin coin);

    void clickOnStartProductSelectionButton(VendingMachine* vendingMachine);

    void chooseProduct(VendingMachine* vendingMachine, int itemCode);

    int getChange(int changeAmount);

    Item* dispenseProduct(VendingMachine* vendingMachine, int itemCode);

    vector<Coin*> refundFullAmount(VendingMachine* vendingMachine);

    void updateInventory(VendingMachine* vendingMachine, Item* item, int code);
};

#endif //IDLE_STATE