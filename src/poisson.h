#ifndef POISSON_H
#define POISSON_H

#include <iostream>
#include <string>

enum class Sexe
{
    MALE,
    FEMELLE
};

static const char* SexeNames[] = {"Male", "Femelle"};

std::ostream& operator<<(std::ostream& os, Sexe s);

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