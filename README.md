# ArchiChecker

ArchiChecker is a very simple tool used to check whether a Windows executable was compiled for 32-bit or 64-bit architecture.

## Install

You can install either by building yourself, or downloading the pre-compiled binaries on the release page.

If you want to be able to use the program from anywhere on the pc, you can put the executable in a folder and add the folder to the PATH environment variable.

## Build

To build ArchiChecker, if you have MinGW, or MinGW-W64, you can use the included build scripts. To build in debug mode, double-click on `build-d-mingw.bat`, or for release mode, double-click on `build-r-mingw.bat`. For this to work you much also have CMake installed on your system and added to the path, and MinGW must be added to the path.

Otherwise, you can build it however you want. Use CMake to genrate a build system for your compiler of choice, or heck you could even just open the code in an IDE and build it from there. The whole project exists within a single `main.cpp` file, so you can use any compiler you want.

## Usage

It is super simple and easy to use ArchiChecker. Simply run it in the command line and pass the path to the executable you want to check.

### Examples

If you want to check whether the executable `myexe.exe` was compiled for 32-bit or 64-bit architecture, you can simply run `archichecker myexe.exe`.

If `myexe.exe` was compiled for 32-bit architecture, you would see the following output:

```
The selected binary is 32 bit.
Machine type: 014c
```

But if it was compiled for 64-bit architecture, you would see the following output:

```
The selected binary is 64 bit.
Machine type: 8664
```

And if ArchiChecker couldn't determine the architecture, you would see the following output:

```
Could not determine if the binary is 32 bit or 64 bit.
This could mean it was compiled for another platform, or it is not reognized.
Machine type: ????
```

Where `????` is what ArchiChecker found where the PE header machine type should be.

For obvious reasons, passing anything other than a Windows binary to ArchiChecker will result in an error, or the program will crash.

Also remember that if you did not add to PATH, you will need to call ArchiChecker from the folder it is in using `./archichecker`, or use the full path to it.

You can pass the entire path to the executable to ArchiChecker if it is not in the current directory.