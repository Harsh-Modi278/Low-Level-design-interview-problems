#include "models/Piece.h"

class Player
{
    string name;
    PieceType playingPieceType;

public:
    Player(string name, PieceType playingPiece);
    PieceType getPieceType();
    string getName();
};

Player::Player(string name, PieceType piece) {
    this->name = name;
    this->playingPieceType = piece;
}

PieceType Player::getPieceType() {
    return playingPieceType;
}

string Player::getName() {
    return name;
}