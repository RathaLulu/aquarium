#ifndef AQUARIUM_H
#define AQUARIUM_H 

#include <vector>
#include <memory>

#include "poisson.h"
#include "algue.h"

class Aquarium
{
    public : 
    /*
    */
    Aquarium();
    /*
    */
    Aquarium(std::vector<std::shared_ptr<Poisson>> pPoissons, std::vector<int> const pSizes);
    /*
    */
    void nextTour(); 
    /*
    */
    void addPoisson(std::shared_ptr<Poisson> pPoisson); 
    /*
    */
    void addAlgue(int pSize); 
    /*
    */
    void addAlgues(std::vector<int> const pSizes); 
    /*
    */
    void printInfo();
    /*
    */
    void PassTour(); 
    /*
    */
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
    /*
    */
    std::vector<std::shared_ptr<Algue>> mAlgues;
    /*
    */
    int mIdAlgue = 0;

};

#endif