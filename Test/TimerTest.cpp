#include <limits.h>
#include "gtest/gtest.h"

#define protected public
#define private public
#include "Timer.h"
#undef protected
#undef private

class TimerTest : public ::testing::Test {
    protected: 
        Timer* tm;
        
  virtual void SetUp() {
    tm = new Timer();
  }

  virtual void TearDown() {
    delete tm;
  }
};

TEST_F(TimerTest,set_turboSetsBooster)
{
    tm->set_Turbo(10);
    EXPECT_EQ(10,tm->booster);
}

