//@(#) DeviceVerwalter.cpp


#include "DeviceVerwalter.h"

DeviceVerwalter::DeviceVerwalter(VorhandeneZutaten * zv) {
    setZutatenVerwalter(zv);
    this->createDevices();
}

void DeviceVerwalter::createDevices() {
    theWaage = new Waage();
    myDevices = new std::map<std::string, InternalDevice *>;

    myEntleerer = new Entleerer(25, 1000, theWaage);
    myDevices->insert(std::make_pair("Entleeren", myEntleerer));

    myStampfer = new Stampfer();
    myDevices->insert(std::make_pair("Stampfen", myStampfer));

    mySchuettler = new Schuettler();
    myDevices->insert(std::make_pair("Schuetteln", mySchuettler));

    myMixer = new Mixer();
    myDevices->insert(std::make_pair("Mischen", myMixer));

    dosiererCount = 0;
    
    std::string myZutat;
    for (int i = myZutatenVerwalter->getAnzahlVorhandeneZutaten() - 4; i >= 0; i--) {
        myZutat=myZutatenVerwalter->getZutat(i);
        if(existsAlready(myZutat)){
            if(myZutat == "Eis" || myZutat == "Limettenstuecke"){
                std::cerr << "Error: Zweimal Eis oder Limettenstuecke sind nicht hardwarekompatibel!" <<std::endl;
                exit(0);
            }
            Dosierer* temp = static_cast<Dosierer*>((*myDevices)[myZutat]);
              myDevices->erase(myZutat);
              myDevices->insert(std::make_pair(myZutat, new Dosierer(1,250,myZutat,theWaage,temp->getFuellstand() + 1000)));
              ++dosiererCount;
        }else{
            createOriginalDevice(myZutat);
        }
    }
    checkDosiererCount(dosiererCount); 
}

void DeviceVerwalter::createOriginalDevice(std::string myZutat){
     if (myZutat == "Eis")
            myDevices->insert(std::make_pair(myZutat, new Dosierer(20, 1000, myZutat, theWaage, 1000)));
        else if (myZutat == "Limettenstuecke")
            myDevices->insert(std::make_pair(myZutat, new Dosierer(10, 1000, myZutat, theWaage, 100)));
        else{
            myDevices->insert(std::make_pair(myZutat, new Dosierer(1, 250, myZutat, theWaage, 1000)));
            ++dosiererCount;
        }
}


void DeviceVerwalter::setZutatenVerwalter(VorhandeneZutaten * zv) {
    myZutatenVerwalter = zv;
}

void DeviceVerwalter::rezeptSchrittZubereiten(std::string zutat, float menge) {
    if (zutat == "Limettenstuecke") {
        // Der Kunde will Limetten ja unbedingt nach Stueck und nicht nach Gewicht abmessen...
        int stckProZeit = static_cast<Dosierer*>(myDevices->at(zutat))->getStueckProZeit();
        myDevices->at(zutat)->doIt(menge * stckProZeit);
    } else {
        myDevices->at(zutat)->doIt(menge);
    }
}

void DeviceVerwalter::entleeren(float menge) {
    myEntleerer->doIt(menge);
}

void DeviceVerwalter::putzen() {
    for (std::map<std::string, InternalDevice*>::iterator i = myDevices->begin(); i != myDevices->end(); ++i) {
        //std::cout << "Device mit der Aktion: " << i->first << " wird jetzt geputzt: " << std::endl;
        i->second->putzen();
    }
}

std::map<std::string, InternalDevice *> * DeviceVerwalter::getDevices(){
    return myDevices;
}

bool DeviceVerwalter::existsAlready(std::string zutat){ 
    for (std::map<std::string, InternalDevice *>::iterator it = myDevices->begin(); it != myDevices->end(); ++it) 
    { 
        if (zutat == it->first){ 
            return true; 
        } 
    } 
    return false; 
} 

void DeviceVerwalter::checkDosiererCount(unsigned count){ 
    if(count>11){ 
        std::cerr << count << "Die Zutatendatei setzt zu viele Dosierer voraus, bitte editieren sie sie und starten neu!" << std::endl; 
        exit(0); 
    } 
}