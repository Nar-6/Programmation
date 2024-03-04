#include <stdio.h>
#include <conio.h>
#include <windows.h>

// Permet de positionner le curseur de souris sur l'Ã©cran Ã  l'endroit
// de coordonnÃ©es x,y
void gotoxy(int x, int y) 
{ 
    HANDLE hConsoleOutput; 
    COORD dwCursorPosition; 
    fflush(stdout); 
    dwCursorPosition.X = x; 
    dwCursorPosition.Y = y; 
    hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE); 
    SetConsoleCursorPosition(hConsoleOutput,dwCursorPosition); 
} 

// Pour effacer l'Ã©cran 
void clrscr()
{ 
  system("cls"); 
} 
