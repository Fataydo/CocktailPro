//@(#) Mixer.h

#ifndef MIXER_H_H
#define MIXER_H_H

#include <iostream>

#include "InternalDevice.h"

/**
*	@brief Diese Klasse simuliert einen Hardware Mixer
*
*	Die Klasse kann lediglich einen Mixer simulieren, der auch nur warten kann.
*/
class Mixer : public InternalDevice {
public:
	/**
	*	@brief Standartkonstuktor
	*
	*	Leerer Standartkonstuktor. Macht nix.
	*/
    Mixer();

	
	/**
	*	@brief "Simuliert" einen Vorgang eines Mixers
	*	@param [in] time Die Zeitangabe wie lang das System warten soll.
	*
	*	Simulation des Mixvorgangs wird lediglich durch einen Sleep der Funktion emuliert.
	*/
    void doIt(float time);

private:

};

#endif
