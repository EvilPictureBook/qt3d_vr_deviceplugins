#ifndef I_VRDEVICE_IMPLEMENTATION_H
#define I_VRDEVICE_IMPLEMENTATION_H

#define I_VRDEVICE_API_VERSION 7

// probably need this, and this is probably correct...
//#ifdef WIN32
//#define I_VRDEVICE_EXPORT __declspec(dllexport)
//#else
//#define I_VRDEVICE_EXPORT
//#endif

#include <cstdint> //don't really want to have this here either...but w/e

class IVRDeviceImplementation
{
public:
    IVRDeviceImplementation() { };
    virtual ~IVRDeviceImplementation() { };

    //I like return types
    virtual int initializeVR(void* udata = nullptr) = 0;
    virtual int submitVR(uintmax_t leftEyeTexID, uintmax_t rightEyeTexID, void* udata = nullptr) = 0;
    virtual int update(void* udata = nullptr) = 0;
    virtual int shutdownVR(void* udata = nullptr) = 0;

};

//types
typedef IVRDeviceImplementation* create_vrdevice_t();
typedef void destroy_vrdevice_t(IVRDeviceImplementation*);
typedef int get_vr_interface_version_t();


// small macro to make sure the user doesn't have to do too much
// maybe do this with a struct ???
#define VRDEVICE_PLUGIN(typename)                                               \
    extern "C" IVRDeviceImplementation* create_vrdevice(){return new typename;} \
    extern "C" void destroy_vrdevice(IVRDeviceImplementation *p){ delete p;}    \
    extern "C" int get_vr_interface_version(){return I_VRDEVICE_API_VERSION;}

#endif
