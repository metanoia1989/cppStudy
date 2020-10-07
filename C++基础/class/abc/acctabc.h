#ifndef ACCTABC_H_ 
#define ACCTABC_H_
#include <iostream>
#include <string>

// 抽象基类
class AcctABC
{
private:
    std::string fullName;
    long acctNum;
    double balance;
protected:
    struct Formatting
    {
        std::ios_base::fmtflags flag;
        std::streamsize pr;
    };
    const std::string & FullName() const { return fullName; } 
    long AcctNum() const { return acctNum; }
    Formatting SetFormat() const;
    void Restore(Formatting & f) const;
public:
    AcctABC(const std::string & s = "Nullbody", long an = -1, double bal = 0.0);
    void Deposit(double amt);
    virtual void Withdraw(double amt) = 0; // 纯虚函数
    double Balance() const { return balance; }
    virtual void ViewAcct() const = 0; // 纯虚函数
    virtual ~AcctABC() {};
};

// Brass Account Class
class Brass : public AcctABC
{
private:
    
public:
    Brass(/* args */);
    ~Brass();
};

Brass::Brass(/* args */)
{
}

Brass::~Brass()
{
}


AcctABC::AcctABC(/* args */)
{
}

AcctABC::~AcctABC()
{
}


#endif