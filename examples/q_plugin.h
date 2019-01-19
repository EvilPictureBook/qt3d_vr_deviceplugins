#ifndef TEST_PLUGIN_H
#define TEST_PLUGIN_H


#include <QObject>
#include <QtPlugin>

//#define PLUGIN_IS_QT
#include <VRDeviceImplementation/QTestImplementation.h>

class TestPlugin : public QObject, public TestInterface
{
    Q_OBJECT
    //Q_PLUGIN_METADATA(IID "org.test.TestImplementation" FILE "testplugin.json") //need to write thsi
    Q_PLUGIN_METADATA(IID "org.test.TestImplementation")
    Q_INTERFACES(TestInterface)

    public:
    void test_fnc() override;


};

#endif
