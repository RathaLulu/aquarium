#include <iostream>

#include "poisson.h"
#include "carnivore.h"

//----------------------------------------------------------------//

Carnivore::Carnivore(const std::string& pName,Sexe pSexe,std::vector<double> pPosLim ,Race pRace) : Poisson(pName, pSexe, pPosLim)
{
    mRace = pRace;
    
}

//----------------------------------------------------------------//

void Carnivore::sayHello() const
{
    std::cout<<"Hello, my name is "<<mName<<"and I'am a "<<mSexe<<" "<<mRace<<std::endl; 
}