#include "Board.cpp"
#include "../models/Player.hpp"

class Game {
    vector<Player*> players = vector<Player*>(2);
    PlayerType turn;
    Board* board;
public:
    Game() {
        board = new Board();
        players[0] = new Player("A", PlayerType::WHITE);
        players[1] = new Player("B", PlayerType::BLACK);
    }
    PlayerType getCurrentTurn() {
        return turn;
    }

    void startGame() {

    }
};