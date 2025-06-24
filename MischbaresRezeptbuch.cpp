//@(#) MischbaresRezeptbuch.cpp


#include "MischbaresRezeptbuch.h"
#include <iostream>
//

void MischbaresRezeptbuch::browse() {
    std::cout << "*********************************************" << std::endl;
    std::cout << "Es gibt " << this->getNumberOfRecipes() << " mischbare Cocktails" << std::endl;

    for (int i = 0; i<this->getNumberOfRecipes(); i++) {
        Recipe* r = this->getRecipe(i);
        std::cout << r->getNummer() << ". ";
        if(!r->getMischbar()){
            std::cout << " !NICHT MISCHBAR! ";
        }
        r->browse();
        std::cout << std::endl;
    }
    std::cout << "*********************************************" << std::endl;

}

MischbaresRezeptbuch::MischbaresRezeptbuch(VorhandeneZutaten * zv) {

    // Debug *********
    std::cout << "********** Rezepte vor dem Filtern **********" << std::endl;
    this->browse();
    // ******************

    setZutatenVerwalter(zv);
    seitenRausreissen();
}

void MischbaresRezeptbuch::setZutatenVerwalter(VorhandeneZutaten * zv) {
    myZutatenVerwalter = zv;
    return;
}

void MischbaresRezeptbuch::zutatKontrollieren(std::string gesuchteZutat, bool& ZutatOK){
        for (int k = 0; k < myZutatenVerwalter->getAnzahlVorhandeneZutaten(); k++) {
            if (myZutatenVerwalter->getZutat(k) == gesuchteZutat) {
                ZutatOK = true;
                break;
            }
        }    
}

bool MischbaresRezeptbuch::rezeptKontrollieren(Recipe* zuPruefendesRezept){
    
    for (int j = 0; j < zuPruefendesRezept->getNoOfRecipeSteps(); j++) {
        std::string gesuchteZutat = zuPruefendesRezept->getRecipeStep(j)->getZutat();
        bool ZutatOK = false;

        zutatKontrollieren(gesuchteZutat, ZutatOK);
        
        if (!ZutatOK) {
            return false;
        }
    }
    return true;
}

void MischbaresRezeptbuch::seitenRausreissen() {

    for (int i = 0; i<this->getNumberOfRecipes(); i++) {
        Recipe* r = getRecipe(i);
       
        if (!rezeptKontrollieren(r)) {
            deleteRecipe(i);
            --i;
        }
    }
}