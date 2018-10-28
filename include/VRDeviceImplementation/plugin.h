#ifndef TEST_VRDEVICE_IMPLEMENTATION_H
#define TEST_VRDEVICE_IMPLEMENTATION_H

#include <VRDeviceImplementation/IVRDeviceImplementation.h>

class TestVRDeviceImplementation : public IVRDeviceImplementation
{
public:
    TestVRDeviceImplementation ();
    ~TestVRDeviceImplementation ();

    int initializeVR(void* udata=nullptr);
    int submitVR(uintmax_t leftEyeTexID, uintmax_t rightEyeTexID, void* udata = nullptr);
    int update(void* udata=nullptr);
    int shutdownVR(void* udata = nullptr);

};


struct export_stuff{
    IVRDeviceImplementation* (*create_vrd)(void);
    void (*destroy_vrd)(IVRDeviceImplementation *p);
};

#endif
