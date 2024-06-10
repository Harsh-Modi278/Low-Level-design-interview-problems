#include "models/common.h"

class Grid
{
    int size;
    vector<vector<PieceType>> board;
    bool isCellFree(int x, int y);
    bool isCellValid(int x, int y);
    char transformPieceTypeToString(PieceType pieceType);

public : 
    Grid(int n);
    bool markCell(int x, int y, PieceType pieceType);
    void printGrid();
    bool isWinningMove(PieceType PieceType);
};

Grid::Grid(int n) {
    this->size = n;
    board.resize(size);
    for (int i = 0; i < size; i++) {
        board[i].resize(size);
    }

    for (int i=0;i<size;i++) {
        for (int j=0;j<size;j++) {
            this->board[i][j] = PieceType::Empty;
        }
    }
}

bool Grid::markCell(int x, int y, PieceType pieceType) {
    if (isCellValid(x, y)) {
        if (isCellFree(x, y)) {
            board[x - 1][y - 1] = pieceType;
            return true;
        } else {
            cout<<"Cell is not empty\n";
            return false;
        }
    } else {
        cout<<"Invalid move\n";
        return false;
    }
}

void Grid::printGrid() {
    for (int i=0;i<size;i++) {
        for (int j=0;j<size;j++) {
            cout << (transformPieceTypeToString(board[i][j]))<<" ";
        }
        cout<<"\n";
    }
    cout<<"---------------------\n";
}

bool Grid::isWinningMove(PieceType pieceType) {
    //row
    for (int i=0;i<size;i++) {
        int cnt = 0;
        for (int j=0;j<size;j++) {
            cnt += (board[i][j] == pieceType);
        }
        if (cnt == size) {
            return true;
        }
    }

    //col
    for (int j=0;j<size;j++) {
        int cnt = 0;
        for (int i=0;i<size;i++) {
            cnt += (board[i][j] == pieceType);
        }
        if (cnt == size) {
            return true;
        }
    }

    //diagonal1
    int cnt = 0;
    for (int i=0;i<size;i++) {
        cnt += (board[i][i] == pieceType);
    }

    if (cnt == size) {
        return true;
    }

    // diagonal2
    cnt = 0;
    for (int i=0;i<size;i++) {
        cnt += (board[i][size-1-i] == pieceType);
    }

    if (cnt == size) {
        return true;
    }

    return false;
}

char Grid::transformPieceTypeToString(PieceType pieceType) {
    if (pieceType == PieceType::Empty) {
        return '_';
    } else if (pieceType == PieceType::X) {
        return 'X';
    } 
    return 'O';
}

bool Grid::isCellValid(int x, int y) {
    return x >= 1 && x <= size && y >= 1 && y <= size;
}

bool Grid::isCellFree(int x, int y) {
    if (isCellValid(x, y)) {
        return board[x-1][y-1] == PieceType::Empty;
    }
    return false;
}