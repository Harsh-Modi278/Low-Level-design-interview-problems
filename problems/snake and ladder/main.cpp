#include "Implementation/Board.cpp"
#include "models/common.h"

int32_t main() {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    Board *board = new Board(MAX_CELLS);

    int snakesCount, laddersCount, playersCount;
    cin>>snakesCount;
    while (snakesCount--) {
        int s, e;
        cin>>s>>e;
        board->addEntity(EntityType::SNAKE, s, e);
    }

    cin>>laddersCount;
    while (laddersCount--) {
        int s, e;
        cin >> s >> e;
        board->addEntity(EntityType::LADDER, s, e);
    }

    cin >> playersCount;
    vector<Player*> players;
    string name;
    while (playersCount--) {
        cin>>name;
        Player * p = new Player(name);
        players.push_back(p);
    }

    board->startGame(players);

    return 0;
}