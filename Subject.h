//@(#) Subject.h

#ifndef SUBJECT_H_H
#define SUBJECT_H_H

#include "Observer.h"

#include <vector>
#include <iostream>
/**
* @class Subject
* @brief Diese Klasse ist f�r das beobachten bzw updaten bestimmter 
 * Funktionen des Mixers zust�ndig.
* Diese Klasse wird verwendet um bestimmte funktionen des Mixers zu beobachten
 * und dem benutzer mitzuteilen. 
*/
class Subject {
public:
/** @brief fügt einen beobachter(Observer) in die observers liste.
* @param [in] observer Fügt diesen Observer der Liste observers hinzu.
*/
    void attach(Observer * observer);
/** @brief ruft für jeden beobachter(Observer) die methode update() auf.
 * Anhand einer Schleife geht die funktion die liste durch und ruft für jedes
 * element in der liste den observer auf.
*/
    void notify();

private:
    /**
     * Dies ist die liste in dem alle Observer hinzugef�gt werden.
     */
    std::vector<Observer *> observers;

};

#endif
