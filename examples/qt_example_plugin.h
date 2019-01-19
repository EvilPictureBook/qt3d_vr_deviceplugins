#ifndef TEST_VRDEVICE_IMPLEMENTATION_H
#define TEST_VRDEVICE_IMPLEMENTATION_H

#include <QObject>
#include <QtPlugin>
#include <QtGui/QMatrix4x4>

#include <VRDeviceImplementation/IVRDeviceImplementation.h>

class TestVRDeviceImplementation : public QObject, VR::Plugin::IVRDeviceImplementation
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID VRDEVICE_INTERFACE_IID) //...should work...
    Q_INTERFACES(VR::Plugin::IVRDeviceImplementation)


public:
    TestVRDeviceImplementation ();
    ~TestVRDeviceImplementation ();

    int initializeVR(void* udata=nullptr); //add overrides?
    int submitVR(uintmax_t leftEyeTexID, uintmax_t rightEyeTexID, void* udata = nullptr);
    int updateVR(void* udata=nullptr);
    int shutdownVR(void* udata = nullptr);
    int shouldClose();

    //need to get left and right eye matrices
    virtual QMatrix4x4 getEyeProjection(VR::eyeId eye);

    //need to get hmd pose, left eye pose, right eye pose
    virtual QMatrix4x4 getEyePose(VR::eyeId eye);
    virtual QMatrix4x4 getHmdPose();

private:
    QMatrix4x4 mat;

};

#endif
