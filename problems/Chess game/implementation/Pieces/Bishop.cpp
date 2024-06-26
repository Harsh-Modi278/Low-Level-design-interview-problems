#include "../../models/Piece.hpp"

class Bishop: public Piece {
public:
    bool validateMove(Cell* startCell, Cell* endCell) {
        int x1 = startCell->getX(), y1 = startCell->getY();
        int x2 = endCell->getX(), y2 = endCell->getY();

        return (x1-x1 == y1 - y2);
    }
};