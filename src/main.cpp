#include <stdio.h>
#include <plugin/plugin.h>


int main(){

    printf("main\n");

    PluginImplementation plug;

    plug.initializeVR();
    plug.update();
    plug.submitVR();

    return 0;
}
