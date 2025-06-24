#include <limits.h>
#include <string>
#include "gtest/gtest.h"
#define protected public
#define private public
#include "Entleerer.h"
#include "Waage.h"
#undef protected
#undef private
#include <sstream>
class Entleerer_Test  : public ::testing::Test {
    protected:
        Entleerer* e;
        Waage* w;
        std::basic_streambuf<char>* old_buf;
        std::stringstream ss;
        
        virtual void SetUp() {
            old_buf = std::cout.rdbuf(ss.rdbuf());
            w = new Waage();
            w->changeWeight(50);
            e = new Entleerer(5, 1250, w);
        }
        
        virtual void TearDown() {
            std::cout.rdbuf(old_buf);
            delete e;
            delete w;
        }
};


TEST_F(Entleerer_Test,testeGewichtvonEntleerer) {
    ss.clear();
    e->doIt(5);
    EXPECT_EQ(5, w->getWeight());
}
