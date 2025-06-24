#include <limits.h>
#include <string>
#include "gtest/gtest.h"


#define protected public
#define private public
#include "VorhandeneZutaten.h"
#include "Mixer.h"
#undef protected
#undef private

#include <ctime>

class MixerTest: public ::testing::Test
{
protected:
    Mixer* mx;
    virtual void SetUp()
    {
        mx = new Mixer();
        mx->myTimer->set_Turbo(10000);
    }
    virtual void TearDown()
    {
        delete mx;
    }
};


TEST_F(MixerTest,DoItTest){
    try{
        mx->doIt(5);
        EXPECT_TRUE(true);
    }
    catch (...) {
        EXPECT_TRUE(false);
    }}
