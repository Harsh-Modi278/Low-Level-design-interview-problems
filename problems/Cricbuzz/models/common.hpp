#ifndef _COMMON_H_
#define _COMMON_H_

#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <deque>
#include <map>
using namespace std;

enum PlayerType {
    BATTER,
    BOWLER,
    WICKET_KEEPER,
    ALL_ROUNDER,
    CAPTAIN
};

enum MatchType {
    T20,
    ONE_DAY,
    TEST
};

enum BallType {
    NORMAL,
    DOT,
    WIDE,
    NO_BALL,
    WICKET
};

enum RunType {
    ZERO,
    SINGLE,
    DOUBLE,
    THREE,
    FOUR,
    SIX
};

enum WicketType {
    BOWLED,
    CAUGHT,
    RUN_OUT,
    LBW
};

#endif //_COMMON_H_