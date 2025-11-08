#include <iostream>

#include "poisson.h"
#include "carnivore.h"

std::ostream& operator<<(std::ostream& os, RaceCar s) {
    static const char* RacesNames[] = {"Merou", "thon", "Poisson-clown"};
    return os << RacesNames[static_cast<int>(s)];
}

//----------------------------------------------------------------//

Carnivore::Carnivore(const std::string& pName,Sexe pSexe, RaceCar pRace) : Poisson(pName, pSexe)
{
    mRace = pRace;
    
}

//----------------------------------------------------------------//

void Carnivore::sayHello() const
{
    std::cout<<"Hello, my name is "<<mName<<"and I'am a "<<mSexe<<" "<<mRace<<std::endl; 
}