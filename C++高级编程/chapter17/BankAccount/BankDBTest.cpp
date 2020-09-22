#include "BankDB.h"
#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    BankDB db;

    db.addAccount(BankAccount(100, "Nicholas Solter"));
    db.addAccount(BankAccount(200, "Scott Kleper"));

    try {
        auto& acct = db.findAccount(100);
        cout << "Found account 100" << endl;
        acct.setClientName("Nicholas A Solter");

        auto& acct2 = db.findAccount("Scott Kleper");
        cout << "Found account of Scott Kleper" << endl;

        auto& acct3 = db.findAccount(100);

    } catch(const out_of_range& e) {
        cerr << "Unable to find accout: " << e.what() << '\n';
    }
    

    return 0;
}
