#ifndef AQUARIUM_H
#define AQUARIUM_H 

#include <vector>

#include "poisson.h"

class Aquarium
{
    public : 
    /*
    */
    Aquarium();
    /*
    */
    Aquarium(std::vector<Poisson> pPoissons, int const pAlgesN);
    /*
    */
    void nextTour(); 
    /*
    */
    void addPoisson(Poisson pPoisson); 
    /*
    */
    void addAlges(); 
    /*
    */
    void addAlges(int pAlgesN); 
    /*
    */
    void printInfo();
    /*
    */
    private :
    /*
    */
    int mPoch = 0; 
    /*
    */
    int mAlgeN = 0; 
    /*
    */
    std::vector<Poisson> mPoissons; 

};

#endif