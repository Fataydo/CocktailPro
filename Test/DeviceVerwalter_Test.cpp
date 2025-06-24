#include <limits.h>
#include <string>
#include "gtest/gtest.h"
#define protected public
#define private public
#include "DeviceVerwalter.h"
#include "VorhandeneZutaten.h"
#include "Entleerer.h"
#include "Waage.h"
#undef protected
#undef private
class DeviceVerwalter_Test : public ::testing::Test {
 protected:
  DeviceVerwalter* dv;
  VorhandeneZutaten* vz;
  std::basic_streambuf<char>* old_buf;
  std::stringstream ss;
  virtual void SetUp() {
      old_buf = std::cout.rdbuf(ss.rdbuf());
      vz = new VorhandeneZutaten();    
      dv = new DeviceVerwalter(vz);

  }
  virtual void TearDown() {
    // Code here will be called immediately after each test
    // (right before the destructor).
    std::cout.rdbuf(old_buf); 
    delete dv;
    delete vz;
  }
};
TEST_F(DeviceVerwalter_Test, testeDevices)
{
    EXPECT_NE( 0, dv->myDevices->size()); 
}
TEST_F(DeviceVerwalter_Test, testIfrezeptSchrittZubereitenDoesDoAnything){
    DeviceVerwalter* test = dv;
    dv->rezeptSchrittZubereiten("Limettenstuecke",10);
    EXPECT_EQ(test,dv);
}
TEST_F(DeviceVerwalter_Test, testIfPutzenReallyDoesntDoAnything){
    DeviceVerwalter* test = dv;
    dv->putzen();
    EXPECT_EQ(test,dv);
}
TEST_F(DeviceVerwalter_Test, testIfEntleerenDoesntDoAnything){
    DeviceVerwalter* test = dv;
    dv->entleeren(10);
    EXPECT_EQ(test,dv);
}

TEST_F(DeviceVerwalter_Test, testIfrezeptSchrittZubereitenDoesDoAnythingNR2){
    DeviceVerwalter* test = dv;
    dv->rezeptSchrittZubereiten("Eis",10);
    EXPECT_EQ(test,dv);
}

TEST_F(DeviceVerwalter_Test,testDoubleIceOrLime){
    DeviceVerwalter* test = dv;
    vz->ZutatenDateiEinlesen("WRONGzutaten.txt");
    EXPECT_EXIT({test->createDevices();},::testing::ExitedWithCode(0),"Error: Zweimal Eis oder Limettenstuecke sind nicht hardwarekompatibel!");
}

TEST_F(DeviceVerwalter_Test,testTooManyDosierers){
    DeviceVerwalter* test = dv;
    EXPECT_EXIT({test->checkDosiererCount(100);},::testing::ExitedWithCode(0),"Die Zutatendatei setzt zu viele Dosierer voraus, bitte editieren sie sie und starten neu!");
}

TEST_F(DeviceVerwalter_Test,testSuccessfulDoubleDosierer){
    VorhandeneZutaten* testvz = vz;
    testvz->zutaten->clear();
    testvz->ZutatenDateiEinlesen("zutatenDoubleWodka.txt");
    testvz->spezielleFaehigkeitenHinzufuegen();
    DeviceVerwalter* test = new DeviceVerwalter(testvz);
    test->createDevices();
    Dosierer* temp = static_cast<Dosierer*>(test->myDevices->at("Wodka"));
    EXPECT_EQ(temp->getFuellstand(),2000);
}