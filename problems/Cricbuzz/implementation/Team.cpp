#include "../models/Team.hpp"
#include "PlayerBattingController.cpp"
#include "PlayerBowlingController.cpp"

Team::Team(string name, vector<Player*> playingEleven): name_(name), playingEleven_(playingEleven) {
    playerBattingController_ = new PlayerBattingController();
    playerBowlingController_ = new PlayerBowlingController();

    playerBattingController_->setYetToPlay(playingEleven_);

    Player* p1 = playerBattingController_->getNextBatsman();
    Player* p2 = playerBattingController_->getNextBatsman();

    playerBattingController_->setStriker(p1);
    playerBattingController_->setNonStriker(p2);

    vector<Player*> bowlers;
    for (int i=10;i>=6;i--) {
        bowlers.push_back(playingEleven_[i]);
    }
    playerBowlingController_->setBowlers(bowlers);
};

Player* Team::getStriker() {
    return playerBattingController_->getStriker();
}

Player* Team::getNonStriker() {
    return playerBattingController_->getNonStriker();
}

void Team::setStriker(Player* p) {
    playerBattingController_->setStriker(p);
}

void Team::setNonStriker(Player* p) {
    playerBattingController_->setNonStriker(p);
}

Player* Team::getBowler() {
    return playerBowlingController_->getNextBowler();
}

void Team::chooseNextBatter() {
    Player* currentStriker = getStriker();
    setStriker(nullptr);

    Player* p = playerBattingController_->getNextBatsman();
    setStriker(p);
}

int Team::getTotalRuns() {
    int totalRuns = 0;
    for (Player* &p: playingEleven_) {
        totalRuns += p->getBattingScorecard()->getTotalRuns();
    }

    return totalRuns;
}

bool Team::getIsWinner() {
    return isWinner_;
}

void Team::setIsWinner(bool w) {
    isWinner_ = w;
}