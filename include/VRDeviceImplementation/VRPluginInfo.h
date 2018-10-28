#ifndef VR_PLUGIN_INFO_H
#define VR_PLUGIN_INFO_H

#include <VRDeviceImplementation/IVRDeviceImplementation.h> //need the type defs

class VRPluginInfo{
public:

    VRPluginInfo(const char* location): location(location){ };
    ~VRPluginInfo() { };

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
