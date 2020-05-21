#include <string.h>
#include <omnetpp.h>

using namespace omnetpp;
using namespace std;

class client : public cSimpleModule
{
    string c1="000";
    string c2="001";
    string c3="010";
    string c4="011";
    string c5="100";
    string c6="101";
    string c7="110";
    string c8="111";
   string data="0010101010101010100101000011111111111100011111010101001010100101010101010010101";
   string id="00000001";
   string message;
   int counter=0;
    string convert(cMessage k);
  protected:
    virtual void initialize() override;
    virtual void handleMessage(cMessage *msg) override;
};

Define_Module(client);


void client::initialize()
{



}
void client::handleMessage(cMessage *msg)
{

    if(counter==0){
              //  string a=c2<<id;
               // string b=a<<(count(a, a + 11, "1")%2)*"1";
                cMessage *msg = new cMessage("001");
                send(msg,"out");
                counter++;
    }else if(counter==1){
        //string a="100"<<message.substr(3,8)<<id<<data;
        //string b=a<<(count(a, a + 11, "1")%2)*"1";
        cMessage *msg = new cMessage("100");
        send(msg,"out");
        counter++;

    }else if(counter==2){
        //string a="100"<<message.substr(3,8)<<id<<data;
        //string b=a<<(count(a, a + 11, "1")%2)*"1";
        cMessage *msg = new cMessage("100");
        send(msg,"out");
        counter++;

    }else if(counter==3){
        //string a="111"<<message.substr(3,8)<<id;
        //string b=a<<(count(a, a + 11, "1")%2)*"1";
        cMessage *msg = new cMessage("100");
        send(msg,"out");
        counter++;

    }
}

