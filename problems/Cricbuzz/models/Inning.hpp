#include "common.hpp"

class Team;
class Over;

class Inning {
    Team* battingTeam;
    Team* bowlingTeam;
    vector<Over*> overs;
};