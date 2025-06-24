//@(#) CocktailPro.cpp


#include "CocktailPro.h"
#include <string>

CocktailPro::CocktailPro(int argc, char * * param) {
    bool isTest = (argc == 2 && std::string(param[1]) == "-T");
    theZutatenVerwalter = new VorhandeneZutaten;
    theMischbaresRezeptbuch = new MischbaresRezeptbuch(theZutatenVerwalter);
    theDeviceVerwalter = new DeviceVerwalter(theZutatenVerwalter);
    theCocktailZubereiter = new CocktailZubereiter(theDeviceVerwalter);

    Timer * theTimer = Timer::getInstance();
    if (argc == 2) {// this has to be changed later
    
        if (std::string(param[1]) == "-D") {
            theTimer->set_Turbo(1000);
            this->demo();
        } else if(isTest){
            theTimer->set_Turbo(10000);
        }
        else{ // Parameter => Turbo an
            theTimer->set_Turbo(10);
        }
    }
}

void CocktailPro::mischen(bool inf)  {
        do {
            printFuellstaende();
            checkCocktailMischbar();
            int CocktailNo=0;
            if(inf){
                while(CocktailNo==0){
                    try{
                        CocktailNo = chooseCocktail();
                    }catch(std::out_of_range& oor){
                        std::cerr << oor.what() << std::endl;
                    }
                }
            }else{ //DEBUG FÜR TESTS
                CocktailNo = theMischbaresRezeptbuch->getNumberOfRecipes();
            }
            mischHelper(CocktailNo);
        } while (inf);
}



void CocktailPro::demo() {
    printFuellstaende();
    std::cout << std::endl << std::endl<< std::endl;
    for(int i=0;i<11;i++){
        mischHelper(1);
    }
}
void CocktailPro::beendeCocktailPro(int zahl){
    if (zahl == -1) exit(0);
}

std::string CocktailPro::eingabeHelper(int in){
    std::string eingabe;
    if(in == 0){
        std::cin >> eingabe;
    }else{
        eingabe = in;
    }   
    return eingabe;
}

int CocktailPro::chooseCocktail(int in) {
    do {
        std::cout << "********** Mischbare Rezepte **********" << std::endl;
        theMischbaresRezeptbuch->browse();
        std::cout << "Was haetten Sie denn gern? (-1 zum Verlassen)" << std::endl;
 
        std::string eingabe = eingabeHelper(in);
        
        int zahl = atoi(eingabe.c_str());
        //int max = theMischbaresRezeptbuch->getNumberOfRecipes();
        beendeCocktailPro(zahl);
        if (theMischbaresRezeptbuch->ueberpruefeObCocktailNummerVorhanden(zahl) == true){ 
            return zahl;
        }else{
        //std::system("clear");
        std::cout << "MEEEP! Too many fingers on keyboard error!" << std::endl;
        //std::cout << "Ihre Eingabe: " << eingabe << " war nicht zwischen 1 und " << max << "!" << std::endl;
        std::stringstream ss;
        ss << "Ihre Eingabe: " << eingabe << " trifft auf kein Cocktail zu!" << std::endl;
        throw std::out_of_range(ss.str());
        }
    }while (in==0);
}


void CocktailPro::printFuellstaende(){
    std::cout << std::endl << "Füllstände der Dosierer:" << std::endl;
    for(std::map<std::string,InternalDevice*>::iterator device = theDeviceVerwalter->getDevices()->begin();device!=theDeviceVerwalter->getDevices()->end();++device){
        printFuellstand(device);
    }
    std::cout << std::endl;
}

void CocktailPro::printFuellstand(std::map<std::string,InternalDevice*>::iterator device){
    if(device->first != "Entleeren" && device->first != "Schuetteln" && device->first != "Stampfen" && device->first != "Mischen"){
        Dosierer* temp = static_cast<Dosierer*>(device->second);
        std::cout << temp->getInhalt() << ": " << temp->getFuellstand() << std::endl;
    }
}

void CocktailPro::mischHelper(int CocktailNo){
        Recipe * rezeptptr = theMischbaresRezeptbuch->getRecipeNummerDesCocktails(CocktailNo);
        
        bool cont = checkDosierer(rezeptptr);
        if(cont){
            std::cout << rezeptptr->getName() << std::endl;
            theCocktailZubereiter->cocktailZubereiten(rezeptptr);
        }else{
            std::cout << std::endl << "Dieser Cocktail ist nicht mehr mischbar!" << std::endl
                            << "Bitte schalten sie den CocktailPro aus, füllen alle Zutaten nach und starten dann wieder um diesen Cocktail zu mischen!"<<std::endl << std::endl;
        }
    }

bool CocktailPro::checkDosierer(Recipe* rezeptptr){
    for(std::map<std::string,InternalDevice*>::iterator device = theDeviceVerwalter->getDevices()->begin();device!=theDeviceVerwalter->getDevices()->end();++device){ // auto& device : theDeviceVerwalter->getDevices()
        if(checkIfZutat(device->first)){
            Dosierer* temp = static_cast<Dosierer*>(device->second);
            for(int i = 0; i<rezeptptr->getNoOfRecipeSteps();++i){ // auto& step : rezeptptr->m_RecipeStep
                if(checkSchritt(temp,rezeptptr,i)){
                    return false;
                }
            }
        }
    }
    return true;
}

bool CocktailPro::checkSchritt(Dosierer* temp, Recipe* rezeptptr, int i){
    if(temp->getInhalt() == rezeptptr->getRecipeStep(i)->getZutat() && temp->getFuellstand() <= rezeptptr->getRecipeStep(i)->getMenge()){
        return true;
    }
    return false;
}

bool CocktailPro::checkIfZutat(std::string input){
    if(input != "Entleeren" && input != "Schuetteln" && input != "Stampfen" && input != "Mischen"){
        return true;
    }
    return false;
}

void CocktailPro::checkCocktailMischbar(){
    for(int i = 0; i< theMischbaresRezeptbuch->getNumberOfRecipes(); ++i){
        if(!checkDosierer(theMischbaresRezeptbuch->getRecipe(i))){
            theMischbaresRezeptbuch->getRecipe(i)->setMischbar(false);
        }
    }
}