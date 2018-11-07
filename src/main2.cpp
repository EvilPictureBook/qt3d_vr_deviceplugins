#include <stdio.h>
#include <VRDeviceImplementation/IVRDeviceImplementation.h>
#include <VRDeviceImplementation/VRPluginInfo.h>
//#include <VRDeviceImplementation/VRPluginTypes.h>
#include <QtGui/QMatrix4x4>

//#include <iostream>
//#include <dlfcn.h>

int main(){

    printf("naim\n");

    VR::Plugin::VRPluginInfo pluginInfo;
    //VR::Plugin::VRPluginInfo pluginInfo("./libmy_plugin.so");
    //IVRPluginInfo pluginInfo("../bin/libmy_plugin.so")a;
    //pluginInfo.loadLib("/home/dmitri/Code/plugin_test/bin/libmy_plugin.so");
    pluginInfo.loadLib("./libmy_plugin.so");

    VR::Plugin::IVRDeviceImplementation* plug = pluginInfo.createVRDevice();


    QMatrix4x4 m;

    plug->initializeVR();
    plug->updateVR();
    plug->getEyeProjection(VR::eyeLeft);
    plug->getEyeProjection(VR::eyeRight);
    plug->getEyePose(VR::eyeLeft);
    plug->getEyePose(VR::eyeRight);
    m = plug->getHmdPose();
    
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            printf("%f, ",m.column(i)[j]);
        }
        printf("\n");
    }
    
    plug->submitVR(1,2);
    plug->shutdownVR();

    pluginInfo.destroyVRDevice(plug);
    pluginInfo.unloadLib();
    //dlclose(pluginInfo.handle);
    //

    return 0;
}
