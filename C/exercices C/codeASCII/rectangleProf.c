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

void rectangle(int x,int y, int l, int h){
    int i;
    gotoxy(x,y);printf("%c",218);
    gotoxy(x+l,y);printf("%c",191);
    gotoxy(x,y+h);printf("%c",192);
    gotoxy(x+l,y+h);printf("%c",217);
    for(i=1;i<l;i++){
        gotoxy(x+i,y);printf("%c",196);
        gotoxy(x+i,y+h);printf("%c",196);
    }
    for(i=1;i<h;i++){
        gotoxy(x,y+i);printf("%c",179);
        gotoxy(x+l,y+i);printf("%c",179);
    }
        printf("\n\n");

}


int main(){
    int i;
  clrscr();
  do{
    rectangle(15,3,25,2);
    gotoxy(25,4);
    printf("MENU");

    rectangle(15,7,25,7);
    gotoxy(16,8);
    printf("1- Creer une liste");
    gotoxy(16,9);
    printf("2-Ajouter un noeud");
    gotoxy(16,10);
    printf("3-Afficher une liste");
    gotoxy(16,11);
    printf("4-Rechercher un noeud");
    gotoxy(16,12);
    printf("5- Quitter");

    rectangle(15,16,25,2);
    gotoxy(16,17);
    printf("Votre choix: ");
    fflush(stdin);
    scanf("%d",&i);
    switch(i){
        case 1:clrscr();printf("1");
                break ;
        case 2:clrscr();printf("2");
                break ;
        case 3:clrscr();printf("3");
                break ;
        case 4:clrscr();printf("4");
                break ;
    }
    printf("\n\n");
    }while(i!=5);
    return 0;
}