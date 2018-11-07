#ifndef VR_PLUGIN_TYPES_H
#define VR_PLUGIN_TYPES_H

namespace VR {

enum eyeId{
    eyeLeft = 0,
    eyeRight = 1
};

struct vec3_t{
    float v[3];
};

struct vec4_t{
    float v[4];
};


struct mat33_t{
    float m[3][3];
};


struct mat44_t{
    float m[4][4];
};


}

#endif
