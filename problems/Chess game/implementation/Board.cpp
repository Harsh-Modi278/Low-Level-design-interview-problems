#include "../models/Board.hpp"
#include "../models/Piece.hpp"

void initWhitePieces(vector<vector<Cell*>> &board_) {
    // white pieces
    for (int j=0;j<CELLS;j++) {
        Cell* cell = new Cell(1, j);
        Piece* pawn = new Piece(PieceType::PAWN, PieceColor::_WHITE_);
        cell->setPiece(pawn);

        board_[1][j] = cell;
    }

    // rooks
    {
        Cell* cell = new Cell(0, 0);
        Piece* whiteRook1 = new Piece(PieceType::ROOK, PieceColor::_WHITE_);
        cell->setPiece(whiteRook1);
        board_[0][0] = cell;

        cell = new Cell(0,7);
        Piece* whiteRook2 = new Piece(PieceType::ROOK, PieceColor::_WHITE_);
        cell->setPiece(whiteRook2);
        board_[0][7] = cell;
    }

    //knights
    {
        Cell* cell = new Cell(0, 1);
        Piece* whiteKnight1 = new Piece(PieceType::KNIGHT, PieceColor::_WHITE_);
        cell->setPiece(whiteKnight1);
        board_[0][1] = cell;

        cell = new Cell(0,6);
        Piece* whiteKnight2 = new Piece(PieceType::KNIGHT, PieceColor::_WHITE_);
        cell->setPiece(whiteKnight2);
        board_[0][6] = cell;
    }

    //bishops
    {
        Cell* cell = new Cell(0, 2);
        Piece* whiteBishop1 = new Piece(PieceType::BISHOP, PieceColor::_WHITE_);
        cell->setPiece(whiteBishop1);
        board_[0][2] = cell;

        cell = new Cell(0,5);
        Piece* whiteBishop2 = new Piece(PieceType::BISHOP, PieceColor::_WHITE_);
        cell->setPiece(whiteBishop2);
        board_[0][5] = cell;
    }

    //queen
    {
        Cell* cell = new Cell(0, 3);
        Piece* whiteQueen = new Piece(PieceType::QUEEN, PieceColor::_WHITE_);
        cell->setPiece(whiteQueen);
        board_[0][3] = cell;
    }

    //king
    {
        Cell* cell = new Cell(0, 4);
        Piece* whiteKing = new Piece(PieceType::KING, PieceColor::_WHITE_);
        cell->setPiece(whiteKing);
        board_[0][4] = cell;
    }
}

void initBlackPieces(vector<vector<Cell*>> &board_) {
    // black pieces
    for (int j=0;j<CELLS;j++) {
        Cell* cell = new Cell(1, j);
        Piece* pawn = new Piece(PieceType::PAWN, PieceColor::_BLACK_);
        cell->setPiece(pawn);

        board_[6][j] = cell;
    }

    // rooks
    {
        Cell* cell = new Cell(0, 0);
        Piece* rook1 = new Piece(PieceType::ROOK, PieceColor::_BLACK_);
        cell->setPiece(rook1);
        board_[7][0] = cell;

        cell = new Cell(0,7);
        Piece* rook2 = new Piece(PieceType::ROOK, PieceColor::_BLACK_);
        cell->setPiece(rook2);
        board_[7][7] = cell;
    }

    //knights
    {
        Cell* cell = new Cell(0, 1);
        Piece* knight1 = new Piece(PieceType::KNIGHT, PieceColor::_BLACK_);
        cell->setPiece(knight1);
        board_[7][1] = cell;

        cell = new Cell(0,6);
        Piece* knight2 = new Piece(PieceType::KNIGHT, PieceColor::_BLACK_);
        cell->setPiece(knight2);
        board_[7][6] = cell;
    }

    //bishops
    {
        Cell* cell = new Cell(0, 2);
        Piece* bishop1 = new Piece(PieceType::BISHOP, PieceColor::_BLACK_);
        cell->setPiece(bishop1);
        board_[7][2] = cell;

        cell = new Cell(0,5);
        Piece* bishop2 = new Piece(PieceType::BISHOP, PieceColor::_BLACK_);
        cell->setPiece(bishop2);
        board_[7][5] = cell;
    }

    //queen
    {
        Cell* cell = new Cell(0, 3);
        Piece* queen = new Piece(PieceType::QUEEN, PieceColor::_BLACK_);
        cell->setPiece(queen);
        board_[7][3] = cell;
    }

    //king
    {
        Cell* cell = new Cell(0, 4);
        Piece* king = new Piece(PieceType::KING, PieceColor::_BLACK_);
        cell->setPiece(king);
        board_[7][4] = cell;
    }
}

Board::Board() {
    initWhitePieces(board_);
    initBlackPieces(board_);
}

void Board::move(Cell* startCell, Cell* endCell) {
    // validate whether the piece at startCell can move to endCell
    Piece* piece = startCell->getPiece();

    if (piece->validateMove(startCell, endCell)) {
        // if yes, then
        int x1 = startCell->getX(), y1 = startCell->getY();
        int x2 = endCell->getX(), y2 = endCell->getY();

        cout<<"\nmoving "<<piece->getType()<<" from ("<<x1<<", "<<y1<<") to ("<<x2<<", "<<y2<<")\n";

        endCell->setPiece(piece);
        startCell->setPiece(nullptr);
    } else {
        cout<<"\nInvalid move\n";
    }

}