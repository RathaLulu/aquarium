#include <iostream>
#include <vector>
#include <memory>

#include "poisson.h"
#include "carnivore.h"
#include "herbivore.h"
#include "aquarium.h"

int main() 
{
    int Nalges{50};
    auto fish1 = std::make_shared<Carnivore>("Hector", Sexe::MALE, Race::MEROU);
    auto fish2 = std::make_shared<Herbivore>("Nemo", Sexe::MALE, Race::CARPE);
    auto fish3 = std::make_shared<Herbivore>("Carle", Sexe::FEMELLE, Race::THON);
    auto fish4 = std::make_shared<Herbivore>("COLLE", Sexe::FEMELLE, Race::BARE);
    auto carn1 = std::make_shared<Carnivore>("Titou", Sexe::MALE, Race::POISSONCLOW);
    auto herb1 = std::make_shared<Herbivore>("Titou", Sexe::MALE, Race::CARPE);

    std::vector<std::shared_ptr<Poisson>> poissons {fish1, fish2, fish3};
    std::vector<int> sizes {4,2,6,3,4,2,1,5,3,4,2,6,3,4,2,3,1,4,5,2,3};

    Aquarium Aqua(poissons, sizes);

   
    Aqua.addPoisson(fish4);
    Aqua.addPoisson(carn1);
    Aqua.addPoisson(herb1);


    Aqua.printInfo();
    int N = 20; 
    for (int i = 0; i<N; ++i)
    {
        Aqua.PassTour();
        Aqua.printInfo();
    }
        
    return 1; 
}
