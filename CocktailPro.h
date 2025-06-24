//@(#) CocktailPro.h

#ifndef COCKTAILPRO_H_H
#define COCKTAILPRO_H_H

#include "DeviceVerwalter.h"
#include "VorhandeneZutaten.h"
#include "MischbaresRezeptbuch.h"
#include "CocktailZubereiter.h"

/**
* @class CocktailPro
* @brief Das Gesamtsystem.
* In einem Objekt dieser Klasse werden der CocktailPro selbst
* und alle seine Komponenten erzeugt und initialisiert.
*/
class CocktailPro {
/**
* Diese Variable stellt den CocktailZubereiter dar, welcher sich um alles interne kümmert.
*/
    CocktailZubereiter * theCocktailZubereiter;
/**
* Diese Variable stellt den DeviceVerwalter dar, welcher sich um die internen Geräte kümmert.
*/
    DeviceVerwalter * theDeviceVerwalter;
/**
* Diese Variable stellt das Rezeptbuch mit Rezepten dar, welche mit den vorhandenen Zutaten möglich sind.
*/
    MischbaresRezeptbuch * theMischbaresRezeptbuch;
/**
* Diese Variable stellt den ZutatenVerwalter dar, welcher sich um die Zutaten kümmert (Zum Beispiel einlesen).
*/
    VorhandeneZutaten * theZutatenVerwalter;

protected:
/**
 * @brief Hilft chooseCocktail
 * @param [in] in debug parameter
 * @return Gibt die nummer des Rezepts entweder mit debug wert oder vom Nutzer zurück
 */
    std::string eingabeHelper(int in);
    
/** @brief Handled die Benutzereingabe.
 * @param [in] in debug parameter
* @return Gibt einen Integer der dem ausgewählten Cocktail entspricht zurück.
* Diese Methode fragt den Benutzer nach seiner Wahl und gibt (falls es keine Fehler gab)
* einen zum Cocktail korrespondierenden Integer zurück.
*/    
    int chooseCocktail(int in=0);
/** @brief beendet das Programm.
 * @return beendet das Programm mit exit(0) wenn "-1" eingegeben wurde.
 * Diese Methode bekommt die eingegeben ziffer von chooseCocktail() übergeben und
 * prueft ob eine "-1" eingegeben wurde.
 */   
    void beendeCocktailPro(int zahl);
/**@brief Methode zur Demonstration des CocktailPro.
* Diese Methode bereitet hardcoded den zur "1" korrespondierenden Cocktail zu, um die Funktion
* des CocktailPro zu demonstrieren.
*/
    void demo();
    
/** @brief Methode um die Füllstände auszugeben.
* Gibt die Füllstände aller Dosiere als std::cout aus.
*/
    void printFuellstaende();
    
/** @brief Helper Methode für printFuellstände.
* Gibt den einzelnen Füllstand eines Dosierers aus.
*/
    void printFuellstand(std::map<std::string,InternalDevice*>::iterator device);
/** @brief Helfer Methode für mischen().
* Lagert den größeren Teil von mischen aus 
* um die Komplexität zu senken.
* @param [in] CocktailNo Die Nummer des ausgewählten Cocktails.
*/    
    void mischHelper(int CocktailNo);
    
/** @brief Methode um Dosierer zu prüfen.
* @param [in] rezeptptr Ein Pointer auf das momentan zu Prüfende Rezept.
* @return Sagt aus ob der Cocktail erfolgreich zubereitet werden kann oder
* ob eine Zutat fehlt.
*/
    bool checkDosierer(Recipe* rezeptptr);
    
    /** @brief Prüft ob es sich beim Device um einen Dosierer handelt oder nicht.
     * @param [in] input Der zu vergleichende String.
     * @return Ob es ein Dosierer ist oder nicht.
     */
    bool checkIfZutat(std::string input);
    
    /** @brief Überprüft ob für den angegebenen Schritt genügend Zutaten da sind.
     * 
     * @param [in] temp Ein Pointer auf den momentanen Dosierer.
     * @param [in] rezeptptr Ein Pointer auf das momentane Rezept.
     * @param [in] i Der i-te Schritt im momentanen Rezept.
     * @return 
     */
    bool checkSchritt(Dosierer* temp, Recipe* rezeptptr, int i);
    
/** @brief Um die Cocktails vor dem ausprinten zu checken.
* Diese Methode prüft die Rezepte vor dem Ausgeben und setzt
* eventuell das entsprechende Flag. 
*/
    void checkCocktailMischbar();
    
public:
/** @brief Der Konstruktor des CocktailPro.
* @param [in] argc Falls hier 2 angegeben wird, wird überhaupt erst nach Turbo gecheckt.
* @param [in] turbo Falls hier -D angegeben wird, wird der Turbo eingeschaltet.
* @return Der fertig "gebaute" CocktailPro.
* Dieser Konstruktor erzeugt den CocktailPro (mit optionalem Turbo Modus).
*/
    CocktailPro(int argc, char * * turbo);
/**
 * @brief Einfacher Copykonstruktor.
 * @param cp Der zu kopierende CocktailPro.
*/
    CocktailPro(CocktailPro& cp);
/**@brief Methode zum mischen des CocktailPro.
*/   
    void mischen(bool inf);
};

#endif
