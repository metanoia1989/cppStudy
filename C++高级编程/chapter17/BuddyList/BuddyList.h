#pragma once

#include <map>
#include <string>
#include <vector>

class BuddyList final
{
public:
    void addBuddy(const std::string& name, const std::string& buddy);
    void removeBuddy(const std::string& name, const std::string& buddy);
    bool isBuddy(const std::string& name, const std::string& buddy) const;
    std::vector<std::string> getBuddies(const std::string& name) const;

private:
    std::multimap<std::string, std::string> mBuddies;
};