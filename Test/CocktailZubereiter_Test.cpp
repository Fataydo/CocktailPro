#include <limits.h>
#include "gtest/gtest.h"
#define protected public
#define private public
#include "CocktailZubereiter.h"
#include "DeviceVerwalter.h"
#undef protected
#undef private

class CocktailZubereiter_Test : public ::testing::Test {
protected:
    CocktailZubereiter * cz;
    DeviceVerwalter * dv;
    VorhandeneZutaten * vz;
    Recipe * r;
    RecipeStep * rs;
    std::stringstream ss;
    std::basic_streambuf<char>* old_buf;
    virtual void SetUp() {
        old_buf = std::cout.rdbuf(ss.rdbuf()); // redirect cout to stream for testing
        r = new Recipe();
        r->setName("test");
        r->appendStep("Wodka",10);
        rs = new RecipeStep;
        rs->setZutat("Wodka");
        rs->setMenge(10);
        vz = new VorhandeneZutaten();
        dv = new DeviceVerwalter(vz);
        cz = new CocktailZubereiter(dv);
    }
    virtual void TearDown() {
        // Code here will be called immediately after each test
        // (right before the destructor).
        delete r;
        delete vz;
        delete dv;
        delete cz;
        std::cout.rdbuf(old_buf); // redirect cout back to standard cout
    }
};



TEST_F(CocktailZubereiter_Test, cocktailZubereitenTest){
    ss.str("");
    ss.clear();
    cz->cocktailZubereiten(r);
    std::string output = ss.str();
    EXPECT_EQ("Gruess Gott,",output.substr(0,12));
    std::cout.rdbuf(old_buf); // redirect cout back to standard cout
}

TEST_F(CocktailZubereiter_Test, cocktailZubereiterTest){
    CocktailZubereiter* test = cz;
    cz->cocktailZubereiten(r);
    EXPECT_EQ(test,cz);
}