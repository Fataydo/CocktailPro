
#include <limits.h>
#include "gtest/gtest.h"

#define protected public
#define private public
#include "Recipe.h"
#undef protected
#undef private

class RecipeTest : public ::testing::Test {
 protected:
  Recipe* r;

  virtual void SetUp() {
          r = new Recipe();
  }

  virtual void TearDown() {
    // Code here will be called immediately after each test
    // (right before the destructor).
    delete r;
  }
};

TEST_F(RecipeTest,getNameOfRecipesReturnsValueOfAttribute){
    std::string recipe_name = r->m_Name;
    EXPECT_EQ(recipe_name,r->getName());
   
}

TEST_F(RecipeTest,getNumberOfRecipesReturnsValueOfAttribute){
    int noOfRecipes = r->m_RecipeStep.size();
    EXPECT_EQ(noOfRecipes,r->getNoOfRecipeSteps());
    
}

TEST_F(RecipeTest, getRecipeTest){
    r->setMischbar(false);
    EXPECT_TRUE(!r->getMischbar());
}

TEST_F(RecipeTest, getRecipeStepReturnsValueOfAttribute){
    for(int i=0;i<r->m_RecipeStep.size();++i){
         RecipeStep* rp =r->getRecipeStep(i);
        EXPECT_TRUE(rp!=NULL);
        EXPECT_FALSE(rp==NULL);
    }
}