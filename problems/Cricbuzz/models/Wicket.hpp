#ifndef _WICKET_H_
#define _WICKET_H_

#include "common.hpp"
#include "Ball.hpp"
#include "Over.hpp"

class Wicket {
    WicketType wicketType_;
    Player* takenBy_;
    Over* over_;
    Ball* ball_;
public:
    Wicket(WicketType wicketType, Player* takenBy, Over* over, Ball* ball): wicketType_(wicketType), takenBy_(takenBy), over_(over), ball_(ball) {};
};

#endif //_WICKET_H_