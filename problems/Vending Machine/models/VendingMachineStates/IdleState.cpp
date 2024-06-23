#include "IdleState.h"
#include "CoinAcceptanceState.cpp"
#include "models/VendingMachine.h"

void IdleState::clickOnInsertCointButton(VendingMachine* vendingMachine) {
    // clicked on button
    // set machine to Coin Acceptance state
    cout<<"\nClicked on insert coin button\n";
    State* nextState = new CoinAcceptanceState();
    vendingMachine->changeState(nextState);
};

void IdleState::insertCoin(VendingMachine* vendingMachine, Coin coin) {
    throw logic_error("can't insert coin in idle state");
};

void IdleState::clickOnStartProductSelectionButton(VendingMachine* vendingMachine) {
    throw logic_error("can't start product selection in idle state");
};

void IdleState::chooseProduct(VendingMachine* vendingMachine, int itemCode) {
    throw logic_error("can't choose product in idle state");
};

int IdleState::getChange(int changeAmount) {
    throw logic_error("can't get change in idle state");
};

Item* IdleState::dispenseProduct(VendingMachine* vendingMachine, int itemCode) {
    throw logic_error("can't dispense in idle state");
}

vector<Coin*> IdleState::refundFullAmount(VendingMachine* vendingMachine) {
    throw logic_error("can't refund the amount in idle state");
}

void IdleState::updateInventory(VendingMachine* vendingMachine, Item* item, int code) {
    vendingMachine->getInventory()->addItem(item, code);
};
