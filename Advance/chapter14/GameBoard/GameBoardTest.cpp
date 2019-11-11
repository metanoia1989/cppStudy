#include "GameBoard.h"
#include <cstddef>

void processGameBoard(const GameBoard& board)
{
    // const GamePiece& piece = board.at(0, 0);
}

int main(int argc, char const *argv[])
{
    size_t const x = 10;
    GameBoard board(x, x);
    // GamePiece piece;

    // board.at(0, 0) = piece;
    // board.at(0, 1) = board.at(0, 0);

    // GameBoard board2;
    // board2 = board;

    // processGameBoard(board2);

    return 0;
}
