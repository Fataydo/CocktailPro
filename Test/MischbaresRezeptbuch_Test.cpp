#include <limits.h>
#include <string>
#include "gtest/gtest.h"

#define protected public
#define private public
#include "MischbaresRezeptbuch.h"
#undef protected
#undef private

#include <sstream>

class MischbaresRezeptbuchTest: public ::testing::Test
{
protected:
    MischbaresRezeptbuch* mb;
    VorhandeneZutaten vz;
    std::basic_streambuf<char>* old_buf;
    std::stringstream ss;
    virtual void SetUp()
    {
        old_buf = std::cout.rdbuf(ss.rdbuf());
        mb = new MischbaresRezeptbuch( &vz );
    }
    
    virtual void TearDown()
    {
        std::cout.rdbuf(old_buf);
        delete mb;
    }
};

TEST_F(MischbaresRezeptbuchTest,SeitenRausreissen){
    int before = mb->getNumberOfRecipes();
    mb->seitenRausreissen();
    int after = mb->getNumberOfRecipes();
    EXPECT_TRUE(before>=after);
}