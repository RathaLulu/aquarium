#ifndef AQUARIUM_H
#define AQUARIUM_H 

#include <vector>
#include <memory>

#include "poisson.h"

class Aquarium
{
    public : 
    /*
    */
    Aquarium();
    /*
    */
    Aquarium(std::vector<std::shared_ptr<Poisson>> pPoissons, int const pAlgesN);
    /*
    */
    void nextTour(); 
    /*
    */
    void addPoisson(std::shared_ptr<Poisson> pPoisson); 
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
    std::vector<std::shared_ptr<Poisson>>mPoissons; 

};

#endif