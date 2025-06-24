// Main.cpp
// Ralf Hahn,  06.09.2016

#include "CocktailPro.h"
#include "RecipeBook.h"
#include <iostream>

int main(int argc, char * argv[]) {
    CocktailPro cp(argc, argv);
    cp.mischen(true);
    return 0;
}
