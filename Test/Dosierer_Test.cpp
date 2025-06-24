#include <limits.h>
#include <string>
#include "gtest/gtest.h"
#define protected public
#define private public
#include "Dosierer.h"
#include "Waage.h"
#undef protected
#undef private
#include <sstream>
class Dosierer_Test  : public ::testing::Test {
    protected:
        Dosierer* d;
        Waage* w;
        std::basic_streambuf<char>* old_buf;
        std::stringstream ss;
        virtual void SetUp() {
            old_buf = std::cout.rdbuf(ss.rdbuf()); // redirect cout to stream for testing
            w = new Waage();
            d = new Dosierer(1, 250, "Zutat", w, 100);
        }
        virtual void TearDown() {
            std::cout.rdbuf(old_buf); // redirect cout back to standard cout
            delete d;
            delete w;
        }
};
TEST_F(Dosierer_Test,testeGewichtDerZutat) {
    // Test redirects the standard cout to another stream (ss)
    // this stream can be read and compared
    // after the test the normal cout is activated again
    ss.clear();
    d->doIt(1);
    EXPECT_EQ(1,w->getDelta());
}
TEST_F(Dosierer_Test,testegetStueckProZeit) {
    EXPECT_EQ(1,d->getStueckProZeit());
}