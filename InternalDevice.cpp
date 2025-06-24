//@(#) InternalDevice.cpp


#include "InternalDevice.h"

InternalDevice::InternalDevice() {
    myTimer = Timer::getInstance();
    this->zeiteinheit = 0;
    this->doinIt = 0;
}

void InternalDevice::putzen() {
    //std::cout << "Ich putze mich..." << std::endl;
    //myTimer->sleep(500);
    //std::cout << "Ich bin fertig mit putzen!" << std::endl;
}
