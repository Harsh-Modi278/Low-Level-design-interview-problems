#ifndef _OPERATION_SELECTION_STATE_
#define _OPERATION_SELECTION_STATE_

#include "../../models/ATMStates/ATMState.hpp"
#include "../../models/ATMStates/IdleState.hpp"
#include "../../models/ATM.hpp"
#include "./CheckBalanceState.cpp"
#include "./CashWithdrawalState.cpp"

class OperationSelectionState: public ATMState {
public:
    OperationSelectionState() {
        setStateType(ATMStateType::OPERATION_SELECTION);
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
        if (opType == OperationTypes::CHECK__BALANCE) {
            cout<<"\nCheck Balance operation selected\n";
            atm->setState(new CheckBalanceState());
        } else if (opType == OperationTypes::CASH__WITHDRAWAL) {
            cout<<"\nCash withdrawal operation selected\n";
            atm->setState(new CachWithdrawalState());
        } else {
            cout<<"\nInvalid operation selected\n";
            returnCardAndExit(atm);
        }
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

#endif //_OPERATION_SELECTION_STATE_