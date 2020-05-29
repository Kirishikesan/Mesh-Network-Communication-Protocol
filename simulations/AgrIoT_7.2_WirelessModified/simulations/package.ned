package agriot_7_2_wirelessmodified.simulations;

import inet.node.inet.WirelessHost;


@license(LGPL);
//
// TODO documentation
//
network Network
{
    @display("bgb=630,368");
    submodules:
        wirelessHost: WirelessHost {
            @display("p=128,121");
        }
}

