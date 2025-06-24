#include <limits.h>
#include <string>
#include "gtest/gtest.h"


#define protected public
#define private public
#include "InternalDevice.h"
#include "Mixer.h"
#undef protected
#undef private


class InternalDeviceTest: public ::testing::Test
{
protected:
    Mixer* m;

    virtual void SetUp()
    {
        m = new Mixer();
    }

    virtual void TearDown()
    {
        delete m;
    }
};

TEST_F(InternalDeviceTest,TestIfPutzenReallyDoesntDoAnything){
    Mixer* test = m;
    m->putzen();
    EXPECT_EQ(test,m);
}