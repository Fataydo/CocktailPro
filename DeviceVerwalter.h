//@(#) DeviceVerwalter.h

#ifndef DEVICEVERWALTER_H_H
#define DEVICEVERWALTER_H_H

#include <string>
#include <map>

#include "InternalDevice.h"
#include "VorhandeneZutaten.h"
#include "Dosierer.h"
#include "Mixer.h"
#include "Stampfer.h"
#include "Schuettler.h"
#include "Entleerer.h"
#include "Waage.h"

/**
* @class DeviceVerwalter
* @brief Befuellt die Dosierer, verwaltet die Interne Hardware.
* Der DeviceVerwalter sorgt dafür dass die einzelnen Schritte des Rezepts
* ausgeführt werden. Zudem kümmert er sich um das Putzen und Entleeren des CocktailPro.
*/
class DeviceVerwalter {
public:
/** @brief Der Konstruktor des DeviceVerwalter.
* @param [in] zv Der benötigte ZutatenVerwalter.
* Der Konstruktor setzt den ZutatenVerwalter auf den übergebenen Parameter und
* erstellt alle anderen benötigten Devices.
*/
    explicit DeviceVerwalter(VorhandeneZutaten * zv);
/** @brief Funktion für jeden einzelnen Schritt den das Rezept benötigt.
* @param [in] zutat Die Zutat für die das entsprechende Device gefunden werden muss.
* @param [in] menge Die Menge der ausgewählten Zutat.
* Die Methode kümmert sich um die einzelnen Schritte die benötigt werden um das Rezept
* zu vervollständigen. Außerdem wird hier zwischen Limettenstuecken und anderen Zutaten
* unterschieden, da das eine Anforderung des Kunden war.
*/
    void rezeptSchrittZubereiten(std::string zutat, float menge);
/** @brief Entleert den CocktailPro.
* @param [in] menge Die Menge (in Gramm) an auszuleerendem Cocktail.
* Diese Methode spricht den Entleerer mit der zu entleerenden Menge an.
*/
    void entleeren(float menge);
/** @brief Putzt jedes interne Gerät des CocktailPro.
* Iteriert über jedes interne Gerät des CocktailPro und aktiviert
* bei jedem die Putzfunktion.
*/
    void putzen();
    
/** @brief Return Funktion für die Device Sammlung.
* Returned die Map aus strings und InternalDevice Pointern.
*/
    std::map<std::string, InternalDevice *> * getDevices();

private:
/** @brief Setzt den ZutatenVerwalter.
* @param [in] zv Den zu initialisierenden ZutatenVerwalter
* Diese Methode wird zum Initialisieren des ZutatenVerwalters benötigt.
*/
    void setZutatenVerwalter(VorhandeneZutaten * zv);
/**
* Eine Map der internen Geräten. Hier wird die abstrakte Oberklasse aus Datentyp
* verwendet um alle Geräte beinhalten zu können.
*/
    std::map<std::string, InternalDevice *> * myDevices;
/**
* Diese Variable stellt den internen Entleerer fertigen CocktailPro dar.
*/
    Entleerer * myEntleerer;
/**
* Diese Variable stellt den internen Mixer des fertigen CocktailPro dar.
*/
    Mixer * myMixer;
/**
* Diese Variable stellt den internen Stampfer des fertigen CocktailPro dar.
*/
    Stampfer * myStampfer;
/**
* Diese Variable stellt den internen Schuettler des fertigen CocktailPro dar.
*/
    Schuettler * mySchuettler;
/**
* Diese Variable stellt den internen ZutatenVerwalter fertigen CocktailPro dar.
*/
    VorhandeneZutaten * myZutatenVerwalter;
/**
* Diese Variable stellt die interne Waage des fertigen CocktailPro dar.
*/
    Waage * theWaage;
/** @brief Erstellt alle benötigten Geräte
* Diese Methode erstellt in der benötigten Reihenfolge alle Geräte.
* Danach wird für jede vorhandene Zutat ein Dosierer erstellt.
* (Bei Eis und Limettenstuecken werden besondere Dosierer erstellt.)
*/
    void createDevices();
/**
* @brief Checkt ob ein Dosierer schon vorhanden ist
* @param [in] zutat Name der Zutat, die überprüft werden soll.
* @return Sagt, ob etwas schon vorhanden ist
*/
    bool existsAlready(std::string zutat);
    
    
/* @brief Checkt ob zu viele Dosierer existieren.
* @param [in] count wie viele Dosierer es gibt.
*/
    void checkDosiererCount(unsigned count);
/* @brief Erstellt einen Dosierer falls noch keiner davon existiert.
* @param [in] myZutat Was sich im Dosierer befinden soll.
*/
    void createOriginalDevice(std::string myZutat);
/*
* Benötigt um eventuell physikalisch unmögliche Zutatenkombis zu verhindern.
*/
    int dosiererCount;
};

#endif
