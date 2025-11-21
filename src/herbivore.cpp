#include <iostream>

#include "poisson.h"
#include "herbivore.h"


//----------------------------------------------------------------//

Herbivore::Herbivore(const std::string& pName,Sexe pSexe,const std::vector<double> pPosLim ,Race pRace) : Poisson(pName, pSexe, pPosLim)
{
    
    mRace = pRace;
}

//----------------------------------------------------------------//

void Herbivore::sayHello() const
{
    std::cout<<"Hello, my name is "<<mName<<"and I'am a "<<mSexe<<" "<<mRace<<std::endl; 
}