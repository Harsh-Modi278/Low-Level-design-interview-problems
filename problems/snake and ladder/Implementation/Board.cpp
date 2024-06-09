#ifndef _BOARD_H
#define _BOARD_H

#include "models/common.h"
#include "models/Entity.h"

#include "Player.cpp"

class Board
{
    int cells;
    vector<Entity *> snakes;
    vector<Entity *> ladders;

public:
    Board(int cells);
    void addEntity(EntityType entityType, int s, int e);
    void startGame(vector<Player *>);
};

#endif //_BOARD_H

Board::Board (int cells) {
    this->cells = cells;
}

void Board::addEntity(EntityType entityType, int s, int e) {
    Entity* newEntity = new Entity(entityType, s, e);
    if (entityType == EntityType::LADDER) {
        this->ladders.push_back(newEntity);
    } else if (entityType == EntityType::SNAKE) {
        this->snakes.push_back(newEntity);
    }
}

void Board::startGame(vector<Player*> players) {
    srand(time(0));

    bool won = false;
    Player* winner = nullptr;
    int maxRetry = 1000;

    while (!won && maxRetry--) {
        for (Player *p : players) {
            if (p->hasWon(MAX_CELLS)) {
                won = true;
                winner = p;
                break;
            }
        }

        for (Player *p : players) {
            p->rollDiceAndMove();
            if (p->hasWon(MAX_CELLS)) {
                winner = p;
                won = true;
            }
        }
    }

    cout<<(winner->name)<<" wins the game\n";
}
