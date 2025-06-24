#include <limits.h>
#include "gtest/gtest.h"

#define protected public
#define private public
#include "RecipeStep.h"
#undef protected
#undef private

class RecipeStepTest : public ::testing::Test {
 protected:
  RecipeStep* rs;
  
  virtual void SetUp() {
    rs = new RecipeStep();
  }

  virtual void TearDown() {
    // Code here will be called immediately after each test
    // (right before the destructor).
    delete rs;
  }
};

TEST_F(RecipeStepTest,getZutatReturnsInitializedValue){
    std::string zutat="";
    EXPECT_EQ(zutat,rs->getZutat());
}

TEST_F(RecipeStepTest,getMengeReturnsInitializedValue){
    float menge = 0;
    EXPECT_EQ(menge,rs->getMenge());
}
