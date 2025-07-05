#include "Gateway.h"
#include "SensorMessage_m.h"

Define_Module(Gateway);

void Gateway::initialize() {

}

void Gateway::handleMessage(cMessage *msg) {

    if (msg->arrivedOn("gatewaySensorGate")) { // Checking the message which is coming from Sensor.
        send(msg, "User_Gate");                // Forwarding the message towards User(Module) gate.
    } else {
        delete msg;
    }
}
