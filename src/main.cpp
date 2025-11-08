#include <iostream>
#include <vector>

#include "poisson.h"
#include "aquarium.h"

int main() 
{
    Poisson fish1("Hector", Sexe::MALE);
    Poisson fish2("Nemo", Sexe::MALE);
    Poisson fish3("Carle", Sexe::FEMELLE);
    Poisson fish4("COLLE", Sexe::FEMELLE);
    int Nalges = 100; 
    std::vector<Poisson> Poissons {fish1, fish2, fish3}; 
    Aquarium Aqua(Poissons, Nalges);
    Aqua.printInfo();
    Aqua.addAlges();
    Aqua.addAlges(50);
    Aqua.addPoisson(fish4);
    Aqua.printInfo();
    return 1; 
}
