//@(#) Entleerer.h

#ifndef ENTLEERER_H_H
#define ENTLEERER_H_H

#include <iostream>

#include "Observer.h"
#include "InternalDevice.h"
#include "Waage.h"
/**
* @class Entleerer
* @brief Diese Klasse ist für das endgültige Entleeren des Cocktails zuständig.
* Diese Klasse wird verwendet um den Entleervorgang darzustellen. Der Entleervorgang
* ist der letzte Schritt beim CocktailPro auf den der Benutzer warten muss.
*/
class Entleerer : public InternalDevice, public Observer {
public:
/** @brief Konstruktor des Entleerers.
* @param [in] g Wieviel Gramm der Entleerer pro Zeit ausgeben kann.
* @param [in] ze Die Zeiteinheit in der der Entleerer arbeitet.
* @param [in] wg Die interne Waage des Entleerers.
* Der Konstruktor initialisiert alle übergebenen Parameter
*und attached die interne Waage an das Entleerer Objekt.
*/
    Entleerer(float g, int ze, Waage * wg);
/** @brief Destruktor des Entleerers.
* Der Destruktor unterscheidet sich nicht von einem Standard- Destruktor.
*/
    ~Entleerer();
/** @brief Updatefunktion des Entleerers.
* Diese Methode wird benutzt um im Auge zu behalten ob schon ausreichend viel
* von einem Cocktail ausgegeben wurde. Falls dies der Fall ist stoppt der Entleerer.
*/
    void update();
/** @brief Beschreibt wie der Entleerer arbeitet.
* @param [in] newValue Wieviel Gramm der Entleerer ausgeben soll.
* Diese Methode beschreibt den internen Vorgang des Entleerers. Hier wird
* gewartet bis der Cocktail entleert wurde mithilfe des doinIt Zustands.
*/
    void doIt(float newValue);

private:
/**
* Diese Variable stellt dar wieviel Gramm der Entleerer pro Zeit ausgeben kann.
*/
    float grammProZeit;
/**
* Diese Variable stellt die interne Waage des Dosierers dar und ist wichtig um
* festzustellen ob der Entleerer fertig ist oder nicht.
*/
    Waage * myWaage;
/**
* Diese Variable wird benötigt um das Gewicht innerhalb des Objekts in
* verschiedenen Funktionen im Auge behalten zu können.
*/
    float value;
};

#endif
