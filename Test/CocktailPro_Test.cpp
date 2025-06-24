#include <limits.h>
#include "gtest/gtest.h"
#include <string>
#include <sstream>

#define protected public
#define private public
#include "CocktailPro.h"
#undef protected
#undef private

class CocktailProTest : public ::testing::Test {
 protected:
  std::basic_streambuf<char>* old_buf;
  std::stringstream ss;
      
  CocktailPro* cp;
  virtual void SetUp() {
    char* args[2];
    args[0] = (char*)"CocktailPro\0";
    args[1] = (char*)"-T";

    old_buf = std::cout.rdbuf(ss.rdbuf()); // redirect cout to stream for testing
    cp = new CocktailPro(2,args);
  }

  virtual void TearDown() {
    // Code here will be called immediately after each test
    // (right before the destructor).
    std::cout.rdbuf(old_buf); // redirect cout back to standard cout
    delete cp;
  }
};

TEST_F(CocktailProTest,TestDemoMode){

    ss.clear();
    CocktailPro* demo = cp;
    std::string s = ss.str();
    std::string hopefullyNotOutput = "Falsche Cocktailnummer!";
    EXPECT_FALSE(hopefullyNotOutput==s.substr(0,23));
}

TEST_F(CocktailProTest,TestMischen){
    ss.clear();
    cp->mischen(false);
    std::string s = ss.str();
    std::string hopefullyNotOutput = "Falsche Cocktailnummer!";
    EXPECT_FALSE(hopefullyNotOutput==s.substr(0,23));
}

TEST_F(CocktailProTest,TestChooseCocktail){
    ss.clear();
    std::string error = "";
    try{
        cp->chooseCocktail(-2);
    }catch(std::out_of_range& oor){
        error = oor.what();
    }
    EXPECT_EQ(error.substr(0,14),"Ihre Eingabe: ");
}

TEST_F(CocktailProTest, testDosiererCheck){
    Recipe* tR = new Recipe();
    tR->setName("Test");
    tR->setNummer(-9);
    tR->appendStep("Eis",1000000);
    cp->checkDosierer(tR);
    EXPECT_FALSE(cp->checkDosierer(tR));
}