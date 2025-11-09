#ifndef POISSON_H
#define POISSON_H

#include <iostream>
#include <string>
#include <memory>

enum class Sexe
{
    MALE,
    FEMELLE
};

static const char* SexeNames[] = {"Male", "Femelle"};

std::ostream& operator<<(std::ostream& os, Sexe s);

enum class Race
{
    MEROU, 
    THON, 
    POISSONCLOW,
    SOLE, 
    BARE, 
    CARPE
};

static const char* RacesNames[] = {"Merou", "thon", "Poisson-clown","Sole", "Bare", "Carpe"};

std::ostream& operator<<(std::ostream& os, Race s);

enum class TypePoisson { NORMAL, CARNIVORE, HERBIVORE };

class Poisson
{
    public :
    /*
    */ 
    Poisson(const std::string& pName,Sexe pSexe);
    /*
    */ 
    virtual ~Poisson() = default;
    /*
    */ 
    virtual void killFish();
    /*
    */  
    virtual bool isLive() const {return mLive;}
    /*
    */ 
    virtual void sayHello() const;
    /*
    */ 
    virtual TypePoisson getType() const { return TypePoisson::NORMAL;}
    /*
    */ 
    protected : 
    /*
    */ 
    std::string mName; 
    /*
    */ 
    Sexe mSexe;
    /*
    */
    bool mLive {true};
    /*
    */
    int mLife {20}; 

};

#endif //POISSON