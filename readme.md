# Aquarium 

Le but de ce projet est de créer une simulation d'aquarium en C++. 

Pour compiler, sur window, utiliser Visual Studio (MSVC) + Terminal VS.


## Prérequis

- **Visual Studio 2022** avec support C++ Desktop  
- **CMake ≥ 3.10**  
- **Protobuf 31.1**  
- **Abseil** (header-only suffit)  

> Les binaires Windows de Protobuf ne suffisent pas pour lier `libprotobuf.lib`. Il faut compiler Protobuf depuis la source.

---

## Installation des dépendances

1. Créez un dossier `lib` pour les dépendances et clonez les dépôts :  

```bash
cd {YOURPROJET}/../
git clone https://github.com/abseil/abseil-cpp.git
cd abseil-cpp
mkdir -p build && cd build

cmake -G Ninja \
  -DCMAKE_BUILD_TYPE=Release \
  -DCMAKE_INSTALL_PREFIX=/usr/local \
  -DBUILD_SHARED_LIBS=ON \
  ..
ninja
sudo ninja install
cd {YOURPROJET}/../
git clone https://github.com/protocolbuffers/protobuf.git
mkdir -p build && cd build
cmake -G Ninja \
  -DCMAKE_BUILD_TYPE=Release \
  -DBUILD_SHARED_LIBS=ON \
  -Dprotobuf_BUILD_TESTS=OFF \
  -Dprotobuf_BUILD_EXAMPLES=OFF \
  -Dprotobuf_BUILD_PROTOC_BINARIES=ON \
  -DCMAKE_INSTALL_PREFIX=/usr/local \
  -DProtobuf_USE_ABSL=ON \
  ..
ninja
sudo ninja install

# Compilation du projet et lancement 

``` bash
build.sh
launch.sh
```
