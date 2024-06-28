#ifndef _TEAM_H_
#define _TEAM_H_

#include "common.hpp"
class Player;
class PlayerBattingController;
class PlayerBowlingController;

class Team {
    string name_;
    vector<Player*> playingEleven_;
    vector<Player*> extraPlayers;
    PlayerBattingController* playerBattingController_;
    PlayerBowlingController* playerBowlingController_;
    bool isWinner_;
public:
    Team(string name, vector<Player*> playingEleven);
    Player* getStriker();
    void setStriker(Player*);
    Player* getNonStriker();
    void setNonStriker(Player*);
    Player* getBowler();
    void chooseNextBatter();
    int getTotalRuns();
    bool getIsWinner();
    void setIsWinner(bool);
};

#endif //_TEAM_H_