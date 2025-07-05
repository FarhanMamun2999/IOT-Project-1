#include "Sensor.h"
#include "SensorMessage_m.h"


Define_Module(Sensor);

void Sensor::initialize() {
    simtime_t startTime = uniform(10, 15);
    scheduleAt(startTime, new cMessage("start"));
    energyUsedSignal = registerSignal("energyUsed");
    energyLevel = par("initialEnergyLevel").doubleValue();  // Initial Energy Level

}

void Sensor::handleMessage(cMessage *msg) {
    if (msg->isSelfMessage() && energyLevel > 0) {    // Check if their is the energy to transmit data

        double energyConsumed = uniform(0.5, 0.7);    // Energy consumption per message
        energyLevel -= energyConsumed;

        const char* sensorId = getFullName();         // Write the Sensor Full Name
        double sensedTime = simTime().dbl();          // write the Sensor Operating Time
        double airHumidity = uniform(50, 52);         // Air humidity level (50% - 52%)
        double airTemperature = uniform(21, 23);      // Air temperature (21°C - 23°C)
        double soilMoisture = uniform(90, 93);        // Soil moisture level (90% - 93%)
        double soilTemperature = uniform(23, 26);     // Soil temperature (23°C - 26°C)
        emit(energyUsedSignal, energyLevel);


        SensorMessage *sensorMsg = new SensorMessage("Packet"); // Create a SensorMessage with the sensed data
        sensorMsg->setSensorName(sensorId);                     // Set the sensor ID in the message
        sensorMsg->setSensedTime(sensedTime);                   // Store the sensing time in the message
        sensorMsg->setAirHumidityValue(airHumidity);            // Store the Air Humidity in the message
        sensorMsg->setAirTemperatureValue(airTemperature);      // Store the Air Temperature in the message
        sensorMsg->setSoilDampnessValue(soilMoisture);          // Store the Soil Moisture in the message
        sensorMsg->setSoilTemperatureValue(soilTemperature);    // Store the Soil Temperature in the message
        sensorMsg->setCurrentEnergyLevel(energyLevel);          // Set the current energy level in the message
        if (energyLevel <= 0) {                                 // Check if there is enough power or not
            EV << sensorId << ": System ShutDown." << endl;
            delete sensorMsg;                                   // Important to avoid memory leak
            delete msg;
            return;                                             // Stop further processing as energy is depleted
        }
       sendDirect(sensorMsg, getParentModule()->getSubmodule("gateway"), "gatewaySensorGate");  // Send the SensorMessage directly to the gateway
        simtime_t interval = uniform(10, 11);                                                   // Schedule the next sensing event
        scheduleAt(simTime() + interval, new cMessage("start"));

    }
    delete msg;                                                                                 // Delete the received message
}
