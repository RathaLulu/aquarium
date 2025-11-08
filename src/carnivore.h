#ifndef CARNIVORE_H
#define CARBIVORE_H

#include <memory>

#include "poisson.h"

enum class RaceCar 
{
    MEROU, 
    THON, 
    POISSONCLOW 
};

static const char* RacesNames[] = {"Merou", "thon", "Poisson-clown"};

std::ostream& operator<<(std::ostream& os, RaceCar s);

class Carnivore : public Poisson
{
    /*
    */ 
    public : 
    /*
    */ 
    Carnivore(const std::string& pName, Sexe pSexe, RaceCar pRace); 
    /*
    */ 
    virtual ~Carnivore() = default;
    /*
    */ 
    void sayHello() const override ; 
    /*
    */
    private : 
    /*
    */
    RaceCar mRace; 

};

#endif