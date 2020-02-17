/**
 * 通用棋盘类
 */
#include <cstddef>
#include <memory>
#include <vector>
#include <stdexcept>
#include <utility>

// 棋子
class GamePiece
{
public:
    virtual std::unique_ptr<GamePiece> clone() const = 0;
};

class ChessPiece : public GamePiece
{
public:
    virtual std::unique_ptr<GamePiece> clone() const override;
};

std::unique_ptr<GamePiece> ChessPiece::clone() const
{
    return std::make_unique<ChessPiece>(*this);
}

// 棋盘
class GameBoard
{
public:
    explicit GameBoard(size_t width = kDefaultWidth, size_t height = kDefaultHeight);
    GameBoard(const GameBoard& src);    // 复制构造函数
    virtual ~GameBoard() = default; // 默认虚析构函数
    GameBoard& operator=(const GameBoard& rhs); // 赋值运算符

    // 显式移动构造函数
    GameBoard(GameBoard&& src) = default;
    GameBoard& operator=(GameBoard&& src) = default;

    std::unique_ptr<GamePiece>& at(size_t x, size_t y);
    const std::unique_ptr<GamePiece>& at(size_t x, size_t y) const;

    size_t getHeight() const { return mHeight; }
    size_t getWidth() const { return mWidth; }

    static const size_t kDefaultWidth = 10;
    static const size_t kDefaultHeight = 10;

    friend void swap(GameBoard& first, GameBoard& second) noexcept;

private:
    void verifyCoordinate(size_t x, size_t y) const;
    
    std::vector<std::vector<std::unique_ptr<GamePiece>>> mCells;
    size_t mWidth, mHeight;
};

GameBoard::GameBoard(size_t width, size_t height)
    : mWidth(width), mHeight(height)
{
    mCells.resize(mWidth);
    for (auto& column : mCells) {
        column.resize(mHeight);
    }
}

GameBoard::GameBoard(const GameBoard& src)
    : GameBoard(src.mWidth, src.mHeight)
{
    for (size_t i = 0; i < mWidth; i++) {
        for (size_t j = 0; j < mHeight; j++) {
            if (src.mCells[i][j])
                mCells[i][j] = src.mCells[i][j]->clone();
        }
    }
    
}

void GameBoard::verifyCoordinate(size_t x, size_t y) const
{
    if (x >= mWidth || y >= mHeight) {
        throw std::out_of_range("");
    }
}

void swap(GameBoard& first, GameBoard& second) noexcept
{
    using std::swap;

    swap(first.mWidth, second.mWidth);
    swap(first.mHeight, second.mHeight);
    swap(first.mCells, second.mCells);
}

GameBoard& GameBoard::operator=(const GameBoard& rhs)
{
    if (this == &rhs){
        return *this;
    }

    GameBoard temp(rhs);
    swap(*this, temp);
    return *this;
}

const std::unique_ptr<GamePiece>& GameBoard::at(size_t x, size_t y) const
{
    verifyCoordinate(x, y);
    return mCells[x][y];
}

std::unique_ptr<GamePiece>& GameBoard::at(size_t x, size_t y) 
{
    return const_cast<std::unique_ptr<GamePiece>&>(std::as_const(*this).at(x, y));
}

