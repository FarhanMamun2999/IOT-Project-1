package iotpart01;


simple Gateway
{
    parameters:
        @display("i=abstract/accesspoint");

    gates:
        input gatewaySensorGate @directIn;
        output User_Gate;
}
