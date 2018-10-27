#include <stdio.h>
//#include <plugin/plugin.h>
#include <plugin/IPlugin.h>
#include <iostream>
#include <dlfcn.h>

int main(){

    printf("naim\n");

    printf("opening\n");
    void* handle = dlopen("./libmy_plugin.so", RTLD_LAZY);
    if (!handle) {
        printf("Cannot open lib: %s \n", dlerror());
        //cerr << "Cannot open library: " << dlerror() << '\n';
        return 1;
    }
    printf("opened lib\n");


    dlerror(); // reset errors

    create_t* create_plugin = (create_t*) dlsym(handle, "create_plugin");
    const char *dlsym_error = dlerror();
    if (dlsym_error) {
        printf("Cannot load symbol 'create_plugin()': %s \n",dlsym_error);
        dlclose(handle);
        return 1;
    }
    printf("found create symbol\n");


    destroy_t* destroy_plugin = (destroy_t*) dlsym(handle, "destroy_plugin");
    const char *dlsym_error2 = dlerror();
    if (dlsym_error) {
        printf("Cannot load symbol 'create_plugin()': %s \n",dlsym_error2);
        dlclose(handle);
        return 1;
    }
    printf("found destroy symbol\n");

    IPlugin* plug = create_plugin();

    plug->initializeVR();
    plug->update();
    plug->submitVR();

    destroy_plugin(plug);
    dlclose(handle);
    return 0;
}
