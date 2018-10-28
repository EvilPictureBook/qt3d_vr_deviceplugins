#include <stdio.h>
#include <VRDeviceImplementation/IVRDeviceImplementation.h>
#include <VRDeviceImplementation/IVRPluginInfo.h>
#include <iostream>
#include <dlfcn.h>

int main(){

    printf("naim\n");

    IVRPluginInfo pluginInfo("./libmy_plugin.so");
    //IVRPluginInfo pluginInfo("../bin/libmy_plugin.so");
    pluginInfo.loadLib();

    IVRDeviceImplementation* plug = pluginInfo.createVRDevice();

    plug->initializeVR();
    plug->update();
    plug->submitVR(1,2);
    plug->shutdownVR();

    pluginInfo.destroyVRDevice(plug);
    dlclose(pluginInfo.handle);

    return 0;
}
