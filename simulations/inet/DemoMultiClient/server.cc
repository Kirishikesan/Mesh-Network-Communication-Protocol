#include <string.h>
#include <omnetpp.h>

using namespace omnetpp;
using namespace std;
#include <string.h>
#include <omnetpp.h>

using namespace omnetpp;
using namespace std;

class server : public cSimpleModule
{
    string c1="000";
        string c2="001";
        string c3="010";
        string c4="011";
        string c5="100";
        string c6="101";
        string c7="110";
        string c8="111";
    int counter=0;
  string id="00000000";
  string nodeids[255]={};
  protected:
    virtual void initialize() override;
    virtual void handleMessage(cMessage *msg) override;

};

Define_Module(server);

void server::initialize()
{


    if (strcmp("host", getName()) == 0) {

        cMessage *msg = new cMessage("000");
        cMessage *msg1 = new cMessage("000");

        cMessage *msg2 = new cMessage("000");

        cMessage *msg3 = new cMessage("000");

        send(msg, "out");
        send(msg1, "out2");
        send(msg2, "out3");
        send(msg3, "out4");
    }
}

void server::handleMessage(cMessage *msg)
{
    if(counter==0){
                 //  string a=c2<<id;
                  // string b=a<<(count(a, a + 11, "1")%2)*"1";
                   cMessage *msg = new cMessage("011");
                   send(msg,"out");
                   counter++;
       }else if(counter==1){
           counter++;

       }else if(counter==2){
           counter++;

       }else if(counter==3){
           counter++;

       }else if(counter==4){
           //string a="100"<<message.substr(3,8)<<id<<data;
           //string b=a<<(count(a, a + 11, "1")%2)*"1";
           cMessage *msg = new cMessage("101");
           send(msg,"out");
           counter++;

       }else if(counter==5){
           //string a="100"<<message.substr(3,8)<<id<<data;
           //string b=a<<(count(a, a + 11, "1")%2)*"1";
           cMessage *msg = new cMessage("101");
           send(msg,"out");
           counter++;

       }else if(counter==6){
           //string a="111"<<message.substr(3,8)<<id;
           //string b=a<<(count(a, a + 11, "1")%2)*"1";
           cMessage *msg = new cMessage("111");
           send(msg,"out");
           counter++;

       }else if(counter==7){
           //string a="100"<<message.substr(3,8)<<id<<data;
           //string b=a<<(count(a, a + 11, "1")%2)*"1";
           cMessage *msg = new cMessage("101");
           send(msg,"out2");
           counter++;

       }else if(counter==8){
           //string a="100"<<message.substr(3,8)<<id<<data;
           //string b=a<<(count(a, a + 11, "1")%2)*"1";
           cMessage *msg = new cMessage("101");
           send(msg,"out2");
           counter++;

       }else if(counter==9){
           //string a="111"<<message.substr(3,8)<<id;
           //string b=a<<(count(a, a + 11, "1")%2)*"1";
           cMessage *msg = new cMessage("111");
           send(msg,"out2");
           counter++;

       }else if(counter==10){
           //string a="100"<<message.substr(3,8)<<id<<data;
           //string b=a<<(count(a, a + 11, "1")%2)*"1";
           cMessage *msg = new cMessage("101");
           send(msg,"out3");
           counter++;

       }else if(counter==11){
           //string a="100"<<message.substr(3,8)<<id<<data;
           //string b=a<<(count(a, a + 11, "1")%2)*"1";
           cMessage *msg = new cMessage("101");
           send(msg,"out3");
           counter++;

       }else if(counter==12){
           //string a="111"<<message.substr(3,8)<<id;
           //string b=a<<(count(a, a + 11, "1")%2)*"1";
           cMessage *msg = new cMessage("111");
           send(msg,"out3");
           counter++;

       }else if(counter==13){
           //string a="100"<<message.substr(3,8)<<id<<data;
           //string b=a<<(count(a, a + 11, "1")%2)*"1";
           cMessage *msg = new cMessage("101");
           send(msg,"out4");
           counter++;

       }else if(counter==14){
           //string a="100"<<message.substr(3,8)<<id<<data;
           //string b=a<<(count(a, a + 11, "1")%2)*"1";
           cMessage *msg = new cMessage("101");
           send(msg,"out4");
           counter++;

       }else if(counter==15){
           //string a="111"<<message.substr(3,8)<<id;
           //string b=a<<(count(a, a + 11, "1")%2)*"1";
           cMessage *msg = new cMessage("111");
           send(msg,"out4");
           counter++;

       }
}
