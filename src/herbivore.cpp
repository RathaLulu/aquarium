#include <iostream>

#include "poisson.h"
#include "herbivore.h"


//----------------------------------------------------------------//

Herbivore::Herbivore(const std::string& pName,Sexe pSexe, Race pRace) : Poisson(pName, pSexe)
{
    
    mRace = pRace;
}

//----------------------------------------------------------------//

void Herbivore::sayHello() const
{
    std::cout<<"Hello, my name is "<<mName<<"and I'am a "<<mSexe<<" "<<mRace<<std::endl; 
}