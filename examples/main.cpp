#include <stdio.h>
#include <plugin/plugin.h>


int main(){

    printf("main\n");

    TestVRDeviceImplementation plug;

    plug.initializeVR();
    plug.update();
    plug.submitVR(0,1);
    plug.shutdownVR();

    return 0;
}
