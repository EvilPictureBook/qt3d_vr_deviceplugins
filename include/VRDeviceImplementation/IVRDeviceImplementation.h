#ifndef I_VRDEVICE_IMPLEMENTATION_H
#define I_VRDEVICE_IMPLEMENTATION_H

#define I_VRDEVICE_API_VERSION 1

// probably need this, and this is probably correct...
//#ifdef WIN32
//#define I_VRDEVICE_EXPORT __declspec(dllexport)
//#else
//#define I_VRDEVICE_EXPORT
//#endif

#include <cstdint> //don't really want to have this here either...but w/e
#include <QtGui/QMatrix4x4>
//#include <VRDeviceImplementation/VRPluginTypes.h>

namespace VR {

enum eyeId{
    eyeLeft = 0,
    eyeRight = 1
};

namespace Plugin {

class IVRDeviceImplementation
{
public:
    IVRDeviceImplementation() { };
    virtual ~IVRDeviceImplementation() { };

    //I like return types
    virtual int initializeVR(void* udata = nullptr) = 0;
    virtual int submitVR(uintmax_t leftEyeTexID, uintmax_t rightEyeTexID, void* udata = nullptr) = 0;
    virtual int updateVR(void* udata = nullptr) = 0;
    virtual int shutdownVR(void* udata = nullptr) = 0;
    virtual int shouldClose() = 0;

    //need to get left and right eye matrices
    virtual QMatrix4x4 getEyeProjection(eyeId eye)=0;
    virtual QMatrix4x4 getEyePose(eyeId eye)=0;
    virtual QMatrix4x4 getHmdPose()=0;

    //TODO: add hand pose and button states, etc...

};

//types
typedef IVRDeviceImplementation* create_vrdevice_t();
typedef void destroy_vrdevice_t(IVRDeviceImplementation*);
typedef int get_vr_interface_version_t();


// small macro to make sure the user doesn't have to do too much
// maybe do this with a struct ???
#define VRDEVICE_PLUGIN(typename)                                               \
    extern "C" VR::Plugin::IVRDeviceImplementation* create_vrdevice(){return new typename;} \
    extern "C" void destroy_vrdevice(VR::Plugin::IVRDeviceImplementation *p){ delete p;}    \
    extern "C" int get_vr_interface_version(){return I_VRDEVICE_API_VERSION;}

} // namespace VR
} //namespace Plugin

#endif
