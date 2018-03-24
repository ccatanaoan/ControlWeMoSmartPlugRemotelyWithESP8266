#include "B4RDefines.h"

B4R::Serial* b4r_main::_serial1;
B4R::B4RESPWiFi* b4r_main::_wifi;
B4R::WiFiSocket* b4r_main::_server;
B4R::Array* b4r_main::_serverip;
B4R::B4RString* b4r_main::_serverport;
B4R::ByteConverter* b4r_main::_bc;
B4R::B4RString* b4r_main::_getbinarystate;
b4r_httpjob* b4r_main::_httpjob;
static B4R::Serial be_gann1_3;
static B4R::B4RESPWiFi be_gann2_3;
static B4R::WiFiSocket be_gann3_3;
static Byte be_gann4_19e1[4];
static B4R::Array be_gann4_19e2;
static B4R::B4RString be_gann5_5;
static B4R::ByteConverter be_gann6_3;
static B4R::B4RString be_gann7_5;


 void b4r_main::_appstart(){
const UInt cp = B4R::StackMemory::cp;
B4R::B4RString be_ann13_5;
B4R::B4RString be_ann13_7;
 //BA.debugLineNum = 25;BA.debugLine="Private Sub AppStart";
 //BA.debugLineNum = 26;BA.debugLine="Serial1.Initialize(115200)";
b4r_main::_serial1->Initialize((ULong) (115200));
 //BA.debugLineNum = 27;BA.debugLine="Delay(3000)";
Common_Delay((ULong) (3000));
 //BA.debugLineNum = 28;BA.debugLine="Log(\"AppStart\")";
B4R::Common::LogHelper(1,102,F("AppStart"));
 //BA.debugLineNum = 29;BA.debugLine="If WiFi.Connect2(\"Rise Above This Home\",\"SteelRes";
if (b4r_main::_wifi->Connect2(be_ann13_5.wrap("Rise Above This Home"),be_ann13_7.wrap("SteelReserve"))) { 
 //BA.debugLineNum = 30;BA.debugLine="Log(\"Connected to router.\")";
B4R::Common::LogHelper(1,102,F("Connected to router."));
 }else {
 //BA.debugLineNum = 32;BA.debugLine="Log(\"Failed to connect to router.\")";
B4R::Common::LogHelper(1,102,F("Failed to connect to router."));
 //BA.debugLineNum = 33;BA.debugLine="Return";
B4R::StackMemory::cp = cp;
if (true) return ;
 };
 //BA.debugLineNum = 36;BA.debugLine="Connect(0)";
_connect((Byte) (0));
 //BA.debugLineNum = 37;BA.debugLine="End Sub";
B4R::StackMemory::cp = cp;
}
void b4r_main::_connect(Byte _unused){
const UInt cp = B4R::StackMemory::cp;
 //BA.debugLineNum = 39;BA.debugLine="Sub Connect(unused As Byte)";
 //BA.debugLineNum = 40;BA.debugLine="If server.ConnectIP(serverIp,serverPort) Then";
if (b4r_main::_server->ConnectIP(b4r_main::_serverip,(UInt)(atof(b4r_main::_serverport->data)))) { 
 //BA.debugLineNum = 41;BA.debugLine="Log(\"Connected to Wemo\")";
B4R::Common::LogHelper(1,102,F("Connected to Wemo"));
 //BA.debugLineNum = 42;BA.debugLine="GetWemoState";
_getwemostate();
 }else {
 //BA.debugLineNum = 44;BA.debugLine="Log(\"Connection failed\")";
B4R::Common::LogHelper(1,102,F("Connection failed"));
 //BA.debugLineNum = 45;BA.debugLine="CallSubPlus(\"Connect\", 2000, 0)";
B4R::__c->CallSubPlus(_connect,(ULong) (2000),(Byte) (0));
 };
 //BA.debugLineNum = 47;BA.debugLine="End Sub";
B4R::StackMemory::cp = cp;
}
void b4r_main::_getwemostate(){
const UInt cp = B4R::StackMemory::cp;
B4R::B4RString be_ann50_4;
B4R::B4RString be_ann51_4;
B4R::B4RString be_ann51_6;
B4R::B4RString be_ann52_4;
B4R::B4RString be_ann52_6;
B4R::B4RString be_ann53_12;
B4R::B4RString be_ann53_19;
B4R::B4RString be_ann53_26;
B4R::B4RString be_ann53_33;
B4R::B4RString be_ann53_40;
B4R::B4RString be_ann53_44;
B4R::B4RString* be_ann53_45e1[11];
B4R::Array be_ann53_45e2;
 //BA.debugLineNum = 69;BA.debugLine="Sub GetWemoState()";
 //BA.debugLineNum = 70;BA.debugLine="HttpJob.Initialize(\"WeMo\")";
b4r_main::_httpjob->_initialize(be_ann50_4.wrap("WeMo"));
 //BA.debugLineNum = 71;BA.debugLine="HttpJob.AddHeader(\"Content-type\", \"text/xml; char";
b4r_main::_httpjob->_addheader((be_ann51_4.wrap("Content-type"))->GetBytes(),(be_ann51_6.wrap("text/xml; charset=\"utf-8\""))->GetBytes());
 //BA.debugLineNum = 72;BA.debugLine="HttpJob.AddHeader(\"SOAPACTION\", \"\"\"urn:Belkin:ser";
b4r_main::_httpjob->_addheader((be_ann52_4.wrap("SOAPACTION"))->GetBytes(),(be_ann52_6.wrap("\"urn:Belkin:service:basicevent:1#GetBinaryState\""))->GetBytes());
 //BA.debugLineNum = 73;BA.debugLine="HttpJob.Post(JoinStrings(Array As String(\"http://";
b4r_main::_httpjob->_post((B4R::__c->JoinStrings(be_ann53_45e2.create(be_ann53_45e1,11,100,be_ann53_12.wrap("http://"),B4R::B4RString::fromNumber((Long)(((Byte*)b4r_main::_serverip->getData((UInt) (0)))[B4R::Array::staticIndex])),be_ann53_19.wrap("."),B4R::B4RString::fromNumber((Long)(((Byte*)b4r_main::_serverip->getData((UInt) (1)))[B4R::Array::staticIndex])),be_ann53_26.wrap("."),B4R::B4RString::fromNumber((Long)(((Byte*)b4r_main::_serverip->getData((UInt) (2)))[B4R::Array::staticIndex])),be_ann53_33.wrap("."),B4R::B4RString::fromNumber((Long)(((Byte*)b4r_main::_serverip->getData((UInt) (3)))[B4R::Array::staticIndex])),be_ann53_40.wrap(":"),b4r_main::_serverport,be_ann53_44.wrap("/upnp/control/basicevent1"))))->GetBytes(),(b4r_main::_getbinarystate)->GetBytes());
 //BA.debugLineNum = 74;BA.debugLine="End Sub";
B4R::StackMemory::cp = cp;
}
void b4r_main::_jobdone(_jobresult* _job){
const UInt cp = B4R::StackMemory::cp;
B4R::B4RString be_ann33_9;
B4R::B4RString be_ann36_9;
B4R::Object be_ann44_6;
B4R::Object be_ann46_4;
 //BA.debugLineNum = 49;BA.debugLine="Sub JobDone (Job As JobResult)";
 //BA.debugLineNum = 50;BA.debugLine="Log(\"*******************************\")";
B4R::Common::LogHelper(1,102,F("*******************************"));
 //BA.debugLineNum = 51;BA.debugLine="If Job.Success Then";
if (_job->Success) { 
 //BA.debugLineNum = 52;BA.debugLine="If bc.IndexOf(Job.Response,\"<BinaryState>1</Bina";
if (b4r_main::_bc->IndexOf(_job->Response,(be_ann33_9.wrap("<BinaryState>1</BinaryState>"))->GetBytes())>-1) { 
 //BA.debugLineNum = 53;BA.debugLine="Log(\"Wemo is ON\")";
B4R::Common::LogHelper(1,102,F("Wemo is ON"));
 //BA.debugLineNum = 54;BA.debugLine="SetWemoState(0)";
_setwemostate(0);
 }else if(b4r_main::_bc->IndexOf(_job->Response,(be_ann36_9.wrap("<BinaryState>0</BinaryState>"))->GetBytes())>-1) { 
 //BA.debugLineNum = 56;BA.debugLine="Log(\"Wemo is OFF\")";
B4R::Common::LogHelper(1,102,F("Wemo is OFF"));
 //BA.debugLineNum = 57;BA.debugLine="SetWemoState(1)";
_setwemostate(1);
 }else {
 //BA.debugLineNum = 59;BA.debugLine="Log(\"Unknown\")";
B4R::Common::LogHelper(1,102,F("Unknown"));
 //BA.debugLineNum = 60;BA.debugLine="SetWemoState(0)";
_setwemostate(0);
 };
 }else {
 //BA.debugLineNum = 63;BA.debugLine="Log(\"ErrorMessage: \", Job.ErrorMessage)";
B4R::Common::LogHelper(2,102,F("ErrorMessage: "),100,be_ann44_6.wrapPointer(_job->ErrorMessage));
 //BA.debugLineNum = 64;BA.debugLine="Log(\"Status: \", Job.Status)";
B4R::Common::LogHelper(2,102,F("Status: "),3,_job->Status);
 //BA.debugLineNum = 65;BA.debugLine="Log(Job.Response)";
B4R::Common::LogHelper(1,100,be_ann46_4.wrapPointer(_job->Response));
 };
 //BA.debugLineNum = 67;BA.debugLine="End Sub";
B4R::StackMemory::cp = cp;
}

