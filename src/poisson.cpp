#include "poisson.h"
#include <iostream>
#include <math.h>
#include <random>


std::ostream& operator<<(std::ostream& os, Sexe s) {
    static const char* SexeNames[] = {"Male", "Femelle", "Inconnu"};
    return os << SexeNames[static_cast<int>(s)];
}

std::ostream& operator<<(std::ostream& os, Race s) {
    static const char* RacesNamesCar[] = {"Merou", "thon", "Poisson-clown","Sole", "Bare", "Carpe"};
    return os << RacesNamesCar[static_cast<int>(s)];
}

//----------------------------------------------------------------//

Poisson::Poisson(const std::string& pName,Sexe pSexe, const std::vector<double> pPosLim)
{
    mName = pName; 
    mSexe = pSexe; 
    mPosLim[0] = pPosLim[0];
    mPosLim[1] = pPosLim[1];
    mPosLim[2] = pPosLim[2];
    mPosLim[3] = pPosLim[3];
    std::random_device lRd;  // Source d'entropie
    std::mt19937 gen(lRd()); // Générateur pseudo-aléatoire
    std::uniform_real_distribution<double> distx(mPosLim[0],  mPosLim[1]); 
    std::uniform_real_distribution<double> disty(mPosLim[2],  mPosLim[3]); 
    std::uniform_real_distribution<double> distvx(0,  mSpeed);  
    mPos.x = distx(gen);
    mPos.y = disty(gen);
    mPos.vx = distvx(gen); 
    mPos.vy = std::sqrt(std::pow(mSpeed, 2) -  std::pow(mPos.vx, 2)) ;
}

//----------------------------------------------------------------//

void Poisson::sayHello() const
{
    std::cout<<"Hello, my name is "<<mName<<" and I'am a "<<mSexe<<" fish"<<std::endl; 
}

//----------------------------------------------------------------//

void Poisson::beAttack()
{
    mLife = mLife - 4; 
}

//----------------------------------------------------------------//

void Poisson::setEat()
{
    mHasEat = true; 
}

//----------------------------------------------------------------//

void Poisson::initEat()
{
    if 
        (mHasEat)
    {
        mLife = mLife + 2; 
        if (mLife > 20) {mLife = 20;}
    }
    mHasEat = false;
}

//----------------------------------------------------------------//

void Poisson::dontEat()
{
    mLife = mLife - 3; 
}

//----------------------------------------------------------------//

std::string Poisson::getName() const
{
    return mName;
}

//----------------------------------------------------------------//

int Poisson::getLife() const 
{
    return mLife;
}

//----------------------------------------------------------------//

Pos Poisson::getPos() const
{
    return mPos; 
} 