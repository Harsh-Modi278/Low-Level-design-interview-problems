#ifndef PRODUCT_SELECTION_STATE
#define PRODUCT_SELECTION_STATE

#include "State.h"
#include "IdleState.h"
#include "ProductDispenseState.cpp"

class ProductSelectionState: public State {
    string currenStateName = "product selection state";
public:
    ProductSelectionState() {
        cout<<"\nVending machine is in "<<currenStateName<<"\n";
    }

    void clickOnInsertCointButton(VendingMachine* vendingMachine) {
        throw logic_error("can't click on insert coin button in product selection state");
    };

    void insertCoin(VendingMachine* vendingMachine, Coin* coin) {
        throw logic_error("can't insert coin in product selection state");
    };

    void clickOnStartProductSelectionButton(VendingMachine* vendingMachine) {
        throw logic_error("can't click on start product selection button in product selection state");
    };

    void chooseProduct(VendingMachine* vendingMachine, int itemCode) {
        // get the product from itemCode
        cout<<"\nProduct code entered is "<<itemCode<<"\n";
        int itemPrice = vendingMachine->getInventory()->getItemPrice(itemCode);

        if (itemPrice == -1) {
            throw runtime_error("invalid item code");
        }

        // amount paid by user
        int paidByUser = 0;
        vector<Coin*> coins = vendingMachine->getCoinStorage();
        for (Coin* c: coins) {
            paidByUser += c->getValue();
        }

        if (paidByUser < itemPrice) {
            cout<<"\nInsuffient funds: selected product is of INR "<<itemPrice<<" and you inserted INR "<<paidByUser<<" \n";
            refundFullAmount(vendingMachine);
            throw runtime_error("Insuffient funds");
        } else if (paidByUser >= itemPrice) {
            Item* item = vendingMachine->getInventory()->getItem(itemCode);
            if (paidByUser > itemPrice) {
                getChange(paidByUser-itemPrice);
            }
            vendingMachine->changeState(new ProductDispenseState(vendingMachine, item));
            
            // now call the dispenser method
            vendingMachine->getCurrentState()->dispenseProduct(vendingMachine, itemCode);
        }

    };

    int getChange(int changeAmount) {
        cout<<"\nPlease collect "<<changeAmount<<" from change tray\n";
        return changeAmount;
    };

    Item* dispenseProduct(VendingMachine* vendingMachine, int itemCode) {
        throw logic_error("can't dispense in coin acceptance state");
    }

    vector<Coin*> refundFullAmount(VendingMachine* vendingMachine) {
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

    void updateInventory(VendingMachine* vendingMachine, Item* item, int code) {
        throw logic_error("can't update inventory in product selection state");
    };
};

#endif //PRODUCT_SELECTION_STATE