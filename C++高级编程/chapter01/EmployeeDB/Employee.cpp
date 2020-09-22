//
// Created by Administrator on 2019/9/27.
//

#include <iostream>
#include "Employee.h"

using std::cout;
using std::endl;

namespace Records {
    Employee::Employee(const std::string &firstName, const std::string &lastName) :
        mFirstName(firstName), mLastName(lastName) {}

    void Employee::promote(int raiseAmount)
    {
        setSalary(getSalary() + raiseAmount);
    }

    void Employee::demote(int demeritAmout)
    {
        setSalary(getSalary() - demeritAmout);
    }

    void Employee::hire()
    {
        mHired = true;
    }

    void Employee::fire()
    {
        mHired = false;
    }

    // 输出当前雇员的信息，使用获取器和设置器是良好的风格，在类的内部也是如此
    void Employee::display() const
    {
        cout << "Employee: " << getLastName() << ", " << getFirstName() << endl;
        cout << "-----------------------" << endl;
        cout <<(isHired()?"Current Employee":"Former Employee") << endl;
        cout << "Employeed Number: " << getEmployeeNumber() << endl;
        cout << "Salary: $" << getSalary() << endl;
        cout << endl;
    }

    // Getters and setters
    void Employee::setFirstName(const std::string &firstName)
    {
        mFirstName = firstName;
    }

    const std::string& Employee::getFirstName() const
    {
        return mFirstName;
    }

    void Employee::setLastName(const std::string &lastName)
    {
        mLastName = lastName;
    }

    const std::string& Employee::getLastName() const
    {
        return mLastName;
    }

    void Employee::setEmployeeNumber(int employeeNumber)
    {
        mEmployeeNumber = employeeNumber;
    }

    int Employee::getEmployeeNumber() const
    {
        return mEmployeeNumber;
    }

    void Employee::setSalary(int salary)
    {
        mSalary = salary;
    }

    int Employee::getSalary() const
    {
        return mSalary;
    }

    bool Employee::isHired() const
    {
        return mHired;
    };
}
