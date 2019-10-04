#include <iostream>
#include <fstream>
#include "hello.hpp"

#include <IMC/Spec/Abort.hpp>
#include <IMC/Base/ByteBuffer.hpp>
#include <IMC/Base/Packet.hpp>
#include <IMC/Spec/PlanSpecification.hpp>
#include <IMC/Spec/Loiter.hpp>
#include <IMC/Spec/SetEntityParameters.hpp>
#include <IMC/Spec/EntityParameter.hpp>
#include <UDP/DatagramSocket.h>

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

    
    Loiter loiter;
    loiter.timeout = 10000;
    loiter.lat = 0.7188016469344056;
    loiter.lon =-0.15194250254286037;
    loiter.z = 3;
    loiter.z_units = 1;
    loiter.duration = 300;
    loiter.speed = 1000;
    loiter.speed_units = 1;
    loiter.radius = 20;
    loiter.length = 1;
    loiter.bearing = 0;
    loiter.direction  = 1;
    loiter.custom = "";

    EntityParameter entParam;
    entParam.name = "Active";
    entParam.value = "false";

    SetEntityParameters setEntParam;
    setEntParam.name = "LBL";
    setEntParam.params.push_back(entParam);

    planMan.data.set(loiter);
    planMan.start_actions.push_back(setEntParam);
    planMan.end_actions;

    planSpec.maneuvers.push_back(planMan);

    int size = planSpec.getSerializationSize();    // calculate bytes required for serialization
    char buffer[size];                          // allocate same number of bytes
    
    Packet::serialize(&planSpec, (uint8_t *) buffer, size);    // serialize message
    DatagramSocket socket(6002, localhost, true, true);     // see https://github.com/butcherg/DatagramSocket
    socket.sendTo(buffer, size, localhost);                 // send message to 127.0.0.1:6002


    // Write to terminal
    std::cout << "{abbrev: ";
    std::cout << planSpec.getName();
    std::cout << ",\nsrc: ";
    std::cout << planSpec.getSource();
    std::cout << ",\nsrc_ent: ";
    std::cout <<  unsigned(planSpec.getSourceEntity());
    std::cout << ",\ndst: ";
    std::cout << planSpec.getDestination();
    std::cout << ",\ndst_ent: ";
    std::cout << unsigned(planSpec.getDestinationEntity());
    planSpec.fieldsToJSON(std::cout,0);
    std::cout << "}\n";

    // Write to disk
    std::ofstream file;
    file.open("IMC_messages.txt");
    file << "{abbrev: ";
    file << planSpec.getName();
    file << ",\nsrc: ";
    file << planSpec.getSource();
    file << ",\nsrc_ent: ";
    file <<  unsigned(planSpec.getSourceEntity());
    file << ",\ndst: ";
    file << planSpec.getDestination();
    file << ",\ndst_ent: ";
    file << unsigned(planSpec.getDestinationEntity());
    planSpec.fieldsToJSON(file,0);
    file << "}\n";
    file.close();

    file << "Program ended." << std::endl;
    

}

