//@(#) Schuettler.cpp


#include "Schuettler.h"

Schuettler::Schuettler() : InternalDevice() {
}

void Schuettler::doIt(float time) {
    myTimer->sleep(time * 1000);
    std::cout << std::endl;
}
