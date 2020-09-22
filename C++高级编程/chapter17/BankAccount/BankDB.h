#pragma once

#include <map>
#include <string>
#include <string_view>

class BankAccount final
{
public:
    BankAccount(int acctNum, std::string_view name) : mAcctNum(acctNum), mClientName(name) {}

    void setAcctNum(int acctNum) { mAcctNum = acctNum; }
    int getAcctNum() const { return mAcctNum; }

    void setClientName(std::string_view name) { mClientName = name; }
    std::string_view getClientName() const { return mClientName; }

private:
    int mAcctNum;
    std::string mClientName;
};

class BankDB final
{
public:
    bool addAccount(const BankAccount& account);
    void deleteAccount(int acctNum);

    BankAccount& findAccount(int acctNum);
    BankAccount& findAccount(std::string_view name);

    void mergeDatabase(BankDB& db);

private:
    std::map<int, BankAccount> mAccounts;
};