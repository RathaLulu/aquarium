#include "poisson.h"
#include <iostream>


Poisson::Poisson(const std::string& pName,Sexe pSexe)
{
    mName = pName; 
    mSexe = pSexe; 
}

void Poisson::sayHello()
{
    std::cout<<"Hello, my name is "<<mName<<std::endl; 
}