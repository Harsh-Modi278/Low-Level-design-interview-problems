#ifndef _IDLE_STATE_
#define _IDLE_STATE_

#include "../../models/ATMStates/IdleState.hpp"
#include "./HasCardState.cpp"
#include "implementation/ATM.cpp"
#include "models/Card.hpp"

//operations
void IdleState::insertCard(ATM* atm, Card* card) {
    if (atm->getInsertedCard() == nullptr) {
        cout<<"\nInserted card with number: "<<card->getCardNumber()<<" \n";
        atm->setInsertedCard(card);
        atm->setState(new HasCardState());
    } else {
        cout<<"\nCard already present in ATM, can't insert a new card\n";
    }
}

void IdleState::authenticatePin(ATM* atm, int insertedPin) {
    throw NotImplemented();
}

void IdleState::selectOperation(ATM* atm, OperationTypes opType) {
    throw NotImplemented();
}

void IdleState::withdrawCash(ATM* atm, int amount) {
    throw NotImplemented();
}

int IdleState::checkBalance(ATM* atm) {
    throw NotImplemented();
}

void IdleState::returnCardAndExit(ATM* atm) {
    throw NotImplemented();
}

#endif //_IDLE_STATE_