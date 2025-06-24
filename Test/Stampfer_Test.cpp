#include <limits.h>
#include <string>
#include "gtest/gtest.h"


#define protected public
#define private public
#include "VorhandeneZutaten.h"
#include "Stampfer.h"
#undef protected
#undef private


#include <ctime>

class StampferTest: public ::testing::Test
{
protected:
    Stampfer* st;
    virtual void SetUp()
    {
        st = new Stampfer();
        st->myTimer->set_Turbo(10000);

    }
    virtual void TearDown()
    {
        delete st;
    }
};

TEST_F(StampferTest,DoItTest){
    try{
        st->doIt(5);
        EXPECT_TRUE(true);
    }
    catch (...) {
        EXPECT_TRUE(false);
    }   
}
