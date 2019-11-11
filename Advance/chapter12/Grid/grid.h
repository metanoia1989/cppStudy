#pragma once

#include <vector>
#include <optional>

template <typename T>
class Grid
{
private:
    void verifyCoordinate(size_t x, size_t y) const;

	std::vector<std::vector<std::optional<T>>> mCells;
    size_t mWidth, mHeight;

public:
    explicit Grid(size_t width = kDefaultWidth, size_t height = kDefaultHeight);
    Grid(const Grid& src);    // 复制构造函数

    virtual ~Grid() = default; // 默认虚析构函数
    Grid<T>& operator=(const Grid& rhs); // 赋值运算符

    // 显式移动构造函数
    Grid(Grid&& src) = default;
    Grid<T>& operator=(Grid&& src) = default;

    std::optional<T>& at(size_t x, size_t y);
    const std::optional<T>& at(size_t x, size_t y) const;

    size_t getHeight() const { return mHeight; }
    size_t getWidth() const { return mWidth; }

    static const size_t kDefaultWidth = 10;
    static const size_t kDefaultHeight = 10;
};

template <typename T>
Grid<T>::Grid(size_t width, size_t height)
    : mWidth(width), mHeight(height)
{
    mCells.resize(mWidth);
    for (auto& column : mCells) {
        column.resize(mHeight);
    }
}

template <typename T>
Grid<T>::Grid(const Grid& src)
    : Grid(src.mWidth, src.mHeight)
{
    for (size_t i = 0; i < mWidth; i++) {
        for (size_t j = 0; j < mHeight; j++) {
            if (src.mCells[i][j])
                mCells[i][j] = src.mCells[i][j]->clone();
        }
    }
    
}

template <typename T>
void Grid<T>::verifyCoordinate(size_t x, size_t y) const
{
    if (x >= mWidth || y >= mHeight) {
        throw std::out_of_range("");
    }
}


template <typename T>
const std::optional<T>& Grid<T>::at(size_t x, size_t y) const
{
    verifyCoordinate(x, y);
    return mCells[x][y];
}

