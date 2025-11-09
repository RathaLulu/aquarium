#include <iostream>

#include "Algue.h"

//----------------------------------------------------------------//

Algue::Algue(int pSize, int pId) : mSize(pSize), mId(pId)
{
    if (mSize < 1) {mSize = 1;} 
}

//----------------------------------------------------------------//

void Algue::evPousse()
{
    ++mSize;
}

//----------------------------------------------------------------//

int Algue::getSize() const
{
    return mSize;
}

//----------------------------------------------------------------//

void Algue::printInfo() const
{
    std::cout<<"Plante iD : "<<mId<<" Taille : " <<mSize<<std::endl;
}

//----------------------------------------------------------------//

bool Algue::isDead() const 
{
    return mSize == 0; 
}

//----------------------------------------------------------------//

void Algue::beEat()
{
    --mSize;
}