#include <limits.h>
#include <string>
#include "gtest/gtest.h"


#define protected public
#define private public
#include "VorhandeneZutaten.h"
#include "Schuettler.h"
#undef protected
#undef private


#include <ctime>

class SchuettlerTest: public ::testing::Test
{
protected:
    Schuettler* sc;
    virtual void SetUp()
    {
        sc = new Schuettler();
        sc->myTimer->set_Turbo(10000);
    }
    virtual void TearDown()
    {
        delete sc;
    }
};

TEST_F(SchuettlerTest,DoItTest){
    try{
        sc->doIt(5);
        EXPECT_TRUE(true);
    }
    catch (...) {
        EXPECT_TRUE(false);
    }
}
