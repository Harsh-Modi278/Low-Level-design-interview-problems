#ifndef _IDLE_STATE_H_
#define _IDLE_STATE_H_

#include "./ATMState.hpp"
class ATM;

class IdleState: public ATMState {
public:
    IdleState() {
        setStateType(ATMStateType::IDLE);
        cout<<"\nIn "<<ATMStateToNameMapping[getStateType()]<<" state\n";
    }

    void insertCard(ATM* atm, Card* card);

    void authenticatePin(ATM* atm, int insertedPin);

    void selectOperation(ATM* atm, OperationTypes opType);

    void withdrawCash(ATM* atm, int amount);

    int checkBalance(ATM* atm);

    void returnCardAndExit(ATM* atm);
};

#endif //_IDLE_STATE_H_