#include <stdio.h>
//#include <plugin/plugin.h>
#include <plugin/IPlugin.h>
#include <iostream>
#include <dlfcn.h>

//TODO: remove early exit() calls !!!


int find_symbols(IVRPluginInfo* info){

    dlerror(); // reset errors
    info->get_vr_interface_version = (get_vr_interface_version_t*) dlsym(info->handle, "get_vr_interface_version");
    const char *dlsym_error = dlerror();
    if (dlsym_error) {
        printf("Cannot load symbol 'get_vr_interface_version()': %s \n",dlsym_error);
        dlclose(info->handle);
        exit(1);
        return 1;
    }
    printf("found create symbol\n");

    //check version
    printf("VR Interface Version: %d\n", info->get_vr_interface_version());

    dlerror(); // reset errors
    info->create_vrdevice = (create_vrdevice_t*) dlsym(info->handle, "create_plugin");
    dlsym_error = dlerror();
    if (dlsym_error) {
        printf("Cannot load symbol 'create_plugin()': %s \n",dlsym_error);
        dlclose(info->handle);
        exit(1);
        return 1;
    }
    printf("found create symbol\n");

    info->destroy_vrdevice = (destroy_vrdevice_t*) dlsym(info->handle, "destroy_plugin");
    dlsym_error = dlerror();
    if (dlsym_error) {
        printf("Cannot load symbol 'create_plugin()': %s \n",dlsym_error);
        dlclose(info->handle);
        exit(1);
        return 1;
    }
    printf("found destroy symbol\n");

    return 0;
}

int openLib(const char* location, IVRPluginInfo* info){
    info->handle = dlopen(location, RTLD_LAZY);
    if (!info->handle) {
        printf("Cannot open lib: %s \n", dlerror());
        exit(1);
        return 1;
    }
    printf("opened lib\n");

    find_symbols(info);

    return 0;
}

int main(){

    printf("naim\n");

    IVRPluginInfo pluginInfo;
    openLib("./libmy_plugin.so",&pluginInfo);

    IVRDeviceImplementation* plug = pluginInfo.create_vrdevice();

    plug->initializeVR();
    plug->update();
    plug->submitVR(1,2);
    plug->shutdownVR();

    pluginInfo.destroy_vrdevice(plug);
    dlclose(pluginInfo.handle);

    /*
    void* handle = dlopen("./libmy_plugin.so", RTLD_LAZY);
    if (!handle) {
        printf("Cannot open lib: %s \n", dlerror());
        return 1;
    }
    printf("opened lib\n");


    dlerror(); // reset errors
    get_vr_interface_version_t* get_vr_interface_version = (get_vr_interface_version_t*) dlsym(handle, "get_vr_interface_version");
    const char *dlsym_error = dlerror();
    if (dlsym_error) {
        printf("Cannot load symbol 'get_vr_interface_version()': %s \n",dlsym_error);
        dlclose(handle);
        return 1;
    }
    printf("found create symbol\n");

    //check version
    printf("VR Interface Version: %d\n", get_vr_interface_version());


    dlerror(); // reset errors
    create_vrdevice_t* create_plugin = (create_vrdevice_t*) dlsym(handle, "create_plugin");
    const char *dlsym_error2 = dlerror();
    if (dlsym_error) {
        printf("Cannot load symbol 'create_plugin()': %s \n",dlsym_error2);
        dlclose(handle);
        return 1;
    }
    printf("found create symbol\n");


    destroy_vrdevice_t* destroy_plugin = (destroy_vrdevice_t*) dlsym(handle, "destroy_plugin");
    const char *dlsym_error3 = dlerror();
    if (dlsym_error) {
        printf("Cannot load symbol 'create_plugin()': %s \n",dlsym_error3);
        dlclose(handle);
        return 1;
    }
    printf("found destroy symbol\n");

    IVRDeviceImplementation* plug = create_plugin();

    plug->initializeVR();
    plug->update();
    plug->submitVR(1,2);
    plug->shutdownVR();

    destroy_plugin(plug);
    dlclose(handle);
    */


    return 0;
}
