//@(#) MischbaresRezeptbuch.h

#ifndef MISCHBARESREZEPTBUCH_H_H
#define MISCHBARESREZEPTBUCH_H_H

#include "Recipe.h"
#include "RecipeBook.h"
#include "VorhandeneZutaten.h"

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib> // fuer exit() unter Linux

/**
*	@class MischbaresRezeptbuch
*	@brief Diese Klasse kennt die mischbaren Rezepte
*	Kennt alle mischbaren Rezepte und kann auch überprüfungen ausführen, ob ein
*	Rezept im Moment noch mischbar ist, oder ob die Zutaten aus sind.
*	Kennt auch eine Liste an verfügbaren Zutaten, die Updatebar ist.
*	Kann diese Ausgeben.
*/
class MischbaresRezeptbuch : public RecipeBook {
public:
	/**
	*	@brief Konstruktor mit Rezeptüberprüfung
	*	@param [in] ze Ist ein Zutatenverwalter, den die Klasse such speichert.	
	*
	*	Dies ist der Konstuktor der Klasse, in ihm wird die Zutatenliste gespeichtert und 
	*	SeitenRausreißen() aufgerufen, um die verfügbarkeit der Zutaten zu überprüfen und 
	*	ggf. Rezepte zu entfernen, denen Zutaten fehlen.
	*/
    explicit MischbaresRezeptbuch(VorhandeneZutaten * ze);

	/**
	*	@brief Ausgabe der verfügbaren Rezepte
	*	
	*	Diese Methode geht durch alle bekannten Rezepte durch (egal ob verfügbar oder nicht,
	*	es ist nicht der job dieser funktion das zu überprüfen!) und gibt sie in einer für
	*	den User leserlichen Weise aus.
	*/
    void browse();

private:
	/**
	*	Diese Variable ist eine Verbindung zur Verwaltung der Zutaten.
	*	Sie wird genutzt, damit das Rezeptbuch die Zutaten zu den Rezepten kennt.
	*/
    VorhandeneZutaten * myZutatenVerwalter;

	/**
	*	Liste der verfügbaren Rezepte
	*/
    std::vector<Recipe *> rezepte;

        /**
        * @brief Kontrolliert eine gegebene Zutat
        * @param [in] gesuchteZutat
        * @param [in] ZutatOK 
        * 
        * Kontrollieren einer Zutat durch vergleich mit allen vorhandenen Zutaten
        */
    void zutatKontrollieren(std::string gesuchteZutat, bool& ZutatOK);
    
        /**
         * @brief Kontrolliert ein Rezept
         * @param [in] zuPruefendesRezept Das zu überrüfende Rezept
         * @return Sagt, ob rezept in Ordnung ist (true) oder ob eine Zutat fehlt (false)
         * 
         * Kontrolliert, ob jede Zutat eines Rezeptes vorhanden ist.
         */
    bool rezeptKontrollieren(Recipe* zuPruefendesRezept);
       
	/**
	* @brief Methode zum Löschen von Rezepten, bei denen Zutaten fehlen.
	*
	* Diese Methode macht einen Check von Jedem Rezept und den dazugehörigen Zutaten.
	* Ist eine Zutat in einem Rezept nicht verfügbar wird dieses Rezept mit Verwendung
	* der deleteReciepe() Methode gelöscht.
	*/
    void seitenRausreissen();

	/**
	* @brief Aktualisiert die Vorhandenen Zutaten
	* @param [in] ze ein Pointer auf eine Liste an Zutaten
	* 
	* Aktualisiert die Zutaten die vorhanden sind im eigenen Zutaten Verwalter (myZutatenVerwalter)
	*/
    void setZutatenVerwalter(VorhandeneZutaten * ze);

};

#endif