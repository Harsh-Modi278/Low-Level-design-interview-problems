#ifndef _CARD_H_
#define _CARD_H_
#include "common.hpp"
class BankAccount;

class Card {
    int cardNumber_;
    int pin_;
    int cvv_;
    BankAccount* bankAcc_;
public:
    Card(int cardNumber, int cvv, BankAccount* bankAcc): cardNumber_(cardNumber), cvv_(cvv), bankAcc_(bankAcc) {
        pin_ = -1;
    }

    void setPin(int newPin) {
        pin_ = newPin;
    }

    bool authenticatePin(int insertedPin) {
        return pin_ != -1 && insertedPin == pin_;
    }

    int getCardNumber() {
        return cardNumber_;
    }

    BankAccount* getBankAccount() {
        return bankAcc_;
    }
};

#endif //_CARD_H_