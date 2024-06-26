#ifndef _PLAYER_H_
#define _PLAYER_H_

#include "common.hpp"

class Player {
    string name_;
    PlayerType pType_;
public:
    Player(string name, PlayerType pType) : name_(name), pType_(pType) {};
};

#endif //_PLAYER_H_