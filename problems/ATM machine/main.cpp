#include "implementation/ATM.cpp"
#include "models/User.hpp"
#include "models/BankAccount.hpp"
#include "models/Card.hpp"

void initUserMock(User* &user, Card* &card, BankAccount* &bankAcc) {
    // dummy bank acc
    bankAcc = new BankAccount(1);
    bankAcc->setBalance(400);

    // dummy card
    card = new Card(101, 666, bankAcc);
    card->setPin(1080);
    
    //dummy user
    user = new User("Harsh");
    user->setName("Harsh");
    user->setCard(card);
    user->setBankAccount(bankAcc);
}

void initATMMock(ATM* &atm) {
    atm = new ATM();

    atm->addNotes(CurrencyType::TWO_THOUSAND, 2);
    atm->addNotes(CurrencyType::FIVE_HUNDRED, 5);
    atm->addNotes(CurrencyType::HUNDRED, 6);
}

void happyFlow1(User* user, ATM* atm) {
    Card* card = user->getCard();
    
    ATMState* atmState = atm->getState();
    atmState->insertCard(atm, card);

    atmState = atm->getState();
    atmState->authenticatePin(atm, 1080);

    atmState = atm->getState();
    atmState->selectOperation(atm, OperationTypes::CHECK__BALANCE);

    atmState = atm->getState();
    int balance = atmState->checkBalance(atm);
    cout<<"Balance in acc is: "<<balance<<" \n";
}

void happyFlow2(User* user, ATM* atm) {
    Card* card = user->getCard();
    
    ATMState* atmState = atm->getState();
    atmState->insertCard(atm, card);

    atmState = atm->getState();
    atmState->authenticatePin(atm, 1080);

    atmState = atm->getState();
    atmState->selectOperation(atm, OperationTypes::CASH__WITHDRAWAL);

    atmState = atm->getState();
    atmState->withdrawCash(atm, 200);
}

int32_t main() {

    try{
        User* user = nullptr;
        Card* card = nullptr;
        BankAccount* bankAcc = nullptr;

        initUserMock(user, card, bankAcc);

        ATM* atm;
        initATMMock(atm);

        happyFlow1(user, atm);
        // happyFlow2(user, atm);

    } catch(exception& ex) {
        cout<<"ex: "<<ex.what()<<"\n";
    }

    
    return 0;
}