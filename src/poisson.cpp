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
    std::uniform_real_distribution<double> distvx(-mSpeed,  mSpeed);  
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
    mLife = mLife - 0; 
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
        mLife = mLife + 0; 
        if (mLife > 20) {mLife = 20;}
    }
    mHasEat = false;
}

//----------------------------------------------------------------//

void Poisson::dontEat()
{
    mLife = mLife - 0; 
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

//----------------------------------------------------------------//

PosResult Poisson::posValid(const Pos pPos)
{
    /* 
    xmin    xmax    ymin    ymax    ->  Resultat    ->  Valeur   
    0       0       0       0       ->  No possible -> 0
    0       0       0       1       ->  No possible -> 1
    0       0       1       0       ->  No possible -> 2
    0       0       1       1       ->  No possible -> 3
    0       1       0       0       ->  no possible -> 4
    0       1       0       1       ->  coin BG     -> 5
    0       1       1       0       ->  coin HG     -> 6
    0       1       1       1       ->  trop gauche -> 7
    1       0       0       0       ->  no possible -> 8
    1       0       0       1       ->  coin BD     -> 9
    1       0       1       0       ->  coin HD     -> 10 
    1       0       1       1       ->  Trop droite -> 11
    1       1       0       0       ->  No possible -> 12 
    1       1       0       1       ->  Trop bas    -> 13
    1       1       1       0       ->  Trop haut   -> 14            
    1       1       1       1       ->  Valide      -> 15 
    */
    bool lXminVal = pPos.x >= mPosLim[0]; 
    bool lXmaxVal = pPos.x <= mPosLim[1]; 
    bool lYminVal = pPos.y >= mPosLim[2]; 
    bool lYmaxVal = pPos.y <= mPosLim[3]; 

    uint8_t lVal = (lXminVal << 3) | (lXmaxVal << 2) | (lYminVal << 1) | lYmaxVal;

    switch
            (lVal) 
    {
            case 5:  return PosResult::COIN_BG;
            case 6:  return PosResult::COIN_HG;
            case 7:  return PosResult::TROP_GAUCHE;
            case 9:  return PosResult::COIN_BD;
            case 10: return PosResult::COIN_HD;
            case 11: return PosResult::TROP_DROITE;
            case 13: return PosResult::TROP_BAS;
            case 14: return PosResult::TROP_HAUT;
            case 15: return PosResult::VALIDE;
            default: return PosResult::NOPOSSIBLE;
    }
}

//----------------------------------------------------------------//

void Poisson::nextPos()
{
    Pos lPosTemp;   
    lPosTemp.x = mPos.x + mPos.vx; 
    lPosTemp.y = mPos.y + mPos.vy;
    PosResult lCheckPos = posValid(lPosTemp);
    switch
        (lCheckPos)
    {
        case PosResult::VALIDE : break;  
        case PosResult::COIN_BG:
        case PosResult::COIN_BD:
        case PosResult::COIN_HD:
        case PosResult::COIN_HG: 
        {
            mPos.vx = -mPos.vx;
            mPos.vy = -mPos.vy;
            break;
        }
        case PosResult::TROP_BAS:
        case PosResult::TROP_HAUT:
        {
            mPos.vy = -mPos.vy;
            break;
        }
        case PosResult::TROP_DROITE:
        case PosResult::TROP_GAUCHE:
        {
            mPos.vx = -mPos.vx;
            break;
        }
        case PosResult::NOPOSSIBLE: 
        {
            std::cout<<"Position non valide"<<std::endl;
            mPos.x = 5; 
            mPos.y = 5; 
            return; 
        }

    }
    mPos.x = mPos.x + mPos.vx;
    mPos.y = mPos.y + mPos.vy;
}