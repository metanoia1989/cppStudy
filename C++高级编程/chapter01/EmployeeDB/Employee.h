//
// Created by Administrator on 2019/9/27.
//

#pragma once
#include <string>

namespace Records
{
    const int kDefaultStartingSalary = 30000;   // 新雇员的默认起薪

    class Employee
    {
    private:
        std::string mFirstName;
        std::string mLastName;
        int mEmployeeNumber = -1;   // 雇员编号
        int mSalary = kDefaultStartingSalary;
        bool mHired = false;

    public:
         Employee() = default;
         Employee(const std::string& firstName, const std::string& lastName);

         void promote(int raiseAmount = 1000);
         void demote(int demeritAmout = 1000);
         void hire();   // 雇佣
         void fire();   // 解雇
         void display() const;

         // Getters and setters
         void setFirstName(const std::string& firstName);
         const std::string& getFirstName() const;

         void setLastName(const std::string& lastName);
         const std::string& getLastName() const;

         void setEmployeeNumber(int employeeNumber);
         int getEmployeeNumber() const;

         void setSalary(int salary);
         int getSalary() const;

         bool isHired() const;
    };
}




