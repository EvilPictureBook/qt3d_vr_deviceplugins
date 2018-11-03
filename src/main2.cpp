#include <stdio.h>
#include <VRDeviceImplementation/IVRDeviceImplementation.h>
#include <VRDeviceImplementation/VRPluginInfo.h>
//#include <iostream>
//#include <dlfcn.h>

int main(){

    printf("naim\n");

    VR::Plugin::VRPluginInfo pluginInfo;
    //VR::Plugin::VRPluginInfo pluginInfo("./libmy_plugin.so");
    //IVRPluginInfo pluginInfo("../bin/libmy_plugin.so");
    pluginInfo.loadLib("/home/dmitri/Code/plugin_test/bin/libmy_plugin.so");

    VR::Plugin::IVRDeviceImplementation* plug = pluginInfo.createVRDevice();

    plug->initializeVR();
    plug->update();
    plug->submitVR(1,2);
    plug->shutdownVR();

    pluginInfo.destroyVRDevice(plug);
    pluginInfo.unloadLib();
    //dlclose(pluginInfo.handle);

    return 0;
}
