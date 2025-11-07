@echo off
REM ============================
REM Script de reconstruction CMake (Windows)
REM Supprime le dossier build/, le recrée et compile
REM ============================

set BUILD_DIR=build

echo  Suppression de l'ancien dossier de build...
if exist %BUILD_DIR% (
    rmdir /s /q %BUILD_DIR%
)

echo  Creation du dossier de build...
mkdir %BUILD_DIR%
cd %BUILD_DIR%

echo  Configuration du projet avec CMake...
cmake ..

if errorlevel 1 (
    echo Erreur pendant la configuration CMake.
    exit /b 1
)

echo  Compilation du projet...
cmake --build . --config Release

if errorlevel 1 (
    echo Erreur pendant la compilation.
    exit /b 1
)

echo  Build termine avec succes !
cd ..