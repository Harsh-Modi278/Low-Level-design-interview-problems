#ifndef _COMMON_H_
#define _COMMON_H_

#include <iostream>
#include <string>
#include <vector>
using namespace std;

enum PlayerType {
    WHITE,
    BLACK
};

enum PieceType {
    ROOK,
    KNIGHT,
    PAWN,
    BISHOP,
    QUEEN,
    KING
};
enum PieceColor {
    _WHITE_,
    _BLACK_
};

const int CELLS = 8;

using namespace std;

#endif //_COMMON_H_