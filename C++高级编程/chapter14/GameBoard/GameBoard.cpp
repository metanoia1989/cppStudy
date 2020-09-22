#include "GameBoard.h"
#include <stdexcept>
#include <utility>
#include <new>

using namespace std;

GameBoard::GameBoard(size_t width, size_t height)
{
    mCells = new GamePiece*[width] {};  // 0 初始化数组
    mWidth = width;
    mHeight = height;

    try {
        for (size_t i = 0; i < mWidth; i++) {
            mCells[i] = new GamePiece[mHeight];
        }
    } catch(...) {
        cleanup();
        std::throw_with_nested(std::bad_alloc());
    }
    
}

GameBoard::GameBoard(const GameBoard& src)
    : GameBoard(src.mWidth, src.mHeight)
{
    for (size_t i = 0; i < mWidth; i++) {
        for (size_t j = 0; j < mHeight; j++) {
            mCells[i][j] = src.mCells[i][j];
        }
    }
}

GameBoard::~GameBoard() noexcept
{
    cleanup();
}

void GameBoard::cleanup() noexcept
{
    for (size_t i = 0; i < mWidth; i++) {
        delete[] mCells[i];
    }
    delete[] mCells;
    mCells = nullptr;
    mWidth = mHeight = 0;
}

void GameBoard::verifyCoordinate(size_t x, size_t y) const
{
    if (x >= mWidth) {
        throw out_of_range("x-corrdinate beyong width");
    } 
    if (y >= mHeight) {
        throw out_of_range("y-corrdinate beyong height");
    } 
}

void swap(GameBoard& first, GameBoard& second) noexcept
{
    using std::swap;

    swap(first.mWidth, second.mWidth);
    swap(first.mHeight, second.mHeight);
    swap(first.mCells, second.mCells);
}