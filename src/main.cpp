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
    auto fish1 = std::make_shared<Poisson>("Hector", Sexe::MALE);
    auto fish2 = std::make_shared<Poisson>("Nemo", Sexe::MALE);
    auto fish3 = std::make_shared<Poisson>("Carle", Sexe::FEMELLE);
    auto fish4 = std::make_shared<Poisson>("COLLE", Sexe::FEMELLE);
    auto carn1 = std::make_shared<Carnivore>("Titou", Sexe::MALE, Race::POISSONCLOW);
    auto herb1 = std::make_shared<Carnivore>("Titou", Sexe::MALE, Race::CARPE);

    std::vector<std::shared_ptr<Poisson>> poissons {fish1, fish2, fish3};

    Aquarium Aqua(poissons, Nalges);
    Aqua.printInfo();

    Aqua.addAlges();
    Aqua.addAlges(50);
    Aqua.addPoisson(fish4);
    Aqua.addPoisson(carn1);
    Aqua.addPoisson(herb1);
    Aqua.printInfo();
        
    return 1; 
}
