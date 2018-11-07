#ifndef TEST_VRDEVICE_IMPLEMENTATION_H
#define TEST_VRDEVICE_IMPLEMENTATION_H

#include <VRDeviceImplementation/IVRDeviceImplementation.h>
#include <VRDeviceImplementation/VRPluginTypes.h>

class TestVRDeviceImplementation : public VR::Plugin::IVRDeviceImplementation
{
public:
    TestVRDeviceImplementation ();
    ~TestVRDeviceImplementation ();

    int initializeVR(void* udata=nullptr);
    int submitVR(uintmax_t leftEyeTexID, uintmax_t rightEyeTexID, void* udata = nullptr);
    int updateVR(void* udata=nullptr);
    int shutdownVR(void* udata = nullptr);
    int shouldClose();

    //need to get left and right eye matrices
    virtual VR::mat44_t getEyeProjection(VR::eyeId eye);

    //need to get hmd pose, left eye pose, right eye pose
    virtual VR::mat44_t getEyePose(VR::eyeId eye);
    virtual VR::mat44_t getHmdPose();

private:
    VR::mat44_t mat;

};

#endif
