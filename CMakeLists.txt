cmake_minimum_required(VERSION 3.10)
project(aquarium)

# Définit la version du standard C++
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include_directories(src)

set(SOURCES
    src/main.cpp
    src/poisson.cpp
    src/aquarium.cpp
    src/herbivore.cpp
    src/carnivore.cpp
)

# Ajoute l’exécutable à construire
add_executable(aquarium ${SOURCES})