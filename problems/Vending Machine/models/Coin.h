#ifndef _COIN_H_
#define _COIN_H_

#include "common.h"

class Coin {
    int value_;
public:
    Coin(int value) : value_(value) {};
    int getValue() {
        return value_;
    }
};

#endif //_COIN_H_