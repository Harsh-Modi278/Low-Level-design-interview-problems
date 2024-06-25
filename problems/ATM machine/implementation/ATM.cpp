#ifndef _ATM_
#define _ATM_

#include "../models/ATM.hpp"
#include "../models/Card.hpp"
#include "ATMStates/IdleState.cpp"

ATM::ATM() {
    state_ = new IdleState();
    insertedCard_ = nullptr;
}

void ATM::setState(ATMState* newState) {
    state_ = newState;
}

ATMState* ATM::getState() {
    return state_;
}

string ATM::getCurrentStateName() {
    return ATMStateToNameMapping[state_->getStateType()];
}

void ATM::setInsertedCard(Card* card) {
    insertedCard_ = card;
}

Card* ATM::getInsertedCard() {
    return insertedCard_;
}

void ATM::removeCard() {
    cout<<"\nPlease collect your card\n";
    insertedCard_ = nullptr;
}

void ATM::addNotes(CurrencyType cType, int cnt) {
    notes[cType] += cnt;
}

void ATM::removeNotes(CurrencyType cType, int cnt) {
    if (notes.count(cType) && notes[cType] >= cnt) {
        notes[cType] -= cnt;
    } else {
        throw runtime_error("ATM doesn't have enough notes");
    }
}

#endif //_ATM_