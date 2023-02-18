/* Packet_Ring.cpp
* Alan Burguete
* 30/11/22
* 
* Program that contains the class for the packet and the algorithm for the arbiter in the ring 
* topology.
* The Packet contains attributes such as the destination node ID, the priority the packet has,
* the length in flits of the packet, and a bit called tailed indicating the end of the packet.
* 
* The RingArbiter class receives an integer with the number of the current node's ID, an integer
* which means the interface from where it is receiving the packet (Local Processor = 0, Rightmost = 1,
* Leftmost = 2) and an integer indicating the destination node ID. Its output indicates the interface or 
* interfaces which are going to be active in order to further the current packet through them.
*/
#include <iostream>
#include <cmath>

class Packet {
public:
    int DestinationID;
    int priority;
    int Length;
    bool tail;
};

class RingArbiter {
public:
    int OutputPort;
    int TotalNodes;

    //Routing Algorithm
    void Routing(int NodeID, int source_interface, int DestinationID) {
        //Receiving from Local Processor
        if (source_interface == 0) {
            if (NodeID < DestinationID) {
                if ((2 * abs(NodeID - DestinationID)) <= TotalNodes) {
                    OutputPort = 1;
                    std::cout << "\n\t Output interfaces Active = " << OutputPort << std::endl;
                }
                else {
                    OutputPort = 2;
                    std::cout << "\n\t Output interfaces Active = " << OutputPort << std::endl;
                }
            }
            else if (NodeID > DestinationID) {
                if (2 * (NodeID - DestinationID) >= TotalNodes) {
                    OutputPort = 1;
                    std::cout << "\n\t Output interfaces Active = " << OutputPort << std::endl;
                }
                else {
                    OutputPort = 2;
                    std::cout << "\n\t Output interfaces Active = " << OutputPort << std::endl;
                }
            }else {
                OutputPort = 0;
                std::cout << "\n\t Output interfaces Active = " << OutputPort << std::endl;
            }
        }
          //Receiving from the other two ports
          else if ((source_interface == 1) && ((DestinationID != NodeID))) {
            OutputPort = 2;
            std::cout << "\n\t Output interfaces Active = " << OutputPort << std::endl;
        } else if ((source_interface == 2) && ((DestinationID != NodeID))) {
            OutputPort = 1;
            std::cout << "\n\t Output interfaces Active = " << OutputPort << std::endl;
        } else {
            OutputPort = 0;
            std::cout << "\n\t Output interfaces Active = " << OutputPort << std::endl;
        }
    }

};

int main()
{
    RingArbiter router;
    Packet packet1;
    router.TotalNodes = 8;

    //Node's ID = 1, From interface = 0, Destination = 4
    packet1.DestinationID = 4;
    router.Routing(1, 0, packet1.DestinationID);
    return 0;
}