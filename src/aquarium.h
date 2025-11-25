#ifndef AQUARIUM_H
#define AQUARIUM_H 

#include <vector>
#include <memory>
#include <fstream>

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
    Aquarium(const std::vector<double> pDim, std::vector<std::shared_ptr<Poisson>> pPoissons, std::vector<int> const pSizes);
    /*
    */
    ~Aquarium();
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
    void aquariumTojson(const bool pDoPrint);  
    /*
    */
    template <typename T>
    void deleteDead(std::vector<T>& pVector, std::vector<int> pDead);
    /*
    */
    void updatesPos(); 
    /*
    */
    void setFile(std::string pFileName); 
    /*
    */
    void closeFile(); 
    /*
    */
    private :
    void endTour();
    /*
    */
    int mPoch = 1; 
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
    /*
    */
    std::vector<double> mDim={0,0,0,0};
    /*
    */
    std::ofstream mFile;
    /*
    */
    std::string mFileName; 
    /*
    */
    bool mFirstSave{true}; 

};

#endif