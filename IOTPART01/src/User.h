#ifndef __IOTPART01_USER_H_
#define __IOTPART01_USER_H_

#include <omnetpp.h>
#include <map>
#include <string>

using namespace omnetpp;

class User : public cSimpleModule
{
  private:
    std::map<std::string, simtime_t> lastMessageTime; // Map to track the last message time from each sensor
    simtime_t checkInterval;  // Interval at which to check sensor activity
    simtime_t sensorTimeout;  // Timeout to consider a sensor as inactive

  protected:
    virtual void initialize() override;
    virtual void handleMessage(cMessage *msg) override;

    // Method to check the activity of sensors
    void checkSensorActivity();
};

#endif // __IOTPART01_USER_H_
