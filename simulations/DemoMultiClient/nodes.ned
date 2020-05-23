//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
// 
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Lesser General Public License for more details.
// 
// You should have received a copy of the GNU Lesser General Public License
// along with this program.  If not, see http://www.gnu.org/licenses/.
//
simple server
{
    gates:
        input in;
        input in2;
        input in3;
        input in4;
        output out;
        output out2;
        output out3;
        output out4;
}

simple client1
{
    gates:
        input in;
        output out;
}
simple client2
{
    gates:
        input in;
        output out;
}
simple client3
{
    gates:
        input in;
        output out;
}
simple client4
{
    gates:
        input in;
        output out;
}
//
// Two instances (tic and toc) of Txc1 connected both ways.
// Tic and toc will pass messages to one another.
//
network demonetwork
{
    @display("bgb=337,261");
    submodules:
        host: server {
            @display("p=154,123");
        }
        node1: client1 {
            @display("p=240,55");
        }
        node2: client2 {
            @display("p=63,199");
        }
        node3: client3 {
            @display("p=43,55");
        }
        node4: client4 {

            @display("p=223,188");
        }
    connections:
        host.out --> {  delay = 100ms; } --> node1.in;
        host.in <-- {  delay = 100ms; } <-- node1.out;
        host.out2 --> {  delay = 100ms; } --> node2.in;
        host.in2 <-- {  delay = 100ms; } <-- node2.out;
        host.out3 --> {  delay = 100ms; } --> node3.in;
        host.in3 <-- {  delay = 100ms; } <-- node3.out;
        host.out4 --> {  delay = 100ms; } --> node4.in;
        host.in4 <-- {  delay = 100ms; } <-- node4.out;
}
