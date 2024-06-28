#include "../models/Player.hpp"

class PlayerBowlingController {
    queue<Player*> bowlers;
    map<Player*, int> oversBalledByBowler;
    Player* currentBowler;
public:
    PlayerBowlingController() {
        while (!bowlers.empty()) {
            bowlers.pop();
        }

        oversBalledByBowler.clear();
        currentBowler = nullptr;
    }

    void setBowlers(vector<Player*> teamBowlers) {
        for (Player* &b: teamBowlers) {
            bowlers.push(b);
        }
    }

    Player* getNextBowler() {
        Player* p = bowlers.front();
        bowlers.pop();
        
        currentBowler = p;
        oversBalledByBowler[p]++;
        // 4 is to be replaced
        if (oversBalledByBowler[p] < 4) {
            bowlers.push(p);
        }

        return p;
    }
};