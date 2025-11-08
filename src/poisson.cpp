#include "poisson.h"
#include <iostream>

std::ostream& operator<<(std::ostream& os, Sexe s) {
    static const char* SexeNames[] = {"Male", "Femelle", "Inconnu"};
    return os << SexeNames[static_cast<int>(s)];
}

//----------------------------------------------------------------//

Poisson::Poisson(const std::string& pName,Sexe pSexe)
{
    mName = pName; 
    mSexe = pSexe; 
}

//----------------------------------------------------------------//

void Poisson::sayHello() const
{
    std::cout<<"Hello, my name is "<<mName<<" and I'am a "<<mSexe<<" fish"<<std::endl; 
}