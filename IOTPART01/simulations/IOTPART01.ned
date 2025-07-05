package iotpart01.simulations;

import iotpart01.Gateway;
import iotpart01.User;
import iotpart01.Sensor;

network IOTPART01
{
    parameters:
        int numSensors = 5;
        @statistic[totalEnergyUsed](source=energyUsed; record=timeavg,stats,vector);
        @display("bgb=722,451");
    submodules:

        sensor[numSensors]: Sensor;
        gateway: Gateway {
            @display("p=351,228");
        }
        user: User {

            @display("p=351,32");
        }
    connections:
        gateway.User_Gate --> user.user_Gate;
}
