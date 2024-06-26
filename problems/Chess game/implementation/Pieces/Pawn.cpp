#include "../../models/Piece.hpp"

class Pawn: public Piece {
public:
    bool validateMove(Cell* startCell, Cell* endCell) {
        int x1 = startCell->getX(), y1 = startCell->getY();
        int x2 = endCell->getX(), y2 = endCell->getY();

        if (y1 == y2 && x2 == x1+1) {
            return true;
        }

        if (abs(y2-y1) == 1 && x2==x1) {
            return endCell->getPiece() != nullptr;
        }

        return false;
    }
};