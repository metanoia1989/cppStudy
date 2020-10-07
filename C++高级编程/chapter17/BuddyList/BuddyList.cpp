#include "BuddyList.h"

using namespace std;

void BuddyList::addBuddy(const string& name, const string& buddy)
{
    if (!isBuddy(name, buddy)) {
        mBuddies.insert({ name, buddy });
    }
}

void BuddyList::removeBuddy(const string& name, const string& buddy)
{
    auto begin = mBuddies.lower_bound(name);
    auto end = mBuddies.upper_bound(name);

    for (auto iter = begin; iter != end; ++iter) {
        if (iter->second == buddy) {
            mBuddies.erase(iter);
            break;
        }
    }
}

bool BuddyList::isBuddy(const string& name, const string& buddy) const
{
    auto [begin, end] = mBuddies.equal_range(name);
    for (auto iter = begin; iter != end; ++iter) {
        if (iter->second == buddy) {
            return true;
        }
    }
    return false;
}

vector<string> BuddyList::getBuddies(const string& name) const
{
    auto [begin, end] = mBuddies.equal_range(name);
    vector<string> buddies;
    for (auto iter = begin; iter != end; ++iter) {
        buddies.push_back(iter->second);
    }
    return buddies;
}