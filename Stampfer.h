//@(#) Stampfer.h

#ifndef STAMPFER_H_H
#define STAMPFER_H_H

#include "InternalDevice.h"
/**
* @class Stampfer
* @brief Diese Klasse ist f�r das z�hlen der zeit beim stampfen zust�ndig.
* Diese Klasse wird verwendet um den Stampfevorgang darzustellen. 
*/
class Stampfer : public InternalDevice {
public:
/** @brief Konstruktor des Stampfers.
* Konstruktor ist leer.
*/
    Stampfer();
/** @brief Beschreibt wie der Stampfer arbeitet.
* @param [in] time Wie lang soll er Stampfen.
* Diese Methode stellt einen Timer f�r das Stampfen dar.
*/
    void doIt(float time);

private:
};

#endif
