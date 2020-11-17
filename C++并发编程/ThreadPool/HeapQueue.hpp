#pragma once
#include <vector>
#include <functional>

template<
    typename T, 
    typename Array=std::vector<T>,
    typename compare_T=std::less<T>
>
class HeapQueue
{
public:
    HeapQueue() { elements.clear(); }

    bool empty() { return elements.size() == 0; }

    T front() { return elements[0]; }

    /**
     * 入列，并向上调整
     */ 
    void push(const T &val) 
    {
        elements.push_back(val);    
        up_update();
    }

    /**
     * 出列，弹出栈顶元素
     */ 
    void pop() {
        if (empty())
            return ; 
        int n = elements.size();
        std::swap(elements[n-1], elements[0]);
        elements.pop_back();
        down_update();
        return ;
    }

private:
    /**
     * 向上调整
     */ 
    void up_update() 
    {
        int ind = elements.size();
        while (ind > 1 && compare(elements[ind / 2 - 1], elements[ind - 1]))
        {
            std::swap(elements[ind / 2 - 1], elements[ind - 1]);
            ind /= 2;
        }
    }

    /**
     * 向下调整
     */ 
    void down_update() 
    {
        int ind = 0, n = elements.size(); 
        while (ind * 2 + 1 < n)
        {
            int tind = ind;    
            if (compare(elements[tind], elements[ind * 2 + 1]))
                tind = ind * 2 + 1;

            if (ind * 2 + 2 < n && compare(elements[tind], elements[ind * 2 + 2]))
                tind = ind * 2 + 2;

            if (ind == tind) 
                break;
            std::swap(elements[ind], elements[tind]);
            ind = tind;
        }
    }

    Array elements;
    compare_T compare;
};