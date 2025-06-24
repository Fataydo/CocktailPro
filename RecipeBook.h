#ifndef RECIPEBOOK_H_489
#define RECIPEBOOK_H_489

#include <fstream>
#include <sstream>

#include <cstdlib> // fuer exit() unter Linux

#include <iostream>

#include <list>
#include <string>

#include "Recipe.h"

/**
 * @class RecipeBook
 *
 * @brief RecipeBook verwaltet eine Kollektion an recipes.
 *
 * Ein RecipeBook kennt eine Rezeptliste
 * Man kann nach der Rezeptanzahl fragen, ein Rezept beim index herausfinden,
 * oder ein Rezept löschen.
 *
 */
class RecipeBook {

  private:
    /**
    * Die Rezeptliste die das RecipeBook verwaltet.
    *
    */
    std::list<Recipe *> m_Recipe;
    /**
    * @brief Wird verwendet falls keine Rezeptdatei zum einlesen gefunden wurde.
    * Daher werden falls dies der Fall ist nur Standardrezepte hinzugefügt.
    */
    void noFileFound();
    /**
    * @brief Liest die Rezeptdatei ein.
    * Liest alle Rezepte aus einer Datei namens "Rezepte.csv" ein, solang diese richtig formatiert ist.
    */
    void readRecipes();
    /**
    * @brief Helper Methode für readRecipes.
    * Diese Methode liest jeweils eine einzelne Zeile der Rezeptdatei ein und dient hauptsächlich der Übersichtlichkeit.
    */
    void readLine(std::string zeile, int& reciepeNumber);

  public:
    /** @brief Konstruktor von RecipeBook
    * @return Ein Pointer auf das erstellte RecipeBook.
    *
    * Diese Methode erstellt ein RecipeBook.
    * Es wird ein temporäres "Initialisierer" Objekt erstellt
    * um die Rezeptliste zu initialisieren. Danach wird der
    * Initialisierer zerstört.
    */
    RecipeBook(void);

    /** @brief Destruktor der das RecipeBook wieder zerstört.
    */
    virtual ~RecipeBook();

    /** @brief Gibt die Anzahl der Rezepte aus
    * @return Die Anzahl der Rezepte im RecipeBook
    */
    int getNumberOfRecipes();

    /** @brief Gibt das i-te Rezept zurück
    * @param [in] i ein positiver Integer für das i-te Rezept.
    * @return Ein pointer auf das angeforderte recipe Objekt, NULL falls invalides i
    *
    * Diese Methode gibt das i-te Rezept zurück;
    * hierbei ist i ein Integer von 0 bis n-1
    * und n die Anzahl von recipes im RecipeBook
    */
    Recipe * getRecipe(unsigned int i);
    
      /** @brief gibt das gesuchte Rezept zurück;
   * @param cNummer ist die eingegebene gewünschte Cocktailnummer
   * @return Returnt das gesuchte Cocktail
   */  
    Recipe * getRecipeNummerDesCocktails(int cNummer);
    /**
     * @brief gibt zurück ob das gesuchte Cocktail vorhanden ist oder nicht;
     * @param cNummer ist die eingegebene gewünschte Cocktailnummer
     * @return returnt true wenn cocktail vorhanden, false wenn nummer nicht vorhanden
     */
    bool ueberpruefeObCocktailNummerVorhanden(int cNummer);
    /** @brief Löscht das i-te recipe aus dem RecipeBook
    * @param [in] i ein positiver Integer für das i-te Rezept.
    * @return Boolean der angibt ob erfolgreich gelöscht wurde.
    *
    * Diese Methode löscht das i-te recipe aus dem RecipeBook.
    * Sie gibt true zurück falls erfolgreich gelöscht wurde (valides i).
    * Für invalide i Werte (i <0 or i>=n) gibt die Funktion false zurück.
    */
    bool deleteRecipe(unsigned int i);
};

#endif
