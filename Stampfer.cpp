//@(#) Stampfer.cpp


#include "Stampfer.h"

Stampfer::Stampfer() : InternalDevice() {
}

void Stampfer::doIt(float time) {
    myTimer->sleep(time * 1000);
    std::cout << std::endl;
}
