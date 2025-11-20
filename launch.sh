#!/usr/bin/env bash

if [ -d "build" ]; then
    ./build/aquarium_exec
else
    echo "Absence de dossier build"
fi