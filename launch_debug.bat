@echo off
REM ============================
REM Lance le code en debug (Windows)
REM ============================

set BUILD_DIR=build/Debug

cd %BUILD_DIR%

echo START
aquarium.exe
echo END

cd ../..
