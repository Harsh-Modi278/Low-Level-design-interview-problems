#ifndef _CACH_WITHDRAWAL_STATE_
#define _CACH_WITHDRAWAL_STATE_

#include "../../models/ATMStates/ATMState.hpp"
#include "../../models/ATMStates/IdleState.hpp"
#include "../../models/ATM.hpp"

class CachWithdrawalState: public ATMState {
public:
    CachWithdrawalState() {
        setStateType(ATMStateType::CASH_WITHDRAWAL);
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
        // can use a transaction for this update

        //simple implementation
        int moneyInAcc = atm->getInsertedCard()->getBankAccount()->getBalance();
        if (moneyInAcc > amount) {
            cout<<"\nDeducting money from account...\n";
            atm->getInsertedCard()->getBankAccount()->setBalance(moneyInAcc-amount);
            cout<<"\nMoney deducted from account.\n";
            
            moneyInAcc = atm->getInsertedCard()->getBankAccount()->getBalance();
            cout<<"\nCurrent balance: "<<moneyInAcc<<" \n";
        } else {
            cout<<"\nInsufficient funds\n";
        }
        returnCardAndExit(atm);

        // chain of responsibility design pattern impl.
    }

    int checkBalance(ATM* atm) {
        throw NotImplemented();
    }

    void returnCardAndExit(ATM* atm) {
        atm->removeCard();

        cout<<"\nexit\n";
        atm->setState(new IdleState());
    }
};

#endif //_CACH_WITHDRAWAL_STATE_