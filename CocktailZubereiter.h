//@(#) CocktailZubereiter.h

#ifndef COCKTAILZUBEREITER_H_H
#define COCKTAILZUBEREITER_H_H



#include "Recipe.h"
#include "RecipeBook.h"
#include "DeviceVerwalter.h"

/**
* @class CocktailZubereiter
* @brief Bereitet den Cocktail nach den Rezeptschritten zu.
* Der CocktailZubereiter bereitet den vom Benutzer
* ausgewählten Cocktail mithilfe eines DeviceVerwalters zu.
*/
class CocktailZubereiter {
public:
/** @brief Der Konstruktor des Zubereiters.
* @param [in] dv Benötigter DeviceVerwalter um Rezeptschritte auszuführen.
* Dieser Konstruktor erzeugt einen CocktailZubereiter und initialisiert myDeviceVerwalter.
*/
    explicit CocktailZubereiter(DeviceVerwalter * dv);
/** @brief Wird benutzt um einen Cocktail zuzubereiten.
* @param [in] rzpt Das zuzubereitende Rezept.
* @return Diese Methode returnt immer true
*/
    bool cocktailZubereiten(Recipe * rzpt);

private:
/**
* Dieser DeviceVerwalter wird beötigt um die einzelnen
* Geräte innerhalb der CocktailPros anzusprechen und zu kontrollieren.
*/
    DeviceVerwalter * myDeviceVerwalter;


};

#endif
