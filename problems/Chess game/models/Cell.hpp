#ifndef _CELL_H_
#define _CELL_H_

#include "common.hpp"

class Piece;

class Cell {
    int x_;
    int y_;
    Piece* piece_;
public:
    Cell(int x, int y) : x_(x), y_(y) {
        piece_ = nullptr;
    };
    
    void setPiece(Piece* piece) {
        piece_ = piece;
    }

    Piece* getPiece() {
        return piece_;
    }

    int getX() {
        return x_;
    }

    int getY() {
        return y_;
    }
};

#endif //_CELL_H_