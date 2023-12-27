#ifndef SQUARE_FUNCS
#define SQUARE_FUNCS
// Modern compilers support a simpler, alternate form of header guards using the "#pragma once"
// preprocessor directive:
// With #pragma once, we’re requesting that the compiler guard the header.
/*
There is one known case where #pragma once will typically fail. If a header file is copied so that
it exists in multiple places on the file system, if somehow both copies of the header get included,
header guards will successfully de-dupe the identical headers, but #pragma once won’t (because the
compiler won’t realize they are actually identical content).
*/

int getSquareSides();					// forward declaration for getSquareSides
int getSquarePerimeter(int sideLength); // forward declaration for getSquarePerimeter

#endif

// BestPractice
// If a header file is paired with a code file (e.g. add.h with add.cpp), they should both have the
// same base name (add).

//Source files should #include their paired header file (if one exists).

// Do not put function and variable definitions in your header files (for now).
// Defining either of these in a header file will likely result in a violation of the one-definition
// rule (ODR) if that header is then #included into more than one source (.cpp) file.