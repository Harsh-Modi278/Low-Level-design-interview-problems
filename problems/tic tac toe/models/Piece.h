#include "common.h"

class Piece {
    PieceType pieceType;
public:
    Piece() {
    }

    Piece(PieceType type) {
        pieceType = type;
    }

    PieceType getPieceType() {
        return pieceType;
    }
};