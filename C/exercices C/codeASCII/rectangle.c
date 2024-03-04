#include <stdio.h>
#include <stdlib.h>
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

int main(){
    int i,j;
    for(j=5;j<11;j++){
        for(i=15;i<26;i++){
            gotoxy(i,j);
            if(i==15){
                printf("%c",218); 
            }
            printf("%c",196);
            if(i==25){
                printf("%c",191); 
            }

        }
    }
    // printf("%c",218);
    // for(i=0;i<10;i++){
    //     printf("%c",196);
    // }
    // printf("%c\n",191);
    // for(i=0;i<5;i++){
    //     printf("%c\n",179);
    // }

}