#ifndef _REZEPTSCHRITT_H_472
#define _REZEPTSCHRITT_H_472

#include <list>
#include <string>
/**
 * @class RecipeStep
 * In ein Objekt dieser Klasse wird der Name der Zutat
 * und die Menge hinzugef�gt .
 *
 */
class RecipeStep {
    /**
     * Der string m_Zutat beschreibt den namen der zutat
     */
    std::string m_Zutat;
    /**
     * Der float Wert m_Menge beschreibt die menge der dazugeh�rigen m_Zutat
     */
    float m_Menge;

public:
/** @brief Konstruktor einer Zutat.
* Diese Methode initialisiert keinen bestimmten namen und der float Wert
* betr�gt 0.
*/
    RecipeStep(void);
/** @brief Destruktor der Zutaten.
* Methoden k�rper ist leer, soll Zutat l�schen.
*/
    ~RecipeStep();
/** @brief Return Funktion f�r Zutat.
* Diese Funktion returned den Namen der Zutat.
*/
    std::string getZutat(void) const;
/** @brief Return Funktion f�r die Menge der Zutat.
* Diese Funktion returned die Menge.
*/
    float getMenge(void) const;
/** @brief Methode um den Namen der Zutat zu setzen.
* Diese Funktion setzt den Namen als String.
*/
    void setZutat(std::string neueZutat);
/** @brief Methode um die Menge einer zutat zu setzen.
* Diese Funktion setzt die Menge als Float Wert.
*/
    void setMenge(float neueMenge);

};
#endif
