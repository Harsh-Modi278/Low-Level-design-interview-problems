#ifndef _BOWLING_SCORECARD_H_
#define _BOWLING_SCORECARD_H_

class BowlingScorecard {
    int oversBowled_;
    int wicketsTaken_;
    int runsGiven_;
    int maidenOvers_;
    int noBalls_;
    int wideBalls_;
    double economy_;
public:
    int getOversBowled() {
        return oversBowled_;
    }

    void setOversBowled(int overs) {
        oversBowled_ = overs;
    }

    int getRunsGiven() {
        return runsGiven_;
    }

    void setRunsGiven(int runs) {
        runsGiven_ = runs;
    }

    int getWicketsTaken() {
        return wicketsTaken_;
    }

    void setWicketsTaken(int w) {
        wicketsTaken_ = w;
    }

    int getNoBalls() {
        return noBalls_;
    }

    void setNoBalls(int nb) {
        noBalls_ = nb;
    }
};

#endif //_BOWLING_SCORECARD_H_