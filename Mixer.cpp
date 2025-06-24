//@(#) Mixer.cpp


#include "Mixer.h"

Mixer::Mixer() : InternalDevice() {

}

void Mixer::doIt(float time) {
    myTimer->sleep(time * 1000);
    std::cout << std::endl;
}
