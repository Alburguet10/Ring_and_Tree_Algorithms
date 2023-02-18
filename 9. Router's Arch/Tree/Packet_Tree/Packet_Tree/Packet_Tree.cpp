/* Packet.cpp
* Alan Burguete
* 30/11/22
*
* Program that contains the class for the packet and the algorithm for the arbiter in the tree
* topology.
* The Packet contains attributes such as the destination node ID, the priority the packet has,
* the length in flits of the packet, and a bit called tailed indicating the end of the packet.
*
* The Routing Function inside the TreeArbiterIRouter class receives an integer with the Group ID
* of the destination, and another integer which means the interface from where it is receiving
* the packet (Local Processor = 0, Upwards Port = 1, Downwards Port 1 = 2, Downwards Port 2 = 3)
* Its output indicates the interface or interfaces which are going to be active in order to further
* the current packet through them.
*/

#include <iostream>
using namespace std;

class Packet {
public:
    int GroupID;
    int priority;
    int Length;
    bool tail;
};

class TreeArbiterIRouter {
public:
    int NodesID;
    int OutputPort;
    int interfaces = 0;

    //Routing Algorithm
    void Routing(int GroupID, int source_interface) {
        //If destination group ID corresponds to node's ID, send all other directions
        //except the one it came from
        if (GroupID == NodesID) {
            while (interfaces < 4) {
                if (interfaces != source_interface) {
                    OutputPort = interfaces;
                    cout << "\n\t Output interfaces Active = " << OutputPort << endl;
                }
                interfaces++;
            }
        }
        //If ID is not the node's ID, send only up
        else {
            OutputPort = 1;
            cout << "\n\t Output interfaces Active = " << OutputPort << endl;
        }
    }

};

int main()
{
    TreeArbiterIRouter router;
    //Sending packet (from Local Processor) with the same Group ID
    /*router.NodesID = 1;
    router.Routing(1, 0);
    return 0;*/

    //Sending packet (from Local Processor) with different Group ID
    /*router.NodesID = 1;
    router.Routing(2, 0);
    return 0;*/

    //Sending packet (from interface D1) with the same Group ID
    /*router.NodesID = 1;
    router.Routing(1, 3);
    return 0;*/

    //Sending packet (from interface D2) with the same Group ID
    /*router.NodesID = 1;
    router.Routing(1, 2);
    return 0;*/

    //Sending packet (from interface D1) with different Group ID
    /*router.NodesID = 1;
    router.Routing(2, 3);
    return 0;*/

    //Sending packet (from interface D2) with different Group ID
    /*router.NodesID = 1;
    router.Routing(2, 2);
    return 0;*/

    //Sending packet (from interface UP) with the same Group ID
    /*router.NodesID = 1;
    router.Routing(1, 1);
    return 0;*/

    //Sending packet (from interface UP) with different Group ID
    router.NodesID = 1;
    router.Routing(2, 0);
    return 0;
}