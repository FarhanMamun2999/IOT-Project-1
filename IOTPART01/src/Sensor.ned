package iotpart01;

simple Sensor
{
    parameters:
        @signal[energyUsed](type=double);
        @display("i=device/accesspoint");
        bool startFirst = default(false);
        double initialEnergyLevel @unit("kolem") = default(10000kolem); // The initial energy level of the sensor
    gates:
        output sensorGate  @directIn;
}
