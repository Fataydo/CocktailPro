//@(#) VorhandeneZutaten.h

#ifndef VorhandeneZutaten_H_H
#define VorhandeneZutaten_H_H

#include <string>
#include <map>
#include <vector>
#include <list>
#include <fstream>
#include <cstdlib> // fuer exit() unter Linux
#include <iostream>

/**
 * @class VorhandeneZutaten
 * @brief Liest Zutaten aus Liste ein.
 * Merkt sich in der Liste die Zutaten + Aggregatszustand.
 *
 */
class VorhandeneZutaten {
public:
  /**
   * @brief Konstruktor von VorhandeneZutaten
   */
    VorhandeneZutaten(void);
    /**
     * @brief Copy Konstruktor von VorhandeneZutaten
     * @param vz
     * Ein einfacher Copy Konstruktor
     */
    VorhandeneZutaten(VorhandeneZutaten& vz);
    
    /**
     * @brief Destruktor von VorhandeneZutaten
     */
    virtual ~VorhandeneZutaten();
    /**
     * @brief gibt eine Liste aller Zutaten aus
     */
    void browse(void);

    /**
     * @brief diese Methode erfasst eine Zutaten
     * @param [in] i Int als id um die Zutat aus dem vektor zu erfassen
     */
    std::string getZutat(int i);
    /**
     * @brief diese Methode erfasst, die menge der jeweiligen Zutaten
     * @return Anzahl der  vorhandenen Zutaten
     */
    int getAnzahlVorhandeneZutaten();

private:
  /**
   * @brief Vektor um die Zutaten zu speichern
   */
    std::vector<std::string> * zutaten;
    /**
     * @brief Ein boolean Wert um den Debugger an und auszuschalten
     *
     */
    static const bool DEBUG = false;
    
    /**
     * @brief diese Methode ruft ZutatenDateiEinlesen und browse() auf.
     */
    void zutatenEinlesen();

    /**
     * @brief Liest die Zutaten aus zutaten.txt ein.
     * @param [in] myfile Pfad zur Zutaten Datei.
     */
    virtual void ZutatenDateiEinlesen(std::string myfile);

    /**
     * @brief fügt zu der liste der Zutaten spezielle Funktionen wie "mischen" und "stampfen" ein
     */
    void spezielleFaehigkeitenHinzufuegen();
    /**
     * Variable um die Anzahl der benätigten Dosierer zu speichern.
     */
    int anzahlDosierer;

};
static std::string FileName;
#endif
