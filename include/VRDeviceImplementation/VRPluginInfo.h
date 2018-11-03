#ifndef VR_PLUGIN_INFO_H
#define VR_PLUGIN_INFO_H

#include <VRDeviceImplementation/IVRDeviceImplementation.h> //need the type defs

namespace VR {
namespace Plugin {

class VRPluginInfo{
public:

    //VRPluginInfo(const char* location): location(location){ };
    VRPluginInfo() { };
    ~VRPluginInfo() { };

    //int findSymbols();
    int loadLib(const char* loc);
    int unloadLib();

    void* handle;
    const char* location;
    get_vr_interface_version_t* getVRAPIVersion;
    create_vrdevice_t* createVRDevice;
    destroy_vrdevice_t* destroyVRDevice;
    bool ready = false;

};


} // namespace VR
} // namespace Plugin

#endif
