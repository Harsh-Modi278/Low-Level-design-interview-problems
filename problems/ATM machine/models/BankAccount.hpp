#ifndef _BANK_ACC_H_
#define _BANK_ACC_H_
#include "common.hpp"

class BankAccount {
    int accNumber_;
    int balance_;
public:
    BankAccount(int accNumber) : accNumber_(accNumber) {
        balance_ = 0;
    };

    int getBalance() {
        cout<<"\nGetting balance for acc no. "<<accNumber_<<" \n";
        return balance_;
    }

    void setBalance(int newBalance) {
        balance_ = newBalance;
    }
};

#endif //_BANK_ACC_H_