//@(#) Dosierer.cpp


#include "Dosierer.h"

Dosierer::Dosierer(float g, int ze, std::string neuerInhalt, Waage * wg, double mF) : InternalDevice(),inhalt(neuerInhalt),maxFuellstand(mF) {
    this->grammProZeit = g;
    this->gwicht = 0.0;
    this->fuellstand = maxFuellstand;
    this->zeiteinheit = ze;
    this->myWaage = wg;
    this->myWaage->attach(this);
}

void Dosierer::update() {
    if (!this->doinIt) return;
    if (myWaage->getDelta() >= gwicht) {
        doinIt = false;
    }

}

void Dosierer::doIt(float gramm) {
    this->gwicht = gramm;
    myWaage->tara();
    doinIt = true;
    std::cout << inhalt << " Ventil wurde geoeffnet" << std::endl;
    while (doinIt) {
        myTimer->sleep(zeiteinheit);
        myWaage->changeWeight(grammProZeit);
        if(inhalt=="Limettenstuecke"){
        fuellstand -= grammProZeit/10;   
    } else {
        fuellstand -= grammProZeit; 
    }
        
    }
    std::cout << inhalt << " Ventil wurde geschlossen" << std::endl;
    std::cout << "Es wurden " << myWaage->getDelta() << "g " << inhalt << " abgefuellt" << std::endl;
    std::cout << std::endl;
}

int Dosierer::getStueckProZeit() {
    return this->grammProZeit;
}

double Dosierer::getFuellstand() {
    return this->fuellstand;
}

std::string Dosierer::getInhalt(){
    return this->inhalt;
}