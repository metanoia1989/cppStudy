#pragma once

#include <cstddef>
#include <stdexcept>
#include <vector>

/**
 * 时间片轮转调度类
 * 
 */
template<typename T>
class RoundRobin
{
public:
    RoundRobin(size_t numExcepted = 0);
    virtual ~RoundRobin() = default;

    RoundRobin(const RoundRobin& src) = delete;
    RoundRobin& operator=(const RoundRobin& rhs) = delete;

    RoundRobin(RoundRobin&& src) = default;
    RoundRobin& operator=(RoundRobin&& rhs) = default;

    void add(const T& element);
    void remove(const T& element);

    T& getNext();

private:
    std::vector<T> mElements;
    typename std::vector<T>::iterator mCurrentElment;
};

template <typename T>
RoundRobin<T>::RoundRobin(size_t numExcepted)
{
    mElements.reserve(numExcepted);
    mCurrentElment = begin(mElements);
}

template <typename T>
void RoundRobin<T>::add(const T& element)
{
    int pos = mCurrentElment - begin(mElements);
    mElements.push_back(element);
    mCurrentElment = begin(mElements) + pos;
}

template <typename T>
void RoundRobin<T>::remove(const T& element)
{
    for (auto it = begin(mElements); it != end(mElements); ++it) {
        if (*it == element) {
            int newPos;
            if (mCurrentElment == end(mElements) - 1 &&
                mCurrentElment == it) {
                newPos = 0;
            } else if (mCurrentElment <= it) {
                newPos = mCurrentElment - begin(mElements);
            } else {
                newPos = mCurrentElment - begin(mElements) - 1;
            }
            mElements.erase(it);
            mCurrentElment = begin(mElements) + newPos;
            return;
        }
    }
}

template <typename T>
T& RoundRobin<T>::getNext()
{
    if (mElements.empty()) {
        throw std::out_of_range("No elements in the list");
    }
    auto& toReturn = *mCurrentElment;
    ++mCurrentElment;
    if (mCurrentElment == end(mElements)) {
        mCurrentElment = begin(mElements);
    }
    return toReturn;
}