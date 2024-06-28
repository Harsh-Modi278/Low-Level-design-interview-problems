#include "../models/Over.hpp"
#include "Ball.cpp"
#include "../models/Player.hpp"
#include "Team.cpp"

Over::Over(int overNumber, Player* bowledBy): overNumber_(overNumber), bowledBy_(bowledBy) {
    balls_.clear();
};

bool Over::startOver(Team* battingTeam, Team* bowlingTeam, int runsToWin) {
    int ballCnt = 1;
    while (ballCnt <= 6) {
        Ball* ball = new Ball(ballCnt, nullptr);
        ball->startBallDelivery(battingTeam, bowlingTeam, this);

        if (ball->getBallType() == BallType::NORMAL) {
            balls_.push_back(ball);
            ballCnt++;

            if (ball->getWicket() != nullptr) {
                battingTeam->chooseNextBatter();
            }

            if (runsToWin != -1 && battingTeam->getTotalRuns() >= runsToWin) {
                battingTeam->setIsWinner(true);
                return true;
            }

        } else {
            extraBalls_++;
        }
    }

    return false;
}

