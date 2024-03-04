#ifndef AHH_H_INCLUDED
#define AHH_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>

typedef struct noeud arbre;
struct noeud{
    char nom[100];
    arbre *fils;
    arbre *frere;
    arbre *parent;
};

// Permet de positionner le curseur de souris sur l'écran à l'endroit
// de coordonnées x,y
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

// Pour effacer l'écran
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

void creerTree(arbre *tree){
    arbre *tr;
    scanf("%s", tree->nom);
    tree->fils=NULL;
    tree->frere=NULL;
    tree->parent=NULL;
}

void afficherArbre(arbre *tree){
    // do{
        printf("Reagrde %s \n\n",tree->nom);
        // tree=tree->frere;
    // }while(tree!=NULL);
}


#endif // AHH_H_INCLUDED
