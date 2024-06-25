#include "common.hpp"
class BankAccount;
class Card;

class User {
    string name_;
    Card* card_;
    BankAccount* bankAcc_;
public: 
    User(string name): name_(name) {};
    void setBankAccount(BankAccount* bankAcc) {
        bankAcc_ = bankAcc;
    }

    BankAccount* getBankAccount() {
        return bankAcc_;
    }

    void setName(string name) {
        name_ = name;
    }

    string getName() {
        return name_;
    }

    void setCard(Card* card) {
        card_ = card;
    }

    Card* getCard() {
        return card_;
    }
};