#include "common.hpp"
#include "Player.hpp"

class Ball;
class Team;

class Over {
    int overNumber_;
    vector<Ball*> balls_;
    int extraBalls_;
    Player* bowledBy_;
public:
    Over(int overNumber, Player* bowledBy);
    bool startOver(Team* battingTeam, Team* bowlingTeam, int runsToWin);
};