void b4r_main::initializeProcessGlobals() {
     B4R::StackMemory::buffer = (byte*)malloc(STACK_BUFFER_SIZE);
     b4r_main::_process_globals();
b4r_httpjob::_process_globals();

   
}
void b4r_main::_process_globals(){
const UInt cp = B4R::StackMemory::cp;
 //BA.debugLineNum = 11;BA.debugLine="Sub Process_Globals";
 //BA.debugLineNum = 14;BA.debugLine="Public Serial1 As Serial";
b4r_main::_serial1 = &be_gann1_3;
 //BA.debugLineNum = 15;BA.debugLine="Public WiFi As ESP8266WiFi";
b4r_main::_wifi = &be_gann2_3;
 //BA.debugLineNum = 16;BA.debugLine="Private server As WiFiSocket";
b4r_main::_server = &be_gann3_3;
 //BA.debugLineNum = 17;BA.debugLine="Private serverIp() As Byte = Array As Byte(192, 1";
b4r_main::_serverip = be_gann4_19e2.create(be_gann4_19e1,4,1,(Byte) (192),(Byte) (168),(Byte) (0),(Byte) (23));
 //BA.debugLineNum = 18;BA.debugLine="Private const serverPort As String = \"49153\"";
b4r_main::_serverport = be_gann5_5.wrap("49153");
 //BA.debugLineNum = 19;BA.debugLine="Private bc As ByteConverter";
b4r_main::_bc = &be_gann6_3;
 //BA.debugLineNum = 20;BA.debugLine="Private GetBinaryState As String =\"<s:Envelope xm";
b4r_main::_getbinarystate = be_gann7_5.wrap("<s:Envelope xmlns:s=\"http://schemas.xmlsoap.org/soap/envelope/\" s:encodingStyle=\"http://schemas.xmlsoap.org/soap/encoding/\"><s:Body><u:GetBinaryState xmlns:u=\"urn:Belkin:service:basicevent:1\"></u:GetBinaryState></s:Body></s:Envelope>");
 //BA.debugLineNum = 23;BA.debugLine="End Sub";
}
void b4r_main::_setwemostate(Int _state){
const UInt cp = B4R::StackMemory::cp;
B4R::B4RString be_ann58_4;
B4R::B4RString be_ann59_4;
B4R::B4RString be_ann59_6;
B4R::B4RString be_ann60_4;
B4R::B4RString be_ann60_6;
B4R::B4RString be_ann66_12;
B4R::B4RString be_ann66_19;
B4R::B4RString be_ann66_26;
B4R::B4RString be_ann66_33;
B4R::B4RString be_ann66_40;
B4R::B4RString be_ann66_44;
B4R::B4RString* be_ann66_45e1[11];
B4R::Array be_ann66_45e2;
B4R::B4RString be_ann66_56;
B4R::B4RString be_ann66_60;
B4R::B4RString* be_ann66_61e1[3];
B4R::Array be_ann66_61e2;
 //BA.debugLineNum = 76;BA.debugLine="Sub SetWemoState(state As Int)";
 //BA.debugLineNum = 77;BA.debugLine="Delay(10000)";
Common_Delay((ULong) (10000));
 //BA.debugLineNum = 78;BA.debugLine="If server.Connected Then";
if (b4r_main::_server->getConnected()) { 
 //BA.debugLineNum = 79;BA.debugLine="HttpJob.Initialize(\"WeMo\")";
b4r_main::_httpjob->_initialize(be_ann58_4.wrap("WeMo"));
 //BA.debugLineNum = 80;BA.debugLine="HttpJob.AddHeader(\"Content-type\", \"text/xml; cha";
b4r_main::_httpjob->_addheader((be_ann59_4.wrap("Content-type"))->GetBytes(),(be_ann59_6.wrap("text/xml; charset=\"utf-8\""))->GetBytes());
 //BA.debugLineNum = 81;BA.debugLine="HttpJob.AddHeader(\"SOAPACTION\", \"\"\"urn:Belkin:se";
b4r_main::_httpjob->_addheader((be_ann60_4.wrap("SOAPACTION"))->GetBytes(),(be_ann60_6.wrap("\"urn:Belkin:service:basicevent:1#SetBinaryState\""))->GetBytes());
 //BA.debugLineNum = 82;BA.debugLine="If state = 1 Then";
if (_state==1) { 
 //BA.debugLineNum = 83;BA.debugLine="Log(\"Wemo switched ON\")";
B4R::Common::LogHelper(1,102,F("Wemo switched ON"));
 }else {
 //BA.debugLineNum = 85;BA.debugLine="Log(\"Wemo switched OFF\")";
B4R::Common::LogHelper(1,102,F("Wemo switched OFF"));
 };
 //BA.debugLineNum = 87;BA.debugLine="HttpJob.Post(JoinStrings(Array As String(\"http:/";
b4r_main::_httpjob->_post((B4R::__c->JoinStrings(be_ann66_45e2.create(be_ann66_45e1,11,100,be_ann66_12.wrap("http://"),B4R::B4RString::fromNumber((Long)(((Byte*)b4r_main::_serverip->getData((UInt) (0)))[B4R::Array::staticIndex])),be_ann66_19.wrap("."),B4R::B4RString::fromNumber((Long)(((Byte*)b4r_main::_serverip->getData((UInt) (1)))[B4R::Array::staticIndex])),be_ann66_26.wrap("."),B4R::B4RString::fromNumber((Long)(((Byte*)b4r_main::_serverip->getData((UInt) (2)))[B4R::Array::staticIndex])),be_ann66_33.wrap("."),B4R::B4RString::fromNumber((Long)(((Byte*)b4r_main::_serverip->getData((UInt) (3)))[B4R::Array::staticIndex])),be_ann66_40.wrap(":"),b4r_main::_serverport,be_ann66_44.wrap("/upnp/control/basicevent1"))))->GetBytes(),(B4R::__c->JoinStrings(be_ann66_61e2.create(be_ann66_61e1,3,100,be_ann66_56.wrap("<s:Envelope xmlns:s=\"http://schemas.xmlsoap.org/soap/envelope/\" s:encodingStyle=\"http://schemas.xmlsoap.org/soap/encoding/\"><s:Body><u:SetBinaryState xmlns:u=\"urn:Belkin:service:basicevent:1\"><BinaryState>"),B4R::B4RString::fromNumber((Long)(_state)),be_ann66_60.wrap("</BinaryState></u:SetBinaryState></s:Body></s:Envelope>"))))->GetBytes());
 };
 //BA.debugLineNum = 89;BA.debugLine="End Sub";
B4R::StackMemory::cp = cp;
}
