#include <iostream>
#include "hello.hpp"

#include <IMC/Spec/Abort.hpp>
#include <IMC/Base/ByteBuffer.hpp>
#include <IMC/Base/Packet.hpp>
#include <UDP/DatagramSocket.h>
#include <IMC/Spec/PlanSpecification.hpp>

#define LAUVXPLORE1 (30)
using namespace IMC;
int main() {
    hello::say_hello();

    char localhost[] = "127.0.0.1";
    PlanSpecification planSpec; // Create planSpec message
    planSpec.setTimeStamp(1.5628304294681385E9);       // set timestamp 

    planSpec.setSource(16652);
    planSpec.setSourceEntity(44); 

    planSpec.setDestination(LAUVXPLORE1);   // specify destination (otherwise DUNE will reject it)
    planSpec.setDestinationEntity(255);
    
    planSpec.plan_id = "cmd-lauv-xplore-1";
    planSpec.description = ""; // Probably not necessary
    planSpec.vnamespace = "";  // Probably not necessary
    planSpec.start_man_id = 1;
    
    planSpec.transitions = {};
    planSpec.start_actions = {};
    planSpec.end_actions = {};

    PlanManeuver planMan;
    planMan.maneuver_id = 1;

    

    planMan.data;
    planMan.start_actions;
    planMan.end_actions;

    int size = planSpec.getSerializationSize();    // calculate bytes required for serialization
    char buffer[size];                          // allocate same number of bytes
    
    Packet::serialize(&planSpec, (uint8_t *) buffer, size);    // serialize message
    DatagramSocket socket(6002, localhost, true, true);     // see https://github.com/butcherg/DatagramSocket
    socket.sendTo(buffer, size, localhost);                 // send message to 127.0.0.1:6002
}