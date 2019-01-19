#include <stdio.h>
//#include <VRDeviceImplementation/IVRDeviceImplementation.h>
//#include <VRDeviceImplementation/VRPluginInfo.h>
//#include <VRDeviceImplementation/VRPluginTypes.h>
#include <QtGui/QMatrix4x4>
#include <QPluginLoader>
//#include <QVRDeviceImplementation/QTestImplementation.h> //interface we expect
#include <VRDeviceImplementation/IVRDeviceImplementation.h>
//#include "q_plugin.h"

const char* PLUGIN_LOC = "/home/dmitri/Code/VR/qt3d_vr_deviceplugins/build/libqt_vrdevice_test.so";

//#include <iostream>
//#include <dlfcn.h>

int main(){

    printf("main\n");
    
    if(!QLibrary::isLibrary(PLUGIN_LOC)){
        printf("COULD NOT LOAD LIBRARY\n");
        return 1;
    }
    QPluginLoader pluginLoader(PLUGIN_LOC);
    QObject *plugin = pluginLoader.instance();

    if(!plugin){
        printf("COULD NOT INSTANCIATE PLUGIN\n");
        return 1;
    }

    VR::Plugin::IVRDeviceImplementation* vrDevice;
    vrDevice = qobject_cast<VR::Plugin::IVRDeviceImplementation*>(plugin);
    if(!vrDevice){
        printf("INVALID INTERFACE IMPLEMENTED BY PLUGIN \n");
        return 1;
    }

    QMatrix4x4 m;

    vrDevice->initializeVR();
    vrDevice->updateVR();
    vrDevice->getEyeProjection(VR::eyeLeft);
    vrDevice->getEyeProjection(VR::eyeRight);
    vrDevice->getEyePose(VR::eyeLeft);
    vrDevice->getEyePose(VR::eyeRight);
    m =vrDevice->getHmdPose();
    
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            printf("%0.3f, ",m(i,j));
        }
        printf("\n");
    }

    

    printf("natural exit\n");
    return 0;
}
