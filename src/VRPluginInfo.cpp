#include <VRDeviceImplementation/VRPluginInfo.h>
#include <stdio.h>
#include <dlfcn.h>

int VR::Plugin::VRPluginInfo::loadLib(){

    ready = false;

    //handle = dlopen(location, RTLD_LAZY); //TODO: check flag
    handle = dlopen(location, RTLD_NOW); //TODO: check flag
    if (!handle) {
        printf("Cannot open lib: %s \n", dlerror());
        ready = false;
        return 1;
    }
    printf("VRPluginInfo opened lib\n");

    dlerror(); // reset errors
    getVRAPIVersion = (get_vr_interface_version_t*) dlsym(handle, "get_vr_interface_version");
    const char *dlsym_error = dlerror();
    if (dlsym_error) {
        printf("Cannot load symbol 'get_vr_interface_version()': %s \n",dlsym_error);
        dlclose(handle);
        ready = false;
        return 1;
    }
    printf("VRPluginInfo found version symbol\n");

    //check version
    printf("VRPluginInfo ::: VR Interface Version: %d\n",getVRAPIVersion());

    dlerror(); // reset errors
    createVRDevice  = (create_vrdevice_t*) dlsym(handle, "create_vrdevice");
    dlsym_error = dlerror();
    if (dlsym_error) {
        printf("Cannot load symbol 'create_plugin()': %s \n",dlsym_error);
        dlclose(handle);
        ready = false;
        return 1;
    }
    printf("VRPluginInfo found create symbol\n");

    destroyVRDevice = (destroy_vrdevice_t*) dlsym(handle, "destroy_vrdevice");
    dlsym_error = dlerror();
    if (dlsym_error) {
        printf("Cannot load symbol 'create_plugin()': %s \n",dlsym_error);
        dlclose(handle);
        ready=false;
        return 1;
    }
    printf("VRPluginInfo found destroy symbol\n");

    printf("[SUCCESS] Library loaded, and all symbols found\n");
    ready=true;
    return 0;
}
