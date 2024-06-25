#ifndef _HAS_CARD_STATE_
#define _HAS_CARD_STATE_

#include "../../models/ATMStates/ATMState.hpp"
#include "../../models/ATMStates/IdleState.hpp"
#include "../../models/ATM.hpp"
#include "./OperationSelectionState.cpp"

class HasCardState: public ATMState {
public:
    HasCardState() {
        setStateType(ATMStateType::HAS_CARD);
        cout<<"\nIn "<<ATMStateToNameMapping[getStateType()]<<" state\n";
    }

    //operations
    void insertCard(ATM* atm, Card* card) {
        throw NotImplemented();
    }

    void authenticatePin(ATM* atm, int insertedPin) {
        cout<<"\nAuthenticating pin...\n";
        bool isPinCorrect = atm->getInsertedCard()->authenticatePin(insertedPin);
        if (isPinCorrect) {
            atm->setState(new OperationSelectionState());
        } else {
            cout<<"\nIncorrect pin entered\n";
            returnCardAndExit(atm);
        }
    }

    void selectOperation(ATM* atm, OperationTypes opType) {
        throw NotImplemented();
    }

    void withdrawCash(ATM* atm, int amount) {
        throw NotImplemented();
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

#endif //_HAS_CARD_STATE_