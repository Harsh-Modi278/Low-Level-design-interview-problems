#ifndef _ATM_STATE_H_
#define _ATM_STATE_H_

#include "../common.hpp"

class ATM;
class Card;

class ATMState {
    ATMStateType stateType_;
public:
    ATMStateType getStateType() {
        return stateType_;
    }

    void setStateType(ATMStateType stateType) {
        stateType_ = stateType;
    }

    //operations
    virtual void insertCard(ATM* atm, Card* card) {
        throw NotImplemented();
    }

    virtual void authenticatePin(ATM* atm, int insertedPin) {
        throw NotImplemented();
    }

    virtual void selectOperation(ATM* atm, OperationTypes opType) {
        throw NotImplemented();
    }

    virtual void withdrawCash(ATM* atm, int amount) {
        throw NotImplemented();
    }

    virtual int checkBalance(ATM* atm) {
        throw NotImplemented();
    }

    virtual void returnCardAndExit(ATM* atm) {
        throw NotImplemented();
    }
};

#endif //_ATM_STATE_H_