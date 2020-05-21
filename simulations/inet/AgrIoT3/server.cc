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

class server : public cSimpleModule
{

    string [255][1000]={};
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
        string a="001"<<id;
        string b=a<<(count(a, a + 11, "1")%2)*"1";
        cMessage *msg = new cMessage(b);
        send(msg, "out");
    }
}

void server::handleMessage(cMessage *msg)
{
    if(msg.substr(0,3)=="010"){
        if(nodes==0){
            nodes=1;
            string a="011"<<id<<msg.substr(3,8);
            string b=a<<(count(a, a + 11, "1")%2)*"1";
            cMessage *msg = new cMessage(b);
            send(msg,"out");
        }else{
            nodes+=1;
            nodeids.push=msg.substr(3,8);
        }
    }else if(msg.substr(0,3)=="100"){
        string a="101"<<id<<msg.substr(3,8);
        string b=a<<(count(a, a + 11, "1")%2)*"1";
        cMessage *msg = new cMessage(b);
        send(msg,"out");
    }else if(msg.substr(0,3)=="111"){
        string a="111"<<id<<msg.substr(3,8);
        string b=a<<(count(a, a + 11, "1")%2)*"1";
        cMessage *msg = new cMessage(b);
        send(msg,"out");
    }
    //send(msg, "out"); // send out the message
}
