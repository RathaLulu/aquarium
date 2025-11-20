#!/usr/bin/env bash

set -e  # stop en cas d’erreur

# Supprimer le dossier build s'il existe
if [ -d "build" ]; then
    echo "Suppression du dossier build existant..."
    rm -rf build
fi

# Recréer le dossier build
echo "Création du dossier build..."
mkdir build
cd build

# Génération avec CMake et compilation avec Ninja
echo "Configuration CMake..."
cmake -G Ninja ..

echo "Compilation..."
ninja

echo "Build terminé avec succès !"