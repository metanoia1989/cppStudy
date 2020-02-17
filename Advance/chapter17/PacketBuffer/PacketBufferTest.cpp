#include "PacketBuffer.h"
#include <iostream>

using namespace std;

class IPPacket final
{
public:
    IPPacket(int id) : mID(id) {}
    int getID() const { return mID; }

private:
    int mID;
};

int main(int argc, char const *argv[])
{
    PacketBuffer<IPPacket> ipPackets(3);

    for (int i= 1; i <= 4; ++i) {
        if (!ipPackets.bufferPacket(IPPacket(i))) {
            cout << "Packet " << i << "" << endl;
        }
    }

    while (true) {
        try {
            IPPacket packet = ipPackets.getNextPacket();
            cout << "Processing packet " << packet.getID() << endl;
        } catch(const out_of_range& e) {
            cerr << e.what() << '\n';
            break;
        }
        
    }

    return 0;
}
