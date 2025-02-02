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

#define cprintf printf
#define cscanf scanf

// Macro for supporting different compilers (GCC, MSVC, etc.)
#ifdef _MSC_VER
#define INIT_CONSTRUCTOR __declspec(dllexport)
#else
#define INIT_CONSTRUCTOR __attribute__((constructor))
#endif

// A function that will be called as soon as the program starts.
INIT_CONSTRUCTOR void set_ascii_code_page() {
    system("chcp 437");  // Set ASCII code page to 437 (for extended ASCII characters)
    
    printf("Turbo C++ compatibility library for Dev C++ and Code::Blocks\n");
    printf("Provided by: https://github.com/DocDrag/TURBO_C.h\n\n");

    printf("Tip: Run Dev C++ and Code::Blocks as Administrator for better performance.\n\n");
}

// Clears the console screen
void clrscr() {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    DWORD count;
    DWORD cellCount;
    COORD homeCoords = {0, 0};

    // Get the number of character cells in the current buffer
    if (hConsole == INVALID_HANDLE_VALUE) return;
    if (!GetConsoleScreenBufferInfo(hConsole, &csbi)) return;
    cellCount = csbi.dwSize.X * csbi.dwSize.Y;

    // Fill the entire buffer with spaces
    if (!FillConsoleOutputCharacter(
            hConsole,
            (TCHAR) ' ',  // Character to write to the console (space)
            cellCount,
            homeCoords,
            &count
    )) return;

    // Fill the entire buffer with the current colors and attributes
    if (!FillConsoleOutputAttribute(
            hConsole,
            csbi.wAttributes,
            cellCount,
            homeCoords,
            &count
    )) return;

    // Move the cursor to the home coordinates
    SetConsoleCursorPosition(hConsole, homeCoords);
}

// Initializes the random number generator (similar to Turbo C's randomize)
void randomize() {
    srand(time(NULL));
}