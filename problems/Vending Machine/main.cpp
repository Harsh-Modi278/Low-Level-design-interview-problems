#include "VendingMachine.cpp"

void fillInventory(VendingMachine* vendingMachine) {
    // dummy data

    int code = 101;
    for (int i=1;i<=3;i++) {
        for (int j=1;j<=3;j++) {
            Item* item = new Item(ItemType::CHIPS, 10);
            vendingMachine->getInventory()->addItem(item, code);
        }
    }

    code++;
    for (int i=4;i<=6;i++) {
        for (int j=1;j<=3;j++) {
            Item* item = new Item(ItemType::COKE, 20);
            vendingMachine->getInventory()->addItem(item, code);
        }
    }

    code++;
    for (int i=7;i<=9;i++) {
        for (int j=1;j<=3;j++) {
            Item* item = new Item(ItemType::JUICE, 50);
            vendingMachine->getInventory()->addItem(item, code);
        }
    }

    code++;
    for (int i=7;i<=9;i++) {
        for (int j=1;j<=3;j++) {
            Item* item = new Item(ItemType::PEPSI, 100);
            vendingMachine->getInventory()->addItem(item, code);
        }
    }
}

void displayInventory(VendingMachine* vendingMachine) {
    cout<<"\n--- display inventory ---\n";
    vendingMachine->getInventory()->display();
    cout<<"\n-------------------------\n";

}

void happyFlow(VendingMachine* vendingMachine) {
    cout<<"\n--- happy flow ---\n";
    State* vmState = vendingMachine->getCurrentState();
    vmState->clickOnInsertCointButton(vendingMachine);

    vmState = vendingMachine->getCurrentState();
    vmState->insertCoin(vendingMachine, new Coin(CoinType::QUARTER));

    vmState = vendingMachine->getCurrentState();
    vmState->clickOnStartProductSelectionButton(vendingMachine);

    vmState = vendingMachine->getCurrentState();
    vmState->chooseProduct(vendingMachine, 101);

    displayInventory(vendingMachine);
}

void errorFlow1(VendingMachine* vendingMachine) {
    cout<<"\n------ error flow 1 ---------\n";
    vendingMachine->changeState(new IdleState(vendingMachine));
    State* vmState = vendingMachine->getCurrentState();
    vmState->getChange(1000);
    vmState->clickOnInsertCointButton(vendingMachine);

    vmState = vendingMachine->getCurrentState();
    vmState->insertCoin(vendingMachine, new Coin(CoinType::PENNY));
    vmState->insertCoin(vendingMachine, new Coin(CoinType::NICKLE));
    vmState->insertCoin(vendingMachine, new Coin(CoinType::QUARTER));

    vmState = vendingMachine->getCurrentState();
    vmState->dispenseProduct(vendingMachine, 102);
    vmState->clickOnStartProductSelectionButton(vendingMachine);

    vmState = vendingMachine->getCurrentState();
    vmState->chooseProduct(vendingMachine, 102);
    vmState->refundFullAmount(vendingMachine);

    displayInventory(vendingMachine);
}

void errorFlow2(VendingMachine* vendingMachine) {
    cout<<"\n------ error flow 2 ---------\n";
    vendingMachine->changeState(new IdleState(vendingMachine));
    State* vmState = vendingMachine->getCurrentState();
    vmState->clickOnInsertCointButton(vendingMachine);

    vmState = vendingMachine->getCurrentState();
    vmState->insertCoin(vendingMachine, new Coin(CoinType::DIME));
    cout<<"\nClicked on cancel button\n";
    vmState->refundFullAmount(vendingMachine);

    vmState = vendingMachine->getCurrentState();
    vmState->dispenseProduct(vendingMachine, 102);
    vmState->clickOnStartProductSelectionButton(vendingMachine);

    vmState = vendingMachine->getCurrentState();
    vmState->chooseProduct(vendingMachine, 102);

    displayInventory(vendingMachine);
}

void errorFlow3(VendingMachine* vendingMachine) {
    cout<<"\n------ error flow 3 ---------\n";
    vendingMachine->changeState(new IdleState(vendingMachine));
    State* vmState = vendingMachine->getCurrentState();
    vmState->clickOnInsertCointButton(vendingMachine);

    vmState = vendingMachine->getCurrentState();
    vmState->insertCoin(vendingMachine, new Coin(CoinType::PENNY));

    vmState = vendingMachine->getCurrentState();
    vmState->clickOnStartProductSelectionButton(vendingMachine);

    vmState = vendingMachine->getCurrentState();
    vmState->chooseProduct(vendingMachine, 104);

    displayInventory(vendingMachine);
}
int32_t main() {
    VendingMachine* vendingMachine = new VendingMachine(4); // 4 shelfs
    try {
        fillInventory(vendingMachine);
        displayInventory(vendingMachine);

        // happy path
        happyFlow(vendingMachine);

        // error paths
        // errorFlow1(vendingMachine);
        // errorFlow2(vendingMachine);
        errorFlow3(vendingMachine);
    } catch(const exception& e) {
        cout<<"\nexception: "<<e.what()<<"\n";
        displayInventory(vendingMachine);
    }

    return 0;
}