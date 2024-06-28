#ifndef _BATTING_SCORECARD_H_
#define _BATTING_SCORECARD_H_

#include "Wicket.hpp"

class BattingScorecard {
    int totalRuns;
    int ballsPlayed;
    int foursHit;
    int sixesHit;
    double strikeRate;
    Wicket* wicket;
public:
    void setTotalRuns(int runs) {
        totalRuns = runs;
    }

    int getTotalRuns() {
        return totalRuns;
    }

    void setBallsPlayed(int balls) {
        ballsPlayed = balls;
    }

    int getBallsPlayed() {
        return ballsPlayed;
    }

    void setFoursHit(int fours) {
        foursHit = fours;
    }

    int getFoursHit() {
        return foursHit;
    }

    void setSixesHit(int sixes) {
        sixesHit = sixes;
    }

    int getSixesHit() {
        return sixesHit;
    }

    double getStrikeRate() {
        strikeRate = (double)0;
        if (ballsPlayed > 0) {
            strikeRate = totalRuns/ballsPlayed;
        }

        return strikeRate;
    }

    void setWicket(Wicket* w) {
        wicket = w;
    }

    Wicket* getWicket() {
        return wicket;
    }
};

#endif //_BATTING_SCORECARD_H_