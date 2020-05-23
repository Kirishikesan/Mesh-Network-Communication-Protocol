package agriot_6_2_ethernet.simulations;

import inet.linklayer.ethernet.EtherBus;
import inet.node.ethernet.EtherHost;
import inet.node.ethernet.EtherHost2;
import ned.DatarateChannel;


@license(LGPL);
//
// TODO documentation
//
network Network
{
    types:
        channel C extends DatarateChannel{
            delay=0.001s;
            datarate=10Mbps;
        }
    submodules:
        etherBus: EtherBus {
            parameters:
                propagationSpeed = 2e8 mps;
                positions = "1 2";
            gates:
                ethg[2];
        }
        etherHost: EtherHost {
            @display("p=134,51;b=12,6");
        }
        etherHost2: EtherHost2 {
            @display("p=300,265");
        }
    connections:
        etherHost.ethg <--> C <--> etherBus.ethg[0];
        etherBus.ethg[1] <--> C <--> etherHost2.ethg;
}

