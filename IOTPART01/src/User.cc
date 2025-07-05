#include "User.h"
#include "SensorMessage_m.h"

Define_Module(User);

void User::initialize() {

}

void User::handleMessage(cMessage *msg) {
    if (msg->arrivedOn("user_Gate")) {                                          //arrive Packet from Gateway
        SensorMessage *sensorMsg = dynamic_cast<SensorMessage *>(msg);
        if (sensorMsg != nullptr) {

            EV << "Sensor Name: " << sensorMsg->getSensorName() << endl;                                    // Get Sensor Name From the Packet
            EV << "Sensed Time: " << sensorMsg->getSensedTime() << endl;                                    // Get Sensed Time From the Packet
            EV << "Air Humidity data: " << sensorMsg->getAirHumidityValue() << " %" << endl;                // Get Air Humidity From the Packet
            EV << "Air Temperature data: " << sensorMsg->getAirTemperatureValue() << " 'C" << endl;         // Get Air Temperature From the Packet
            EV << "Soil Temperature data: " << sensorMsg->getAirTemperatureValue() << " 'C" << endl;        // Get Soil Temperature From the Packet
            EV << "Soil Moisture data: " << sensorMsg->getSoilDampnessValue() << " ' %" << endl;             // Get Soil Moisture From the Packet
            EV << "Current Energy Level: " << sensorMsg->getCurrentEnergyLevel() << " kolems" << endl;      // Get Energy Level From the Packet

            // Calculate the Interval time between 2 simulation
            simtime_t currentTime = simTime();                                   // Get the current simulation time
            std::string sensorName = sensorMsg->getSensorName();                 // Get the sensor name
            if (lastMessageTime.find(sensorName) != lastMessageTime.end()) {     // Check The Previous Record Time of the Sensor
                simtime_t lastTime = lastMessageTime[sensorName];                // Get the time difference by comparing the current time
                EV << "Time since last message from " << sensorName << ": " << (currentTime - lastTime) << "s" << endl;
            } else {
                EV << " First Message Generated From Sensor (0sec) " << sensorName << endl;
            }
            lastMessageTime[sensorName] = currentTime;                            // Update the last received time for this sensor
        }
    }

    if (!msg->isSelfMessage()) {
        delete msg; // Delete the received message
    }
}
