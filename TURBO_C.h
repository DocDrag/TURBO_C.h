/**
 * This code works on Windows and has been tested using Dev C++ and Code::Blocks only.
 * Tested with GNU GCC Compiler.
 * Some functions may not be fully compatible with the Turbo C++ environment.
 * The code uses Windows APIs for console manipulation and ANSI escape codes.
 * Please open Dev C++ and Code::Blocks with Run as Administrator for better performance.
 * This file is not part of the mingw-w64 runtime package.
 */

#ifndef TURBO_C_H
#define TURBO_C_H

#include <stdlib.h>    // For system, srand
#include <time.h>      // For time
#include <windows.h>   // For SetConsoleTextAttribute, GetStdHandle