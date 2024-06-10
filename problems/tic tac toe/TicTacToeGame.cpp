#include "models/common.h"
#include "Implementation/Player.cpp"
#include "Implementation/Grid.cpp"

class TicTaeToeGame {
    queue<Player*> players;
    Grid* grid;

    vector<int> getIndex(string line) {
        string s = "";
        vector<string> v;

        for (auto &c : line) {
            if (c == ' ') {
                v.push_back(s);
                s = "";
            }
            else {
                s = s + c;
            }
        }
        v.push_back(s);

        vector<int> res;
        for (string &ss : v) {
            if (ss.size() > 0) {
                res.push_back(stoi(ss));
            }
        }

        return res;
    }

public:
    void startGame() {
        int gridSize, nPlayers;

        cin>>gridSize;
        grid = new Grid(gridSize);

        cin >> nPlayers;

        while (nPlayers--) {
            char pieceType;
            string name;
            
            cin>>pieceType;
            cin>>name;

            PieceType pType = PieceType::Empty;
            if (pieceType == 'X') {
                pType = PieceType::X;
            } else {
                pType = PieceType::O;
            }
            Player* p = new Player(name, pType);
            players.push(p);
        }

        bool foundX = false;
        while (!foundX) {
            Player* p = players.front();
            if (p->getPieceType() == PieceType::X) {
                foundX = false;
                break;
            } 
            players.pop();
            players.push(p);
        }

        grid->printGrid();

        cin.ignore(10000, '\n'); // Skip just past the end of the line
        string line;
        bool someoneWon = false;
        while (getline(std::cin, line)) {
            if (line == "exit") {
                break;
            }


            vector<int> index = getIndex(line);
            int x = index[0], y = index[1];

            Player *p = players.front();

            bool marked = grid->markCell(x, y, p->getPieceType());
            if (marked) {
                players.pop();
                players.push(p);
                grid->printGrid();
                if (grid->isWinningMove(p->getPieceType())) {
                    cout<<p->getName()<<" has won\n";
                    someoneWon = true;
                    break;
                }
            } else {
                cout<<"repeat turn\n";
            }
        }

        if (!someoneWon) {
            cout<<"Game Over\n";
        }
    }
};

