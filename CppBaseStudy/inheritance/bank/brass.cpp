// 银行账号类
#include <iostream>
#include "brass.h"

using std::cout;
using std::endl;
using std::string;

// 格式化材料
typedef std::ios_base::fmtflags format;
typedef std::streamsize precis;
format setFormat();
void restore(format f, precis p);

// Brass methods
Brass::Brass( const std::string & s, long an, double bal)
: fullName(s), acctNum(an), balance(bal) 
{
}

void Brass::Deposit(double amt)
{
    if (amt < 0) {
        cout << "Negative deposit not allowed; "
            << "deposit is cancelled.\n";
    } else {
        balance += amt;
    }
}

void Brass::Withdraw(double amt)
{
    // 设置格式化输出 ###.##
    format initialState = setFormat();
    precis prec = cout.precision(2);

    if (amt < 0) {
        cout << "Withdrawal amount must be positive; "
            << "withdrawal canceled.\n";
    } else if (amt <= balance) {
        balance -= amt;
    } else {
        cout << "Withdrawl amount of $" << amt
            << " exceeds your balance.\n"
            << "Withdrawal canceled.\n";
    }
    restore(initialState, prec);
}

double Brass::Balance() const
{
    return balance;
}

void Brass::ViewAcct() const
{
    // 设置格式化输出 ###.##
    format initialState = setFormat();
    precis prec = cout.precision(2);
    cout << "Client: " << fullName << endl;
    cout << "Account Number: " << acctNum << endl;
    cout << "Balance: $" << balance << endl;
    restore(initialState, prec); // 恢复原格式输出
    
}

// BrassPuls Methods
BrassPlus::BrassPlus(
    const std::string & s, long an, double bal,
    double ml, double r
) : Brass(s, an, bal), maxLoan(ml), rate(r), owesBank(0.0)
{
}

BrassPlus::BrassPlus( const Brass & ba, double ml, double r)
    : Brass(ba), maxLoan(ml), rate(r), owesBank(0.0)
{
}

// 重新定义 ViewAcct
void BrassPlus::ViewAcct() const
{
    // 设置格式化输出 ###.##
    format initialState = setFormat();
    precis prec = cout.precision(2);

    Brass::ViewAcct(); // 展示基本的部分
    cout << "Maximum load: $" << maxLoan << endl;
    cout << "Owed to bak: $" << owesBank << endl;
    cout.precision(3); // ###.### format
    cout << "Loan Rate: " << 100 * rate << "%\n";
    restore(initialState, prec);
}

// 重新定义 Withdraw
void BrassPlus::Withdraw(double amt)
{
    // 设置格式化输出 ###.##
    format initialState = setFormat();
    precis prec = cout.precision(2);

    double bal = Balance();
    if (amt <= bal) {
        Brass::Withdraw(amt);
    } else if( amt <= bal + maxLoan - owesBank) {
        double advance = amt - bal;
        owesBank += advance * (1.0 + rate);
        cout << "Bank advance: $" << advance << endl;
        cout << "Fiance charge: $" << advance * rate << endl;
        Deposit(advance);
        Brass::Withdraw(amt);
    } else {
        cout << "Credit limit exceeded. Transaction cancelled.\n";
    }
    restore(initialState, prec);
}

format setFormat()
{
    // 设置格式化输出 ###.##
    return cout.setf(std::ios_base::fixed,
        std::ios_base::floatfield);
}

void restore(format f, precis p)
{
    cout.setf(f, std::ios_base::floatfield);
    cout.precision(p);
}