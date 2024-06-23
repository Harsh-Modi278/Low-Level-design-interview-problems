#include "IdleState.h"
#include "ProductSelectionState.cpp"

#ifndef COIN_ACCEPTANCE_STATE
#define COIN_ACCEPTANCE_STATE

#include "State.h"

class CoinAcceptanceState: public State {
public:
    CoinAcceptanceState() {
        cout<<"\nVending machine is in coin acceptance state\n";
    }

    void clickOnInsertCointButton(VendingMachine* vendingMachine);

    void insertCoin(VendingMachine* vendingMachine, Coin* coin);

    void clickOnStartProductSelectionButton(VendingMachine* vendingMachine);

    void chooseProduct(VendingMachine* vendingMachine, int itemCode);

    int getChange(int changeAmount);

    Item* dispenseProduct(VendingMachine* vendingMachine, int itemCode);

    vector<Coin*> refundFullAmount(VendingMachine* vendingMachine);
    
    void updateInventory(VendingMachine* vendingMachine, Item* item, int code);
};

#endif //COIN_ACCEPTANCE_STATE

void CoinAcceptanceState::clickOnInsertCointButton(VendingMachine* vendingMachine) {
    throw logic_error("can't click on insert coin button in coin acceptance state");
};

void CoinAcceptanceState::insertCoin(VendingMachine* vendingMachine, Coin* coin) {
    cout<<"\nInserted a "<<coin->getValue()<<" Rs coin\n";
    vendingMachine->addCoin(coin);
};

void CoinAcceptanceState::clickOnStartProductSelectionButton(VendingMachine* vendingMachine) {
    // click on product selection button
    // move to next state: Product Selection state
    cout<<"\nClicked on start product selection button\n";
    vendingMachine->changeState(new ProductSelectionState());
};

void CoinAcceptanceState::chooseProduct(VendingMachine* vendingMachine, int itemCode) {
    throw logic_error("can't choose product in coin acceptance state");
};

int CoinAcceptanceState::getChange(int changeAmount) {
    throw logic_error("can't get change in coin acceptance state");
};

Item* CoinAcceptanceState::dispenseProduct(VendingMachine* vendingMachine, int itemCode) {
    throw logic_error("can't dispense in coin acceptance state");
}

vector<Coin*> CoinAcceptanceState::refundFullAmount(VendingMachine* vendingMachine) {
    vector<Coin*> coins = vendingMachine->getCoinStorage();
    
    int refundAmount = 0;
    for (Coin* c: coins) {
        refundAmount += c->getValue();
    }

    cout<<"\n--- starting refund of amount of "<<refundAmount<<" ---\n";
    cout<<"\n please collect coins in change tray: ";
    for (Coin* c: coins) {
        cout<<c->getValue()<<" ";
    }
    cout<<" ---\n";

    // set machine to idle state
    vendingMachine->changeState(new IdleState(vendingMachine));
    return coins;
}

void CoinAcceptanceState::updateInventory(VendingMachine* vendingMachine, Item* item, int code) {
    throw logic_error("can't update inventory in coin acceptance state");
};