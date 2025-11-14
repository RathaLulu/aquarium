@echo off
REM ============================
REM Script de fabrication des fichiers protobuf
REM Efface d'abord le dossier proto existant pour en re-crée un
REM ============================
set PROTO_DIR=proto


echo Suppression de l'ancien dossier de proto...
if exist %PROTO_DIR% (
    rmdir /s /q %PROTO_DIR%
)

echo Creation du nouveau dossier proto
mkdir %PROTO_DIR%


protoc -I=. --cpp_out=proto aquarium.proto