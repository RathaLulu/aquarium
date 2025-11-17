# Aquarium 

Le but de ce projet est de créer une simulation d'aquarium en C++. 

Pour compiler, sur window, utiliser Visual Studio (MSVC) + Terminal VS.


## Dépendance 

### 1. **CMake**  
Téléchargement : https://cmake.org/download/  

### 2. **Protobuf**

A faire dans un dossier lib (attention à modifier le CMakeList en fonction de où est abseil et protobuf): 
git clone https://github.com/abseil/abseil-cpp.git 
git clone https://github.com/protocolbuffers/protobuf.git
cd protobuf
git checkout v31.1
mkdir build
cd build
cmake .. -G "Visual Studio 17 2022" -A x64 -Dprotobuf_BUILD_TESTS=OFF -DCMAKE_BUILD_TYPE=Release -DABSL_ROOT_DIR="C:/Users/lucas/Documents/code/abseil-cpp"
cmake --build . --config Release
Nécessaire si tu utilises la sérialisation.  
Téléchargement et installation (avec abseil):


Une fois installé, vérifie avec :

protoc --version

## Compilation 

install.bat
build.bat

## Exécution

launch_debug.bat (lance le fichier main.cpp)