#ifndef HERBIVORE_H
#define HERBIVORE_H

#include <memory>

#include "poisson.h"
#include <vector>


class Herbivore : public Poisson
{
    /*
    */ 
    public : 
    /*
    */ 
    Herbivore(const std::string& pName, Sexe pSexe, const std::vector<double> pPosLim,Race pRace); 
    /*
    */ 
    virtual ~Herbivore() = default;
    /*
    */ 
    void sayHello() const override ; 
    /*
    */
    TypePoisson getType() const override { return TypePoisson::HERBIVORE; }
    private : 
    /*
    */
    Race mRace; 

};

#endif