#ifndef _BALL_H_
#define _BALL_H_

#include "common.hpp"
#include "Team.hpp"
#include "Over.hpp"
#include "Player.hpp"

class Wicket;
class ScoreUpdateObserver;

class Ball {
    int ballNumber_;
    BallType ballType_;
    RunType runType_;
    Player* playedBy_;
    Player* bowledBy_;
    Wicket* wicket_;
    vector<ScoreUpdateObserver*> observers_;
public:
    Ball(int, Player*);

    void notify(Ball*);
    void startBallDelivery(Team* battingTeam, Team* bowlingTeam, Over* over);
    
    RunType getRunType() {
        return runType_;
    }

    BallType getBallType() {
        return ballType_;
    }

    Player* getPlayedBy() {
        return playedBy_;
    }

    Player* getBowledBy() {
        return bowledBy_;
    }


    int getBallNumber() {
        return ballNumber_;
    }

    Wicket* getWicket() {
        return wicket_;
    }
};

#endif //_BALL_H_