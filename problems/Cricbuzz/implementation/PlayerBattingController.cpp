#include "../models/Player.hpp"

class PlayerBattingController {
    queue<Player*> yetToPlay;
    Player* striker;
    Player* nonStriker;
public:
    PlayerBattingController() {
        while (!yetToPlay.empty()) {
            yetToPlay.pop();
        }

        striker = nullptr;
        nonStriker = nullptr;
    }

    void setYetToPlay(vector<Player*> players) {
        for (Player* &p:players) {
            yetToPlay.push(p);
        }
    }

    Player* getNextBatsman() {
        Player* p = yetToPlay.front();
        yetToPlay.pop();

        return p;
    }

    void setStriker(Player* p) {
        striker = p;
    }

    Player* getStriker() {
        return striker;
    }

    void setNonStriker(Player* p) {
        nonStriker = p;
    }

    Player* getNonStriker() {
        return nonStriker;
    }
};