
#include <algorithm>

#include "RecipeStep.h"

RecipeStep::RecipeStep(void):m_Zutat("") {
    m_Menge = 0;
}

RecipeStep::~RecipeStep() {
}

std::string RecipeStep::getZutat(void) const {
    return m_Zutat;
}

float RecipeStep::getMenge(void) const {
    return m_Menge;
}

void RecipeStep::setZutat(std::string neueZutat) {
    this->m_Zutat = neueZutat;
}

void RecipeStep::setMenge(float neueMenge) {
    this->m_Menge = neueMenge;
}
