#ifndef _PLAYER_H
#define _PLAYER_H

#include "models/common.h"
#include "Dice.cpp"

class Player
{
    int prevPos, currPos;
    Dice *dice;

public:
    string name;
    Player(string name)
    {
        this->name = name;
        prevPos = 0;
        currPos = 0;
    }

    void rollDiceAndMove();
    void move(int nextPos, int diceValue);
    bool hasWon(int winningPosition);
};

#endif // _PLAYER_H

void Player::rollDiceAndMove() {
    int val = this->dice->roll();
    this->move(this->currPos+val, val);
}

void Player::move(int nextPos, int diceValue) {
    prevPos = currPos;
    currPos = min(nextPos, MAX_CELLS);
    cout<<this->name<<" rolled a "<<diceValue<<" and moved from "<<prevPos<<" to "<<nextPos<<"\n";
}

bool Player::hasWon(int winningPos) {
    return currPos == winningPos;
}