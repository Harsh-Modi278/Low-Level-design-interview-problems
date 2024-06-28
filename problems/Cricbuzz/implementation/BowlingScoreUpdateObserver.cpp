#include "../models/ScoreUpdateObserver.hpp"
#include "../models/Ball.hpp"
#include "../models/BowlingScoreCard.hpp"
#include "../models/Player.hpp"

class BowlingScoreUpdateObserver : public ScoreUpdateObserver {
public:
    void update(Ball* ballDetails) {
        BowlingScorecard* bsc = ballDetails->getBowledBy()->getBowlingScorecard();

        int runsGiven = 0;
        if (ballDetails->getRunType() == RunType::SINGLE) {
            runsGiven = 1;
        } else if (ballDetails->getRunType() == RunType::DOUBLE) {
            runsGiven = 2;
        } else if (ballDetails->getRunType() == RunType::THREE) {
            runsGiven = 3;
        } else if (ballDetails->getRunType() == RunType::FOUR) {
            runsGiven = 4;
        } else if (ballDetails->getRunType() == RunType::SIX) {
            runsGiven = 6;
        }

        int currentRunsGiven = bsc->getRunsGiven();
        bsc->setRunsGiven(currentRunsGiven+runsGiven);

        if (ballDetails->getWicket() != nullptr) {
            int w = bsc->getWicketsTaken();
            bsc->setWicketsTaken(1+w);
        }

        if (ballDetails->getBallType() == BallType::NO_BALL) {
            int nb = bsc->getNoBalls();
            bsc->setNoBalls(1+nb);
        }

        if (ballDetails->getBallNumber() == 6 && ballDetails->getBallType() == BallType::NORMAL) {
            int currentOversBowled = bsc->getOversBowled();
            bsc->setOversBowled(1+currentOversBowled);
        }
    }
};