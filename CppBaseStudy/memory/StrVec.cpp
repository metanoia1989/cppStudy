#include <iostream>
#include <memory>
#include <string>
#include <utility>

class StrVec
{
private:
    static std::allocator<std::string> alloc; // 分配元素
    // 被添加元素的函数所使用
    void chk_n_alloc() { if (size() == capacity()) reallocate(); }
    // 工具函数，被拷贝构造函数、赋值运算符和析构函数所使用
    std::pair<std::string*, std::string*> alloc_n_copy 
        (const std::string*, const std::string*);
    void free(); // 销毁元素并释放内存
    void reallocate(); // 获得更多内存并拷贝已有元素怒
    std::string *elements; // 指向数组首元素的指针
    std::string *first_free; // 指向数组第一个空闲元素的指针
    std::string *cap; // 指向数组尾后位置的指针
public:
    StrVec(): // allocator 成员进行默认初始化
        elements(nullptr), first_free(nullptr), cap(nullptr) {}
    StrVec(const StrVec&); // 拷贝构造函数
    StrVec &operator=(const StrVec&); // 拷贝赋值运算符
    ~StrVec() { free(); }; // 析构函数
    void push_back(const std::string&); // 拷贝元素
    size_t size() const { return first_free - elements; }
    size_t capacity() const { return cap - elements; }
    std::string *begin() const { return elements; }
    std::string *end() const { return first_free; }
};

StrVec::StrVec(const StrVec &s)
{
    // 调用 alloc_n_copy 分配空间以容纳与 s 中一样多的元素
    auto newdata = alloc_n_copy(s.begin(), s.end());
    elements = newdata.first;
    first_free = cap = newdata.second;
}

void StrVec::push_back(const std::string& s)
{
    chk_n_alloc(); // 确保有空间容纳新元素
    // 在 first_free 指向的元素中构造 s 的副本
    alloc.construct(first_free++, s);
}

std::pair<std::string*, std::string*> 
StrVec::alloc_n_copy(const std::string* b, const std::string* e)
{
    // 分配空间保存给定范围中的元素
    auto data = alloc.allocate(e - b);
    // 初始化并返回一个 pair，该 pair 由 data 和 unitialized_copy 的返回值构成
    return { data, uninitialized_copy(b, e, data)};
}

void StrVec::free()
{
    // 不能传递给 deallocate 一个空指针，如果 elements 为 0，函数什么也不做
    if (elements) {
        // 逆序销毁旧元素
        for (auto p = first_free; p != elements; /* 空 */) 
            alloc.destroy(--p);
        alloc.deallocate(elements, cap -elements);
    }
}

StrVec &StrVec::operator=(const StrVec &rhs)
{
    // 调用 alloc_n_copy 分配内存，大小与rhs中元素占用空间一样多
    auto data = alloc_n_copy(rhs.begin(), rhs.end());
    free();
    elements = data.first;
    first_free = cap = data.second;
    return *this;
}