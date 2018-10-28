#ifndef IVR_PLUGIN_INFO_H
#define IVR_PLUGIN_INFO_H

#include <VRDeviceImplementation/IVRDeviceImplementation.h> //need the type defs

class IVRPluginInfo{
public:

    IVRPluginInfo(const char* location): location(location){ };
    ~IVRPluginInfo() { };

    //int findSymbols();
    int loadLib();

    void* handle;
    const char* location;
    get_vr_interface_version_t* getVRAPIVersion;
    create_vrdevice_t* createVRDevice;
    destroy_vrdevice_t* destroyVRDevice;
    bool ready = false;

};

#endif
