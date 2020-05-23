package agriot_6_0.simulations;

import inet.examples.inet.ipv4hook.MyHost;
import inet.examples.inet.ipv4hook.MyRouter;
import inet.networklayer.configurator.ipv4.Ipv4FlatNetworkConfigurator;
import inet.node.ethernet.Eth100M;


@license(LGPL);
//
// TODO documentation
//
network Network
{
    parameters:
        int n;
        @display("bgb=396,249");
    submodules:

        Host[n]: MyHost {}
        

        Server: MyHost {
            @display("p=301,163");
        }
        Router: MyRouter {
            @display("p=182,128");
        }
        configurator: inet.networklayer.configurator.ipv4.Ipv4NetworkConfigurator {
            @display("p=271,32");
        }

    connections:
        for i=0..n-1 {
            Host[i].ethg++ <--> Eth100M <--> Router.ethg++;
        }
        Router.ethg++ <--> Eth100M <--> Server.ethg++;

}

