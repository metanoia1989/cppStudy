class Base
{
public:
    virtual ~Base() = default;
    Base() = default;
    Base(const Base& src);
    Base& operator=(const Base& rhs);
};

Base::Base(const Base& src)
{
}

class Derived : public Base
{
public:
    Derived() = default;
    Derived(const Derived& src);
    Derived& operator=(const Derived& rhs);
};

Derived::Derived(const Derived& src) : Base(src)
{
}

Derived& Derived::operator=(const Derived& rhs) 
{
    if (&rhs == this) {
        return *this;
    }
    Base::operator=(rhs);  
    return *this;
}