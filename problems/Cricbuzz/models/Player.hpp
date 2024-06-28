#ifndef _PLAYER_H_
#define _PLAYER_H_

#include "Person.hpp"
#include "BattingScoreCard.hpp"
#include "BowlingScorecard.hpp"

class Player {
    Person* person_;
    PlayerType pType_;
    BattingScorecard* battingSc;
    BowlingScorecard* bowlingSc;
public:
    Player(Person* person, PlayerType playerType) : person_(person), pType_(playerType) {};

    BattingScorecard* getBattingScorecard() {
        return battingSc;
    }

    BowlingScorecard* getBowlingScorecard() {
        return bowlingSc;
    }
};

#endif //_PLAYER_H_