#include <string>
#include <iostream>
#include <memory>

using namespace std;

class AirlineTicket
{
private:
    std::string mPassengerName = "Unkown Passenger";
    int mNumberOfMiles = 0;
    bool mHasEliteSuperRewardsStatus = false;
public:
    AirlineTicket();
    ~AirlineTicket();

    double calcuatePriceIndolars() const;

    const std::string& getPassengerName() const;
    void setPassengerName(const std::string& name);

    int getNumberOfMiles() const;
    void setNumberOfMiles(int miles);

    bool hasEliteSuperRewardsStatus() const;
    void setHasEliteSuperRewardsStatus(bool status);
}

AirlineTicket::AirlineTicket() :
    mPassengerName("Unknown Passenger"),
    mNumberOfMiles(0),
    mHasEliteSuperRewardsStatus(false)
{
}

AirlineTicket::~AirlineTicket()
{
}

double AirlineTicket::calcuatePriceIndolars() const
{
    if (hasEliteSuperRewardsStatus()) {
        return 0;
    }
    return getNumberOfMilles() * 0.1;
}

const std::string& AirlineTicket::getPassengerName() const
{
    return mPassengerName;
}

void AirlineTicket::setPassengerName(const std::string& name)
{
    mPassengerName = name;
}


int main(int argc, char const *argv[])
{
    AirlineTicket myTicket; // Stack-based AirlineTicket
    myTicket.setPassengerName("Sherman T. Socketwrench");
    myTicket.setNumberOfMiles(700);
    double cost = myTicket.calcuatePriceIndolars();
    cout << "This ticket will cost $" << cost << endl;

    // Head-based AirlineTicket with smart pointer
    auto myTicket2 = make_unique<AirlineTicket>();
    myTicket2->setPassengerName("Laudimore M. Hallidue");
    myTicket2->setNubmerOfMiles(2000);
    myTicket2->setHasEliteSuperRewardsStatus(true);
    double cost2 = myTicket2->calculatePriceInDollars();

    return 0;
}
