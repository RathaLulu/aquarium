#include <vector>
#include <iostream>
#include <memory>
#include <algorithm>
#include <random>

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
    std::cout<<"----------- "<< mPoch << " ------------"<<std::endl;
    std::cout<<"Nombres d'alges : "<<mAlgeN<<std::endl;
    std::cout<<"Listes des poissons : "<<std::endl;
    for 
        (unsigned int lI = 0; lI < mPoissons.size(); ++lI)
    {
        mPoissons[lI]->sayHello();
    }
} 

//----------------------------------------------------------------//

void Aquarium::PassTour()
{
    std::vector<int> lDead;  
    for 
        (auto& p : mPoissons)
    {
        if (p->isLive())
            switch (p->getType())
            {
                case TypePoisson::HERBIVORE:
                    --mAlgeN;
                case TypePoisson::CARNIVORE:
                {
                    std::random_device rd;           // source d'entropie (matérielle si dispo)
                    std::mt19937 gen(rd());          // moteur Mersenne Twister
                    std::uniform_int_distribution<> distrib(0, (mPoissons.size()-1)*10); // loi uniforme entre 0 et N

                    int lRandomNumber = distrib(gen);
                    std::cout<<lRandomNumber<<std::endl;
                    if (lRandomNumber < mPoissons.size())
                    {
                        if 
                            (mPoissons[lRandomNumber]->getType() == TypePoisson::HERBIVORE)
                        {
                            mPoissons[lRandomNumber]->killFish();
                            lDead.push_back(lRandomNumber);
                        }
                    }
                }
                    
                
            }      
    }
    std::sort(lDead.begin(), lDead.end());
    for (int lI : lDead) 
    {
        if (lI < mPoissons.size())
            mPoissons.erase(mPoissons.begin() + lI);
    }
    ++mPoch;
}