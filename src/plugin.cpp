#include <stdio.h>
#include <plugin/plugin.h>

PluginImplementation::PluginImplementation(){
    printf("constructor\n");
}
PluginImplementation::~PluginImplementation(){
    printf("destructor");
}

int PluginImplementation::initializeVR(void* udata){
    printf("init\n");
    return 0;
}


int PluginImplementation::submitVR(void* udata){
    printf("submit\n");
    return 0;
}

int PluginImplementation::update(void* udata){
    printf("update\n");
    return 0;
}

extern "C" IPlugin * create_plugin(){return new PluginImplementation;}
extern "C" void destroy_plugin(IPlugin *p){ delete p;}
