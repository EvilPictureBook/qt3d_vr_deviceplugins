#include <stdio.h>
#include <plugin/plugin.h>

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

//extern "C" IVRDeviceImplementation* create_plugin(){return new TestVRDeviceImplementation ;}
//extern "C" void destroy_plugin(IVRDeviceImplementation *p){ delete p;}
//extern "C" int get_vr_interface_version(){return I_VRDEVICE_API_VERSION;}


