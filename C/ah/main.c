#include "Headers\ahh.h"


int main(){
    int i;
    arbre tree;
  clrscr();
 do{
     clrscr();
    rectangle(15,3,25,2);
    gotoxy(25,4);
    printf("MENU");

    rectangle(15,7,25,7);
    gotoxy(16,8);
    printf("1- Creer un arbre");
    gotoxy(16,9);
    printf("2-Ajouter un noeud");
    gotoxy(16,10);
    printf("3-Afficher un arbre");
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
        case 1:clrscr();
                printf("Entrez le nom ");
                creerTree(&tree);
            break ;
        case 2:clrscr();printf("2");
                break ;
        case 3:clrscr();
                afficherArbre(&tree);
            break ;
        case 4:clrscr();printf("4");
                break ;
    }
    printf("\n\n");
    }while(i!=5);
    return 0;
}
