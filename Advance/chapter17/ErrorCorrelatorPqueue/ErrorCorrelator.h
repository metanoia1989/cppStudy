#pragma once

#include <ostream>
#include <string>
#include <string_view>
#include <queue>

class Error final
{
public:
    Error(int priority, std::string_view errorString) 
        : mPriority(priority), mErrorString(errorString) {}
    int getPriority() const { return mPriority; }
    std::string_view getErrorString() const { return mErrorString; }

private:
    int mPriority;
    std::string mErrorString;
};

bool operator<(const Error& lhs, const Error& rhs);
std::ostream& operator<<(std::ostream& os, const Error& err);

class ErrorCorrelator final
{
public:
    void addError(const Error& error);
    Error getError();
private:
    std::priority_queue<Error> mErrors;
};