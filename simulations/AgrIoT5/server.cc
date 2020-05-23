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
  int nodes=0;
  protected:
    virtual void initialize() override;
    virtual void handleMessage(cMessage *msg) override;

};

Define_Module(server);

void server::initialize()
{


    if (strcmp("host", getName()) == 0) {

        cMessage *msg = new cMessage("000");
        send(msg, "out");
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
           //string a="100"<<message.substr(3,8)<<id<<data;
           //string b=a<<(count(a, a + 11, "1")%2)*"1";
           cMessage *msg = new cMessage("101");
           send(msg,"out");
           counter++;

       }else if(counter==2){
           //string a="100"<<message.substr(3,8)<<id<<data;
           //string b=a<<(count(a, a + 11, "1")%2)*"1";
           cMessage *msg = new cMessage("101");
           send(msg,"out");
           counter++;

       }else if(counter==3){
           //string a="111"<<message.substr(3,8)<<id;
           //string b=a<<(count(a, a + 11, "1")%2)*"1";
           cMessage *msg = new cMessage("111");
           send(msg,"out");
           counter++;

       }
counter=0;
}
