#ifndef _ATM_H_
#define _ATM_H_

#include "common.hpp"

class ATMState;
class Card;

class ATM {
    ATMState* state_;
    Card* insertedCard_;
    map<CurrencyType, int> notes;

public:
    ATM();

    void setState(ATMState* newState);

    ATMState* getState();

    string getCurrentStateName();

    void setInsertedCard(Card* card);

    Card* getInsertedCard();

    void removeCard();

    void addNotes(CurrencyType cType, int cnt);

    void removeNotes(CurrencyType cType, int cnt);
};

#endif //_ATM_H_