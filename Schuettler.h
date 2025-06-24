//@(#) Schuettler.h

#ifndef SCHUETTLER_H_H
#define SCHUETTLER_H_H

#include "InternalDevice.h"
/**
* @class Schuettler
* @brief Diese Klasse ist f�r das z�hlen der zeit beim schuetteln zust�ndig.
* Diese Klasse wird verwendet um den Schuettlevorgang darzustellen. 
*/
class Schuettler : public InternalDevice {
public:
/** @brief Konstruktor des Schuettlers.
 * Konstruktor ist leer.
*/
    Schuettler();
/** @brief Beschreibt wie der Schuettler arbeitet.
* @param [in] time Wie lang soll er Schuetteln.
* Diese Methode stellt einen Timer f�r das Schuetteln dar.
*/
    void doIt(float time);
private:
};

#endif
