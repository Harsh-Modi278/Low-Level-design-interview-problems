#include "TicTacToeGame.cpp"

int32_t main() {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    TicTaeToeGame* game = new TicTaeToeGame();
    game->startGame();
    return 0;
}