#include "../../models/Piece.hpp"

class Rook: public Piece {
public:
    bool validateMove(Cell* startCell, Cell* endCell) {
        int x1 = startCell->getX(), y1 = startCell->getY();
        int x2 = endCell->getX(), y2 = endCell->getY();

        return (x1 == x2 || y1 == y2);
    }
};