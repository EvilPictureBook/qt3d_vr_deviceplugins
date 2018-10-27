#include <plugin/IPlugin.h>

class PluginImplementation : public IPlugin
{
public:
    PluginImplementation();
    ~PluginImplementation();

    int initializeVR(void* udata=nullptr);
    int submitVR(void* udata=nullptr);
    int update(void* udata=nullptr);

};

//extern "C" IPlugin * create_plugin(){return new PluginImplementation;}
//extern "C" void destroy_plugin(IPlugin *p){ delete p;}
