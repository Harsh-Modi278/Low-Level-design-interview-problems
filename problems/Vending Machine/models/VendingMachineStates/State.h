#ifndef _STATE_H_
#define _STATE_H_

#include "../Item.h"
#include "../VendingMachine.h"

class State {
public:
    virtual void clickOnInsertCointButton(VendingMachine* vendingMachine) {
        throw new NotImplemented();
    };

    virtual void insertCoin(VendingMachine* vendingMachine, Coin* coin) {
        throw new NotImplemented();
    };

    virtual void clickOnStartProductSelectionButton(VendingMachine* vendingMachine) {
        throw new NotImplemented();
    };

    virtual void chooseProduct(VendingMachine* vendingMachine, int itemCode) {
        throw new NotImplemented();
    };

    virtual int getChange(int changeAmount) {
        throw new NotImplemented();
    };

    virtual Item* dispenseProduct(VendingMachine* vendingMachine, int itemCode) {
        throw new NotImplemented();
    }

    virtual vector<Coin*> refundFullAmount(VendingMachine* vendingMachine) {
        throw new NotImplemented();
    }

    virtual void updateInventory(VendingMachine* vendingMachine, Item* item, int code) {
        throw new NotImplemented();
    };
};

#endif //_STATE_H_