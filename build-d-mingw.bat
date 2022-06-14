:: Disable the echo
@echo off

:: Make build directory if it doesn't exist
echo [BUILD SCRIPT] Creating build directory if it doesn't exist...
if not exist "build/" mkdir build

:: Enter build directory
cd build

:: Create debug directory if it doesn't exist
echo [BUILD SCRIPT] Creating debug directory if it doesn't exist...
if not exist "debug/" mkdir debug

:: Enter debug directory
cd debug

:: Generate makefile for mingw debug build with cmake
echo [BUILD SCRIPT] Generating makefile for mingw debug build with cmake...
cmake -G "MinGW Makefiles" -DCMAKE_BUILD_TYPE=Debug ../..

:: Build project with mingw32-make
echo [BUILD SCRIPT] Building project with mingw32-make...
mingw32-make

:: Return to main directory
cd ../..

echo [BUILD SCRIPT] Done.

PAUSE