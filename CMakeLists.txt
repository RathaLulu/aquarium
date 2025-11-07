cmake_minimum_required(VERSION 3.10)
project(HelloWorld)

# Définit la version du standard C++
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Ajoute l’exécutable à construire
add_executable(hello src/main.cpp)