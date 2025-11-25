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
    std::vector<double> aqua_limit {0,10,0,10}; 
   auto fish1 = std::make_shared<Carnivore>("Hector", Sexe::MALE,aqua_limit ,Race::MEROU);
   auto fish2 = std::make_shared<Herbivore>("Nemo", Sexe::MALE,aqua_limit, Race::CARPE);
   auto fish3 = std::make_shared<Herbivore>("Carle", Sexe::FEMELLE,aqua_limit ,Race::THON);
  //  auto fish4 = std::make_shared<Herbivore>("COLLE", Sexe::FEMELLE, Race::BARE);
 //   auto carn1 = std::make_shared<Carnivore>("Titou", Sexe::MALE, Race::POISSONCLOW);
  //  auto herb1 = std::make_shared<Herbivore>("Titou", Sexe::MALE, Race::CARPE);

    std::vector<std::shared_ptr<Poisson>> poissons {fish1};
    std::vector<int> sizes {};
  

    std::string file {"/home/lucas/code/aquarium/data/test.json"};
    Aquarium Aqua(aqua_limit, poissons, sizes);

    Aqua.setFile(file);


    Aqua.aquariumTojson(true);
    int N = 40; 
    for (int i = 0; i<N; ++i)
    {
        Aqua.PassTour();
        Aqua.aquariumTojson(true);
    }

    Aqua.closeFile();
        
    return 1; 
}
