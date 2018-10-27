#ifndef IPLUGIN_H
#define IPLUGIN_H

class IPlugin
{
public:
    IPlugin() { };
    virtual ~IPlugin() { };

    //I like return types
    virtual int initializeVR(void* udata = nullptr) = 0;
    virtual int submitVR(void* udata = nullptr) = 0;
    virtual int update(void* udata = nullptr) = 0;

};

typedef IPlugin* create_t();
typedef void destroy_t(IPlugin*);

#endif
