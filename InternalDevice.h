//@(#) InternalDevice.h

#ifndef INTERNALDEVICE_H_H
#define INTERNALDEVICE_H_H

#include "Timer.h"

/**
* @class InternalDevice
* @brief Abstraktion von Dosierern und Verarbeitungseinheiten.
* Diese Abstrakte Klasse stellt ein generelles internes Gerät dar.
*/
class InternalDevice {
public:
/** @brief Abstrakte Methode um die Arbeitsweise eines Geräts zu beschreiben.
* @param [in] value Dummy Variable
* Diese Methode ist nicht implementiert und existiert nur
* um von den definierteren Geräten überschrieben zu werden.
*/
    virtual void doIt(float value) = 0;
/** @brief Methode um das Putzen eines Geräts darzustellen.
* Diese Methode stellt eigentlich das Putzen eines Geräts dar,
* ist aber nicht implementiert.
*/
    void putzen();
    
/** @brief Konstruktor eines generellen Geräts.
* Diese Methode initialisiert einen Timer und setzt den doinIt Zustand auf 0.
*/
    InternalDevice();
protected:
/**
* Diese Variable stellt die Zeiteinheit dar in der das Gerät arbeitet.
*/
    int zeiteinheit;
/**
* Diese Variable stellt dar ob das Gerät momentan arbeitet oder nicht.
*/
    bool doinIt;
/**
* Der Timer der benutzt wird um dem Gerät genug Zeit zu lassen um seinen Job zu erledigen.
*/
    Timer * myTimer;
   /**
    * Diese Variable schaut ob Device sauber ist.
    */
};

#endif
