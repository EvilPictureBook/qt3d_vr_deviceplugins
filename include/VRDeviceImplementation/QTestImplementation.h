#ifndef TEST_INTERFACE_H
#define TEST_INTERFACE_H


class TestInterface
{
    public:
        virtual ~TestInterface() {}
        virtual void test_fnc() = 0;
};

Q_DECLARE_INTERFACE(TestInterface, "org.test.evilpicturebook.iid")

#endif
