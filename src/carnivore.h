#ifndef CARNIVORE_H
#define CARBIVORE_H

#include <memory>

#include "poisson.h"

class Carnivore : public Poisson
{
    /*
    */ 
    public : 
    /*
    */ 
    Carnivore(const std::string& pName, Sexe pSexe, Race pRace); 
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
    Race mRace; 

};

#endif