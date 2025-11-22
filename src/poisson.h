#ifndef POISSON_H
#define POISSON_H

#include <iostream>
#include <string>
#include <memory>
#include <vector>

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

struct Pos 
{
    double x; 
    double y; 
    double vx; 
    double vy;
};

enum class PosResult : uint8_t {
    NOPOSSIBLE = 0,
    COIN_BG = 5,
    COIN_HG = 6,
    TROP_GAUCHE = 7,
    COIN_BD = 9,
    COIN_HD = 10,
    TROP_DROITE = 11,
    TROP_BAS = 13,
    TROP_HAUT = 14,
    VALIDE = 15
};

class Poisson
{
    public :
    //Poisson();
    /*
    */ 
    Poisson(const std::string& pName, Sexe pSexe, const std::vector<double> pPosLim); //pPosLim -> [xmin, xmax, ymin, ymax] correspond à coordonnées limite où le poisson sera initialisé.
    /*
    */ 
    virtual ~Poisson() = default;
    /*
    */ 
    virtual void beAttack();
    /*
    */  
    virtual bool isLive() const {return mLife > 0;}
    /*
    */ 
    virtual void sayHello() const;
    /*
    */ 
    virtual TypePoisson getType() const { return TypePoisson::NORMAL;}
    /*
    */ 
    virtual void setEat(); 
    /*
    */ 
    void initEat();
    /*
    */
    virtual bool getHasEat() const {return mHasEat;}
    /*
    */
    virtual void dontEat(); 
    /*
    */
    std::string getName() const;
    /*
    */
    int getLife() const;
    /*
    */
    Pos getPos() const; 
    /*
    */
    PosResult posValid(const Pos pPos);
    /*
    */
    void nextPos(); 
    protected : 
    /*
    */ 
    std::string mName; 
    /*
    */ 
    Sexe mSexe;
    /*
    */
    int mLife {20}; 
    /*
    */
    bool mHasEat {false}; 
    /*
    */
    Pos mPos; 
    /*
    */
    std::vector<double> mPosLim{0.0,0.0,0.0,0.0};
    /*
    */
    double mSpeed = 1.0; //mSpeed**2= (mPos.vx)**2 + (mPos.vy)**2

};

#endif //POISSON