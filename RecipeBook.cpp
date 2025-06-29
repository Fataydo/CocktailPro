//@(#) RecipeBook.cpp

#include <algorithm>

#include "RecipeBook.h"

RecipeBook::RecipeBook(void) {
    m_Recipe.clear();
    
       // Stream anlegen
    std::ifstream in;

    std::string FileName = "Rezepte.csv";
    // Datei oeffnen
    in.open(FileName.c_str(), std::ios::in);
    if (!in) {// File konnte nicht geoeffnet werden
        std::cout << "Rezept Datei konnte nicht gefunden werden, benutze Standard Variante" << std::endl;
        noFileFound();
    } else {
        std::cout << "Rezepte-Liste gefunden!";
        readRecipes();
    } 
}

RecipeBook::~RecipeBook() {
}

int RecipeBook::getNumberOfRecipes() {
    return (m_Recipe.size());
}

Recipe * RecipeBook::getRecipe(unsigned int i) {
    if (i > m_Recipe.size()) return NULL;
    else {
        std::list<Recipe*>::iterator p;
        advance(p = m_Recipe.begin(), i); // p zeigt jetzt auf das i-te Element
        return *p; // Wert von p - also den Pointer zurueck
    }
}

Recipe * RecipeBook::getRecipeNummerDesCocktails(int cNummer) {
    std::list<Recipe*>::iterator p; // Iterator
    for(p = m_Recipe.begin(); p != m_Recipe.end(); ++p)
        if((*p)->getNummer()== cNummer){
        return *p; // Adresse vom Wert von p - also den Pointer auf den der Iterator zeigt
    } return *p;
}

bool RecipeBook::ueberpruefeObCocktailNummerVorhanden(int cNummer) {
    std::list<Recipe*>::iterator p; // Iterator
    for(p = m_Recipe.begin(); p != m_Recipe.end(); ++p)
        if((*p)->getNummer()== cNummer){
        return true; // Adresse vom Wert von p - also den Pointer auf den der Iterator zeigt
    } return false;
}

bool RecipeBook::deleteRecipe(unsigned int i) {
    if (i >= m_Recipe.size()) {
        return false;
    } else {
        std::list<Recipe*>::iterator p;
        advance(p = m_Recipe.begin(), i); // now p points to the i-th Element
        m_Recipe.erase(p); // delete the element p is pointing to
        return true; // Success!
    }
}

void RecipeBook::readRecipes(){
        
    // Stream anlegen
    std::ifstream in;

    int reciepeCounter = 1; 
    std::string FileName = "Rezepte.csv";
    // Datei oeffnen
    in.open(FileName.c_str(), std::ios::in);
            // Daten lesen und ausgeben
    if(!in){
        std::string ex = "File not found" + FileName;
        throw ex;
    }
    std::cout << "Rezepte-Liste erfolgreich geöffnet!";
        std::string zeile;

        // 1. Zeile ist Ueberschrift - Einlesen und wegwerfen!
        getline(in, zeile);

        while (getline(in, zeile)) {
            readLine(zeile, reciepeCounter);
            ++reciepeCounter;
        }

        /* Datei wieder schliessen */
        in.close();
}

void RecipeBook::readLine(std::string zeile, int& reciepeNumber){
    
    if(zeile==""){
        std::string ex = "Empty Line, aborting.";
        throw ex;
    }
    
    std::istringstream inputString(zeile);
    std::string Name;
    std::string Zutat;
    std::string tempstring;
    float Menge;

    Recipe* r1;

    r1 = new Recipe;

    // Aus istringstream Name einlesen mit Komma als Trennzeichen
    getline(inputString, Name, ';');
    // Weiter einlesen bis zum naechsten Trennzeichen (Zutat)
    r1->setName(Name);
    r1->setNummer(reciepeNumber);
    
    while (getline(inputString, Zutat, ';')&& !Zutat.empty()) {
        // Weiter einlesen bis zum naechsten Trennzeichen (Menge)
        if (getline(inputString, tempstring, ';')) {
            std::istringstream(tempstring) >> Menge;
        }
        r1->appendStep(Zutat, Menge);
    }
    this->m_Recipe.push_back(r1);
}


void RecipeBook::noFileFound(){
    Recipe* r1;

    r1 = new Recipe;
    r1->setName("Caipirinha");
    r1->appendStep("Limettenstuecke", 8);
    r1->appendStep("Zucker", 15);
    r1->appendStep("Stampfen", 20);
    r1->appendStep("Eis", 90);
    r1->appendStep("Cachaca", 5);
    r1->appendStep("Mischen", 10);
    r1->setNummer(1);
    this->m_Recipe.push_back(r1);

    r1 = new Recipe;
    r1->setName("Margarita");
    r1->appendStep("Zitronensaft", 2);
    r1->appendStep("Cointreau", 2);
    r1->appendStep("Tequilla", 4);
    r1->appendStep("Eis", 50);
    r1->appendStep("Mischen", 20);
    r1->setNummer(2);
    this->m_Recipe.push_back(r1);

    r1 = new Recipe;
    r1->setName("Daiquiri");
    r1->appendStep("Limettensaft", 2);
    r1->appendStep("Zuckersirup", 2);
    r1->appendStep("Rum weiss", 5);
    r1->appendStep("Eis", 50);
    r1->appendStep("Mischen", 20);
    r1->setNummer(3);
    this->m_Recipe.push_back(r1);

    r1 = new Recipe;
    r1->setName("Planters Punch");
    r1->appendStep("Zitronensaft", 2);
    r1->appendStep("Grenadine", 1);
    r1->appendStep("Orangensaft", 8);
    r1->appendStep("Rum braun", 6);
    r1->appendStep("Eis", 100);
    r1->appendStep("Mischen", 20);
    r1->setNummer(4);
    this->m_Recipe.push_back(r1);

    r1 = new Recipe;
    r1->setName("Caipiroska");
    r1->appendStep("Limettenstuecke", 8);
    r1->appendStep("Zucker", 15);
    r1->appendStep("Stampfen", 20);
    r1->appendStep("Eis", 90);
    r1->appendStep("Wodka", 5);
    r1->appendStep("Mischen", 10);
    r1->setNummer(5);
    this->m_Recipe.push_back(r1);

    r1 = new Recipe;
    r1->setName("Caipirissima");
    r1->appendStep("Limettenstuecke", 8);
    r1->appendStep("Zucker", 15);
    r1->appendStep("Stampfen", 20);
    r1->appendStep("Eis", 90);
    r1->appendStep("Rum weiss", 5);
    r1->appendStep("Mischen", 10);
    r1->setNummer(6);
    this->m_Recipe.push_back(r1);

    r1 = new Recipe;
    r1->setName("Cuban Island");
    r1->appendStep("Zitronensaft", 2);
    r1->appendStep("Cointreau", 2);
    r1->appendStep("Rum weiss", 2);
    r1->appendStep("Wodka", 2);
    r1->appendStep("Eis", 30);
    r1->appendStep("Mischen", 30);
    r1->setNummer(7);
    this->m_Recipe.push_back(r1);


    r1 = new Recipe;
    r1->setName("Martini James B");
    r1->appendStep("Gin", 6);
    r1->appendStep("Wodka", 2);
    r1->appendStep("Noilly Prat", 1);
    r1->appendStep("Schuetteln", 10);
    r1->setNummer(8);
    this->m_Recipe.push_back(r1);
}
