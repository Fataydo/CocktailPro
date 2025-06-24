//@(#) Waage.h

#ifndef WAAGE_H_H
#define WAAGE_H_H

#include "Subject.h"

/**
* @class Waage
* @brief Diese Klasse wird dazu genutzt, die Gewichte
* der jeweiligen Zutaten zu erfassen.
*/


class Waage : public Subject {
public:
    Waage():weight(0),deltaweight(0){}
  /**
  *@brief diese Methode ändert das Gewichte
  *@param [in] v Wie viel Gramm, zurzeit auf der Waage sind
  */
    void changeWeight(int v);
    /**
    *@brief diese Methode setzt die Waage wieder auf 0 Gramm
    *@return Das genullte deltaweight.
    */
    int tara();
    /**
    *@brief diese Methode erfasst das Gewicht der Zutat
    *@return weight
    */
    int getWeight();
    /**
    *@brief diese Methode erfasst das Gewicht, der voherigen Zutaten
    @return deltaweight
    */
    int getDelta();
private:

  /**
  *@brief diese Variable stellt das Gewicht der Zutat dar
  */
    int weight;
    /**
    *@brief diese Variable stellt das Gewicht der schon erfassten Zutaten dar
    */
    int deltaweight;
};

#endif
