//@(#) Dosierer.h

#ifndef DOSIERER_H_H
#define DOSIERER_H_H

#include <string>
#include <iostream>

#include "Observer.h"
#include "InternalDevice.h"
#include "Waage.h"

/**
* @class Dosierer.
* @brief Stellt einen Dosierer für eine entsprechende Zutat dar.
* Der Dosierer kümmert sich darum dass die richtige Menge von einer Zutat im
* angeforderten Cocktail landet.
*/
class Dosierer : public InternalDevice, public Observer {
public:
/** @brief Der Konstruktor des Dosierers.
* @param [in] g Wieviel Gramm der Dosierer pro Zeit heraus gibt.
* @param [in] ze Die Zeiteinheit in der der Dosierer arbeitet.
* @param [in] neuerInhalt Der Inhalt des Dosierers.
* @param [in] wg Die interne Waage des Dosierers.
* @param [in] mF Maximaler Füllstand des Dosierers.
* Der Konstruktor des Dosierers initialisiert alle übergebenen Parameter und
* attached die Waage an das Dosierer Objekt.
*/
    Dosierer(float g, int ze, std::string neuerInhalt, Waage * wg, double mF);
/** @brief Updatefunktion des Dosieres.
* Diese Methode wird benutzt um im Auge zu behalten ob schon genug von einer
* Zutat ausgegeben wurde. Falls dies der Fall ist stoppt sie den Dosierer.
*/
    virtual void update();
/** @brief Beschreibt wie der Dosierer arbeitet.
* @param [in] gramm Wieviel Gramm der Dosierer ausgeben soll.
* Diese Methode beschreibt den internen Vorgang des Dosierers. Hier wird
* unter Anderem die Waage zurück gesetzt und der doinIt Zustand auf true gesetzt.
*/
    void doIt(float gramm);
/** @brief Return Funktion für grammProZeit.
* Diese Funktion returned grammProZeit als Integer.
*/
    int getStueckProZeit();

/** @brief Return Funktion für fuellstand.
* Diese Funktion returned den momentanen Fuellstand des Dosierers.
*/
    double getFuellstand();

    
private:
/**
* Diese Variable stellt dar wieviel Gramm einer Zutat
* der Dosierer pro Zeit ausgeben kann.
*/
    float grammProZeit;
/**
* Diese Variable stellt die interne Waage des Dosierers dar und ist wichtig um
* festzustellen ob der Dosierer seinen Job erledigt hat oder nicht.
*/
    Waage * myWaage;
/**
* Diese Variable wird benötigt um das Gewicht innerhalb des Objekts in
* verschiedenen Funktionen im Auge behalten zu können.
*/
    float gwicht;
/**
* Diese Variable stellt den Inhalt des Dosierers dar.
*/
    std::string inhalt;
/**
* Diese Variable stellt den maximalen Füllstand des Dosierers dar.
*/
    const double maxFuellstand;
/**
* Diese Variable stellt den aktuellen Füllstand des Dosierers dar.
*/    
    double fuellstand;
};

#endif
