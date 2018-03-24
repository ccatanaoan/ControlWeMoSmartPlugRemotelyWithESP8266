
#ifndef b4r_main_h
#define b4r_main_h
class b4r_httpjob;
class _jobresult;

class b4r_main {
public:

static void initializeProcessGlobals();
static void _appstart();
static void _connect(Byte _unused);
static void _getwemostate();
static void _jobdone(_jobresult* _job);
static void _process_globals();
static B4R::Serial* _serial1;
static B4R::B4RESPWiFi* _wifi;
static B4R::WiFiSocket* _server;
static B4R::Array* _serverip;
static B4R::B4RString* _serverport;
static B4R::ByteConverter* _bc;
static B4R::B4RString* _getbinarystate;
static b4r_httpjob* _httpjob;
static void _setwemostate(Int _state);
};

#endif