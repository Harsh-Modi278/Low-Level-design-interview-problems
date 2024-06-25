#ifndef _CHECK_BALANCE_STATE_H_
#define _CHECK_BALANCE_STATE_H_

#include "../../models/ATM.hpp"
#include "../../models/BankAccount.hpp"
#include "../../models/Card.hpp"

class CheckBalanceState: public ATMState {
public:
    CheckBalanceState() {
        setStateType(ATMStateType::CHECK_BALANCE);
        cout<<"\nIn "<<ATMStateToNameMapping[getStateType()]<<" state\n";
    }

    //operations
    void insertCard(ATM* atm, Card* card) {
        throw NotImplemented();
    }

    void authenticatePin(ATM* atm, int insertedPin) {
        throw NotImplemented();
    }

    void selectOperation(ATM* atm, OperationTypes opType) {
        throw NotImplemented();
    }

    void withdrawCash(ATM* atm, int amount) {
        throw NotImplemented();
    }

    int checkBalance(ATM* atm) {
        cout<<"\nChecking balance\n";
        int balance = atm->getInsertedCard()->getBankAccount()->getBalance();
        returnCardAndExit(atm);
        return balance;
    }

    void returnCardAndExit(ATM* atm) {
        atm->removeCard();

        cout<<"\nexit\n";
        atm->setState(new IdleState());
    }
};

#endif //_CHECK_BALANCE_STATE_H_