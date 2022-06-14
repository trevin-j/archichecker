:: Disable the echo
@echo off

:: Make build directory if it doesn't exist
echo [BUILD SCRIPT] Creating build directory if it doesn't exist...
if not exist "build/" mkdir build

:: Enter build directory
cd build

:: Create release directory if it doesn't exist
echo [BUILD SCRIPT] Creating release directory if it doesn't exist...
if not exist "release/" mkdir release

:: Enter debug directory
cd release

:: Generate makefile for mingw release build with cmake
echo [BUILD SCRIPT] Generating makefile for mingw release build with cmake...
cmake -G "MinGW Makefiles" -DCMAKE_BUILD_TYPE=Release ../..

:: Build project with mingw32-make
echo [BUILD SCRIPT] Building project with mingw32-make...
mingw32-make

:: Return to main directory
cd ../..

echo [BUILD SCRIPT] Done.

PAUSE