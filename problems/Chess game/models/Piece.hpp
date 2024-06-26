#ifndef _PIECE_H_
#define _PIECE_H_

#include "common.hpp"
#include "Cell.hpp"

class Piece {
    PieceType pieceType_;
    PieceColor pieceColor_;
public:
    Piece(PieceType pieceType, PieceColor pieceColor): pieceType_(pieceType), pieceColor_(pieceColor) {};

    bool validateMove(Cell* startCell, Cell* endCell) {
        return false;
    };

    PieceType getType() {
        return pieceType_;
    }
};

#endif //_PIECE_H_