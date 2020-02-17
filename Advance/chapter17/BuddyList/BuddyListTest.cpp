#include "BuddyList.h"
#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    BuddyList buddies;

    buddies.addBuddy("Harry potter", "Ron Weasley");
    buddies.addBuddy("Harry potter", "Hermione Grander");
    buddies.addBuddy("Harry potter", "Hagrid");
    buddies.addBuddy("Harry potter", "Draco Malfoy");
    buddies.removeBuddy("Harry potter", "Draco Malfoy");
    buddies.addBuddy("Hagrid", "Harry potter");
    buddies.addBuddy("Hagrid", "Ron Weasley");
    buddies.addBuddy("Hagrid", "Hermione Granger");

    auto harrysFriends = buddies.getBuddies("Harry Potter");

    cout << "Harry's friends: " << endl;
    for (const auto& name : harrysFriends) {
        cout << "\t" << name << endl;
    }
    return 0;
}
