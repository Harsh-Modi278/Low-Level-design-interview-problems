#include "Cell.hpp"

class Board {
    vector<vector<Cell*>> board_ = vector<vector<Cell*>>(CELLS, vector<Cell*>(CELLS));
public:
    Board();
    void move(Cell* startCell, Cell* endCell);
};