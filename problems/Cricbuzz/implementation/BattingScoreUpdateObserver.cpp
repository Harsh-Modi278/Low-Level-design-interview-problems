#include "../models/ScoreUpdateObserver.hpp"
#include "../models/Ball.hpp"
#include "../models/BattingScoreCard.hpp"
#include "../models/Player.hpp"

class BattingScoreUpdateObserver : public ScoreUpdateObserver {
public:
    void update(Ball* ballDetails) {
        int runs = 0;
        BattingScorecard* bsc = ballDetails->getPlayedBy()->getBattingScorecard();

        if (ballDetails->getRunType() == RunType::SINGLE) {
            runs = 1;
        } else if (ballDetails->getRunType() == RunType::DOUBLE) {
            runs = 2;
        } else if (ballDetails->getRunType() == RunType::THREE) {
            runs = 3;
        } else if (ballDetails->getRunType() == RunType::FOUR) {
            runs = 4;
            int foursHit = bsc->getFoursHit();
            bsc->setFoursHit(1+foursHit);
        } else if (ballDetails->getRunType() == RunType::SIX) {
            runs = 6;
            int sixesHit = bsc->getSixesHit();
            bsc->setSixesHit(1+sixesHit);
        }

        int currentRunsByPlayer = bsc->getTotalRuns();
        bsc->setTotalRuns(currentRunsByPlayer+runs);

        int ballsPlayed = bsc->getBallsPlayed();
        bsc->setBallsPlayed(1+ballsPlayed);

        if (ballDetails->getBallType() == BallType::WICKET) {

        }
    }
};