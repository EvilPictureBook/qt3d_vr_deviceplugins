#include <stdio.h>
#include <VRDeviceImplementation/plugin.h>

//need to call this in the implementation
VRDEVICE_PLUGIN(TestVRDeviceImplementation);

TestVRDeviceImplementation::TestVRDeviceImplementation(){
    printf("VR Constructor\n");
}
TestVRDeviceImplementation::~TestVRDeviceImplementation(){
    printf("VR Destructor\n");
}

int TestVRDeviceImplementation::initializeVR(void* udata){
    printf("VR Init\n");
    return 0;
}

int TestVRDeviceImplementation::submitVR(uintmax_t leftEyeTexID, uintmax_t rightEyeTexID, void* udata){
    printf("VR Submit: [%lu,%lu]\n",leftEyeTexID,rightEyeTexID);
    return 0;
}

int TestVRDeviceImplementation::update(void* udata){
    printf("VR Update\n");
    return 0;
}

int TestVRDeviceImplementation::shutdownVR(void* udata){
    printf("VR Shutdown\n");
    return 0;
}


int TestVRDeviceImplementation::shouldClose(){
    return false;
}

