#include <stdio.h>
//#include <VRDeviceImplementation/IVRDeviceImplementation.h>
//#include <VRDeviceImplementation/VRPluginInfo.h>
//#include <VRDeviceImplementation/VRPluginTypes.h>
#include <QtGui/QMatrix4x4>
#include <QPluginLoader>
#include <QVRDeviceImplementation/QTestImplementation.h> //interface we expect
//#include "q_plugin.h"

const char* PLUGIN_LOC = "/home/dmitri/Code/VR/qt3d_vr_deviceplugins/build/libq_plugin.so";

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

    TestInterface* testInterface;
    testInterface = qobject_cast<TestInterface *>(plugin);
    if(!testInterface){
        printf("INVALID INTERFACE IMPLEMENTED BY PLUGIN \n");
        return 1;
    }

    testInterface->test_fnc();


    printf("natural exit\n");
    return 0;
}
