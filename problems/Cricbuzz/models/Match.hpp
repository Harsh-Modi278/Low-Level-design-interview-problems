#include "common.hpp"
class Team;
class Inning;

class Match {
    Team* team1;
    Team* team2;
    string date;
    string venue;
    MatchType matchType;
    Team* tossWinner;
    vector<Inning*> innings = vector<Inning*>(2);
};