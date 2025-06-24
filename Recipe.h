#ifndef _REZEPT_H_479
#define _REZEPT_H_479

#include "RecipeStep.h"

#include <stdio.h>
#include <list>
#include <string>
/**
 * @class Recipe
 * In einem Objekt dieser Klasse wird eine liste mit allen RezeptZutaten
 * in eine liste hinzugef�gt und mit einem Rezept-Namen erzeugt.
 * 
 */
class Recipe {
    /**
     * Diese liste beinhaltet jede einzelne zutat eines Rezeptes
     */
private:
    std::list<RecipeStep*> m_RecipeStep;
    /**
     * Der string m_Name beschreibt den Rezept namen
     */
    std::string m_Name;
    /**
     * Dieser Int beinhaltet die Nummer des Rezepts
     */
    int m_Nummer;
    
    bool m_mischbar;

public:
/** @brief Konstruktor eines Rezepts.
* Diese Methode initialisiert eine leere liste und setzt keinen namen fest.
*/
    Recipe(void);
/** @brief Destruktor eines Rezepts.
* Methoden k�rper ist leer, soll Rezepte l�schen.
*/
    ~Recipe();
/** @brief gibt die l�nge der liste m_RecipeStep zur�ck.
* Der Methodenname ist nicht wirklich passend zur Funktion.
*/
    int getNoOfRecipeSteps();
/** @brief Gibt die Zutat eines Rezeptes zurück.
* @param [in] i Gibt an der stelle i, von der liste m_RecipeStep die zutat zurück.
* @return Den momentanen Schritt, als RecipeStep Objekt. 
*/
    RecipeStep * getRecipeStep(unsigned int i);
/**
 * @brief Methode um Nummer zu setzen.
 * @param [in] newNum Nummer die benutzt wird.
 * Setzt neue Nummer für das jeweilige Rezept ein.
 */
    void setNummer(int newNum);
/**
 * @brief Return funktion für Nummer
 * @return Nummer des Rezeptes
 * Gibt die Nummer des Rezepts zurück.
 */
    int getNummer() const;
/** @brief Return Funktion f�r Name.
* @return Name des Rezepts.
*/
    std::string getName(void) const;

/** @brief Methode um den Namen zu setzen.
* Diese Funktion setzt den Namen als String.
*/
    void setName(const std::string& Name);
/** @brief Methode f�gt der liste m_RecipeStep ein Objekt 
 * der Klasse RecipeStep hinzu.
 * @param [in] z welcher zutat hinzugef�gt wird und
 * @param [in] m welche menge von der zutat hinzugef�gt wird.
 * Diese Werte werden als Objekt der Klasse RecipeStep angelegt und dann
 * pushed die methode sie in die liste m_RecipeStep hinein
*/
    void appendStep(std::string z, float m);
/** @brief Gibt die Zutaten eines  Rezepts aus.
* Gibt die Zutat jedes Schritts via cout aus.
*/
    void browse();
    
/** @brief Methode um den Namen zu getten.
* Diese Funktion ob der Cocktail mischbar ist.
* @return Ob der Cocktail mischbar ist.
*/
    bool getMischbar();
    
/** @brief Methode um das mischbar Flag zu setzen.
* @param [in] isMischbar Der zu setzende Wert.
* Diese Funktion setzt das mischbar Flag.
*/
    void setMischbar(bool isMischbar);
    
};

#endif
