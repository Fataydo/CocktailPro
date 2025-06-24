//@(#) Observer.h

#ifndef OBSERVER_H_H
#define OBSERVER_H_H
/**
 *@class Observer
 * Diese Klasse ist komplett abstrakt und wird nicht implementiert. 
 */
class Observer {
public:
    /** @brief Abstrake Update Funktion
     * Eine abstrakte Update Funktion für alle Klassen die von Observer erben.
     */
    virtual void update() = 0;

};

#endif
//teständerung diesdas