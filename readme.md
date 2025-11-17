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

```powershell
git clone https://github.com/abseil/abseil-cpp.git
git clone https://github.com/protocolbuffers/protobuf.git
cd protobuf
git checkout v31.1
```
2. Créez un dossier build et configurez CMake :
```powershell
mkdir build
cd build
cmake .. -G "Visual Studio 17 2022" -A x64 `
-Dprotobuf_BUILD_TESTS=OFF `
-DCMAKE_BUILD_TYPE=Release `
-DABSL_ROOT_DIR="C:/Users/lucas/Documents/code/abseil-cpp"
```
3. Compilation 
```powershell
cmake --build . --config Release
```
4. Vérification (Dans un autre terminal)
```powershell
protoc --version
```
Vous devriez voir libprotoc 31.1.0.

# Compilation du projet et lancement 

```powershell
build.bat
launch_debug.bat
```
