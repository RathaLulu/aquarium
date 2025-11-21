#ifndef CARNIVORE_H
#define CARBIVORE_H

#include <memory>

#include "poisson.h"
#include <vector>

class Carnivore : public Poisson
{
    /*
    */ 
    public : 
    /*
    */ 
    Carnivore(const std::string& pName, Sexe pSexe,std::vector<double> pPosLim ,Race pRace); 
    /*
    */ 
    virtual ~Carnivore() = default;
    /*
    */ 
    void sayHello() const override ; 
    /*
    */
    TypePoisson getType() const override { return TypePoisson::CARNIVORE; }
    private : 
    /*
    */
    Race mRace; 
    /*
    */

};

#endif