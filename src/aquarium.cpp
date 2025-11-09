#include <vector>
#include <iostream>
#include <memory>
#include <algorithm>
#include <random>

#include "poisson.h"
#include "aquarium.h"


//----------------------------------------------------------------//

Aquarium::Aquarium(std::vector<std::shared_ptr<Poisson>>pPoissons, std::vector<int> const pSizes)
{
    mPoissons = pPoissons; 
    addAlgues(pSizes);
}

//----------------------------------------------------------------//

void Aquarium::addAlgue(int pSize)
{
    std::shared_ptr<Algue> lAlgue = std::make_shared<Algue> (pSize,mIdAlgue);
    mAlgues.push_back(lAlgue);
    ++mIdAlgue; 
}

//----------------------------------------------------------------//

void Aquarium::addAlgues(std::vector<int> const pSizes)
{
    for 
        (unsigned int lI = 0; lI < pSizes.size(); ++lI)
    {
        std::shared_ptr<Algue> lAlgueTemp = std::make_shared<Algue> (pSizes[lI],mIdAlgue);
        mAlgues.push_back(lAlgueTemp);
        ++mIdAlgue; 
    }
}

//----------------------------------------------------------------//

//----------------------------------------------------------------//

void Aquarium::addPoisson(std::shared_ptr<Poisson> pPoisson)
{
    mPoissons.push_back(pPoisson); 
}

//----------------------------------------------------------------//

void Aquarium::printInfo()
{
    std::cout<<"----------- "<< mPoch << " ------------"<<std::endl;
    std::cout<<"Nombres d'algues : "<<mAlgues.size()<<std::endl;
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
    std::vector<int> lDeadFish;  
    std::vector<int> lDeadAlgues;  
    for 
        (auto& p : mPoissons)
    {
        if (p->isLive())
            switch (p->getType())
            {
                case TypePoisson::HERBIVORE:
                {
                    if 
                        (!mAlgues.empty())
                    {
                        std::random_device rd;           
                        std::mt19937 gen(rd());        
                        std::uniform_int_distribution<> distrib(0, (mAlgues.size()-1));

                        int lRandomNumber = distrib(gen);
                        if (mAlgues[lRandomNumber]->isDead())
                        {
                            mAlgues[lRandomNumber]->beEat();
                            if (mAlgues[lRandomNumber]->isDead()) {lDeadAlgues.push_back(lRandomNumber);}
                        }
                    }
                }
                case TypePoisson::CARNIVORE:
                {
                    std::random_device rd;           
                    std::mt19937 gen(rd());        
                    std::uniform_int_distribution<> distrib(0, (mPoissons.size()-1)*10);

                    int lRandomNumber = distrib(gen);
                    if (lRandomNumber < mPoissons.size())
                    {
                        if 
                            (mPoissons[lRandomNumber]->getType() == TypePoisson::HERBIVORE)
                        {
                            mPoissons[lRandomNumber]->killFish();
                            lDeadFish.push_back(lRandomNumber);
                        }
                    }
                }
                    
                
            }      
    }
    std::sort(lDeadFish.begin(), lDeadFish.end());
    for (int lI : lDeadFish) 
    {
        if (lI < mPoissons.size())
            mPoissons.erase(mPoissons.begin() + lI);
    }
    std::sort(lDeadAlgues.begin(), lDeadAlgues.end());
    for (int lI : lDeadAlgues) 
    {
        if (lI < mAlgues.size())
            mAlgues.erase(mAlgues.begin() + lI);
    }
    ++mPoch;
}