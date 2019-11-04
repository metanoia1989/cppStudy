//
// Created by Administrator on 2019/9/27.
//

#pragma once

#include <iostream>
#include <vector>
#include "Employee.h"

namespace Records {
    const int kFirstEmployeeNumber = 1000;  // 起始编号

    class Database
    {
    private:
        std::vector<Employee> mEmployees;
        int mNextEmployeeNumber = kFirstEmployeeNumber;

    public:
        Employee& addEmployee(const std::string& firstName, const std::string& lastName);
        Employee& getEmployee(int employeeNumber);
        Employee& getEmployee(const std::string& firstName, const std::string& lastName);

        void displayAll() const;    // 输出所有雇员
        void displayCurrent() const;    // 输出当前在职雇员
        void displayFormer() const;     // 输出已离职雇员
    };
}

