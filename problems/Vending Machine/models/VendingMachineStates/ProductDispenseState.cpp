#ifndef PRODUCT_DISPENSE_STATE
#define PRODUCT_DISPENSE_STATE

#include "State.h"
#include "IdleState.h"

class ProductDispenseState: public State {
    string currenStateName = "product dispense state";
    Item* itemToBeDispensed_;
    VendingMachine* vendingMachine_;

public:
    ProductDispenseState(VendingMachine* vendingMachine, Item* productToBeDispensed) {
        cout<<"\nVending machine is in "<<currenStateName<<"\n";
        itemToBeDispensed_ = productToBeDispensed;
        vendingMachine_ = vendingMachine;
    }

    void clickOnInsertCointButton(VendingMachine* vendingMachine) {
        throw logic_error("can't click on insert coin button in product dispense state");
    };

    void insertCoin(VendingMachine* vendingMachine, Coin* coin) {
        throw logic_error("can't insert coin in product dispense state");
    };

    void clickOnStartProductSelectionButton(VendingMachine* vendingMachine) {
        throw logic_error("can't click on start product selection button in product dispense state");
    };

    void chooseProduct(VendingMachine* vendingMachine, int itemCode) {
        throw logic_error("can't choose product in product dispense state");
    };

    int getChange(int changeAmount) {
        throw logic_error("can't get change in product dispense state");
    };

    Item* dispenseProduct(VendingMachine* vendingMachine, int code) {
        cout<<"\nDispensing item: "<<itemToBeDispensed_->getItemType()<<" with item code: "<<code<<"\n";
        return itemToBeDispensed_;
    }

    vector<Coin*> refundFullAmount(VendingMachine* vendingMachine) {
        throw logic_error("can't get refund in product dispense state");
    }

    void updateInventory(VendingMachine* vendingMachine, Item* item, int code) {
        throw logic_error("can't update inventory in product dispense state");
    };
};

#endif //PRODUCT_DISPENSE_STATE