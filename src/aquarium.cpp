#include <vector>
#include <iostream>
#include <memory>

#include "poisson.h"
#include "aquarium.h"


//----------------------------------------------------------------//

Aquarium::Aquarium(std::vector<std::shared_ptr<Poisson>>pPoissons, int const pAlgesN)
{
    mAlgeN = pAlgesN; 
    mPoissons = pPoissons; 
}

//----------------------------------------------------------------//

void Aquarium::addAlges()
{
    ++mAlgeN;
}

//----------------------------------------------------------------//

void Aquarium::addAlges(int pAlgesN)
{
    mAlgeN = mAlgeN + pAlgesN; 
}

//----------------------------------------------------------------//

void Aquarium::addPoisson(std::shared_ptr<Poisson> pPoisson)
{
    mPoissons.push_back(pPoisson); 
}

//----------------------------------------------------------------//

void Aquarium::printInfo()
{
    std::cout<<"Nombres d'alges : "<<mAlgeN<<std::endl;
    std::cout<<"Listes des poissons : "<<std::endl;
    for 
        (unsigned int lI = 0; lI < mPoissons.size(); ++lI)
    {
        mPoissons[lI]->sayHello();
    }
} 