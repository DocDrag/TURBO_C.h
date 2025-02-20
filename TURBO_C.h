/**
 * Turbo C++ Compatibility Library v1.0.0
 * 
 * This library provides Turbo C++-style console functions for modern compilers.
 * It has been tested on Windows using Dev C++ and Code::Blocks with the GNU GCC Compiler.
 * 
 * ⚠ Important Notes:
 * - Some functions may not be fully compatible with the original Turbo C++ environment.
 * - This library relies on Windows API for console manipulation and ANSI escape codes.
 * - You **must** run Dev C++ and Code::Blocks as Administrator to display extended ASCII characters correctly.
 * 
 * This library is **not** part of the mingw-w64 runtime package.
 * 
 * Provided by: https://github.com/DocDrag/TURBO_C.h
 */

#ifndef TURBO_C_H
#define TURBO_C_H

#include <stdlib.h>    // For srand
#include <time.h>      // For time
#include <windows.h>   // For SetConsoleTextAttribute, GetStdHandle

#define cprintf printf
#define cscanf scanf

// Function declarations
void clrscr();
void randomize();
void gotoxy(int, int);
void textcolor(int);
void textbackground(int);
void setcolor(int);
void delay(int);

// Macro for supporting different compilers (GCC, MSVC, etc.)
#ifdef _MSC_VER
#define INIT_CONSTRUCTOR __declspec(dllexport)
#else
#define INIT_CONSTRUCTOR __attribute__((constructor))
#endif

// A function that will be called as soon as the program starts.
INIT_CONSTRUCTOR void set_ascii_code_page() {
    SetConsoleOutputCP(437); // Set ASCII Code Page to 437 for extended ASCII characters
    
    printf("Turbo C++ Compatibility Library v1.0.0\n");
    printf("For Dev C++ and Code::Blocks\n");

    printf("Provided by: ");
    textcolor(9); // Set text color to blue
    printf("https://github.com/DocDrag/TURBO_C.h\n\n");
    textcolor(7); // Reset text color to default (light gray)

    printf("Note: You must run Dev C++ and Code::Blocks as Administrator.\n");
    printf("Certain extended ASCII characters may not display correctly otherwise.\n\n");
}

// Clears the console screen
void clrscr() {
    #ifdef _WIN32
        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        CONSOLE_SCREEN_BUFFER_INFO csbi;
        DWORD count;
        DWORD cellCount;
        COORD homeCoords = {0, 0};

        if (hConsole == INVALID_HANDLE_VALUE) return;
        if (!GetConsoleScreenBufferInfo(hConsole, &csbi)) return;
        cellCount = csbi.dwSize.X * csbi.dwSize.Y;

        // Clear console screen
        if (!FillConsoleOutputCharacter(hConsole, ' ', cellCount, homeCoords, &count)) return;
        if (!FillConsoleOutputAttribute(hConsole, csbi.wAttributes, cellCount, homeCoords, &count)) return;
        SetConsoleCursorPosition(hConsole, homeCoords);
    #else
        printf("\033[2J\033[H");  // ANSI Escape Code for clearing screen
        fflush(stdout);
    #endif
}

// Initializes the random number generator (similar to Turbo C's randomize)
void randomize() {
    srand(time(NULL));
}

// Moves the console cursor to the specified (x, y) position
#ifdef _WIN32
void gotoxy(int x, int y) {
    COORD coord;
    coord.X = x - 1;  // Windows API uses 0-based indexing
    coord.Y = y - 1;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
#else
void gotoxy(int x, int y) {
    printf("\033[%d;%dH", y, x);  // ANSI escape code for cursor positioning
}
#endif

// Function to set the text color in the console
void textcolor(int foreground_color) {
    foreground_color = foreground_color % 16; // Ensure value stays within 0-15
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), foreground_color);
}

// Function to set the background color in the console
void textbackground(int background_color) {
    background_color = background_color % 16; // Ensure value stays within 0-15
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (background_color << 4));
}

// Function to set both text and background colors in the console
void setcolor(int foreground_color, int background_color) {
    foreground_color = foreground_color % 16; // Ensure value stays within 0-15
    background_color = background_color % 16; // Ensure value stays within 0-15
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), foreground_color + (background_color << 4));
}

// Function to pause the program for a specified number of milliseconds
void delay(int milliseconds) {
    #ifdef _WIN32
        Sleep(milliseconds);
    #else
        struct timespec req, rem;
        req.tv_sec = milliseconds / 1000;
        req.tv_nsec = (milliseconds % 1000) * 1000000;
        nanosleep(&req, &rem);
    #endif
}

#endif // TURBO_C_H