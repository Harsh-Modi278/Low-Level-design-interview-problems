#include "../models/Wicket.hpp"
#include "../models/Over.hpp"
#include "../models/Team.hpp"
#include "../models/Ball.hpp"
#include "../models/Player.hpp"
#include "BattingScoreUpdateObserver.cpp"
#include "BowlingScoreUpdateObserver.cpp"

Ball::Ball(int ballNumber, Player* bowledBy): ballNumber_(ballNumber), bowledBy_(bowledBy) {
    observers_.push_back(new BattingScoreUpdateObserver());
    observers_.push_back(new BowlingScoreUpdateObserver());
};

bool isWicketTaken() {
    if (rand() <= 0.2) {
        return true;
    }

    return false;
}

RunType getRandomRunType() {
    double val = rand();

    if (val <= 0.2) {
        return RunType::SINGLE;
    } else if (val > 0.2 && val <= 0.4) {
        return RunType::DOUBLE;
    } else if (val > 0.4 && val <= 0.6) {
        return RunType::FOUR;
    } else if (val > 0.6 && val <= 0.8) {
        return RunType::SIX;
    } else {
        return RunType::THREE;
    }
}

void Ball::startBallDelivery(Team* battingTeam, Team* bowlingTeam, Over* over) {
    Player* playedBy = battingTeam->getStriker();

    // assuming
    ballType_ = BallType::NORMAL;

    //wicket or not?
    if (isWicketTaken()) {
        runType_ = RunType::ZERO;
        wicket_ = new Wicket(WicketType::LBW, bowledBy_, over, this);
        battingTeam->setStriker(nullptr);
    } else {
        runType_ = getRandomRunType();

        if (runType_ == RunType::SINGLE || runType_ == RunType::THREE) {
            Player* temp = battingTeam->getStriker();
            battingTeam->setStriker(battingTeam->getNonStriker());
            battingTeam->setNonStriker(temp);
        }
    }

    notify(this);
}

void Ball::notify(Ball* ballDetails) {
    for (ScoreUpdateObserver* &observer:observers_) {
        observer->update(ballDetails);
    }
}