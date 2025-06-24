#include <limits.h>
#include "gtest/gtest.h"

#define protected public
#define private public
#include "RecipeBook.h"
#undef protected
#undef private

class RecipeBookTest : public ::testing::Test {
 protected:
  RecipeBook* r;
  std::basic_streambuf<char>* old_buf;
  std::stringstream ss;

  virtual void SetUp() {
        old_buf = std::cout.rdbuf(ss.rdbuf()); // redirect cout to stream for testing
        r = new RecipeBook();
  }

  virtual void TearDown() {
    // Code here will be called immediately after each test
    // (right before the destructor).
    std::cout.rdbuf(old_buf); // redirect cout back to standard cout
    delete r;
  }
};

TEST_F(RecipeBookTest,getNumberOfRecipesReturnsValueOfAttribute){
    int noOfRecipes=r->m_Recipe.size();
    EXPECT_EQ(noOfRecipes,r->getNumberOfRecipes());
}
TEST_F(RecipeBookTest,testDeleteRecipeBound){
    EXPECT_FALSE(r->deleteRecipe(r->getNumberOfRecipes()));
}

TEST_F(RecipeBookTest,testDeleteRecipeOutOfBound){
    int oob = 100;
    EXPECT_FALSE(r->deleteRecipe(oob));
}

TEST_F(RecipeBookTest,readRecipesTest)
{
    try{
        r->readRecipes();
    }
    catch(std::string s){
        EXPECT_EQ("File not found", s.substr(0,14));
    }
}

TEST_F(RecipeBookTest,TestEmptyLine)
{
    int i = 1;
    try{
        r->readLine("",i);
    }
    catch(std::string s){
        EXPECT_EQ("Empty Line, aborting.", s.substr(0,21));
    }
}

TEST_F(RecipeBookTest, testeDateilesen){
RecipeBook* demo = r;
try{
    r->readRecipes();
} catch(std::string ex){
    std::cout << ex << std::endl;
}
EXPECT_EQ(demo,r);
}

TEST_F(RecipeBookTest, testeOhneDateiRezepte){
r->m_Recipe.clear();
r->noFileFound();
EXPECT_EQ(8,r->getNumberOfRecipes());
}