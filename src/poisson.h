#ifndef POISSON_H
#define POISSON_H

#include <iostream>
#include <string>

enum class Sexe
{
    MALE,
    FEMELLE
};

class Poisson
{
    public :
    /*
    */ 
    Poisson(const std::string& pName,Sexe pSexe);
    /*
    */ 
    void sayHello(); 
    /*
    */ 
    private : 
    /*
    */ 
    std::string mName; 
    /*
    */ 
    Sexe mSexe;

};

#endif //POISSON