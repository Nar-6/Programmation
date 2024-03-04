#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <string.h>

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
void initTree(arbre *tr){
    tr=NULL;
}

arbre *creerTree(char nomAMettre[]){
    arbre *tr=malloc(sizeof(arbre));
    if(tr==NULL){
        printf("Erreur allocation memoire !\n");
        exit(EXIT_FAILURE);
    }
    strcpy(tr->nom,nomAMettre);
    tr->fils=NULL;
    tr->frere=NULL;
    tr->parent=NULL;

        printf("creation de %s\n", tr->nom);
    return tr;
}

arbre *creerTreeAvance(char nomAMettre[]){
    arbre *tr=creerTree(nomAMettre),*tr2,*tmp,*garde;
    tr2=tr;
    garde=tr;
    char choix1,choix2;
    char i[100],j[100],k[100];
    printf("%s A t il des fils?(O/N) \n",nomAMettre);
        fflush(stdin);
    scanf("%c",&choix1);
    if(choix1=='o'|| choix1=='O'){
        printf("quel est son nom ? \n");
        fflush(stdin);
        scanf("%s",k);
        tmp=creerTreeAvance(k);
        tr->fils=tmp;
        tmp->parent=tr;
        tr=tr->fils;
    }else{
        printf("ok\n");
    }
    printf("%s A t il des frere?(O/N) \n",nomAMettre);
            fflush(stdin);
    scanf("%c",&choix2);
    if(choix2=='o'|| choix2=='O'){
        printf("quel est son nom ? \n");
        fflush(stdin);
        scanf("%s",j);
        tmp=creerTreeAvance(j);
        tr2->frere=tmp;
        tmp->parent=tr2;
        tr2=tr2->frere;
    }else{
        printf("ok\n");
    }

    return garde;
}


void afficherArbrePre(arbre *tr){
     if(tr==NULL) {
         printf("l\'arbre est vide");
         return;
     }

     if(tr->parent!=NULL){
         printf("(%s) -> (%s)\n",tr->parent->nom,tr->nom);
     }else{
         printf("(%s)\n",tr->nom);
     }

     if(tr->fils!=NULL){
         afficherArbrePre(tr->fils);
     }
     if(tr->frere!=NULL){
         afficherArbrePre(tr->frere);
     }
}

void afficherArbreFils(arbre *tr,char nomPere[]){
    arbre *tmp;
    tmp=tr->fils;
     if(tr==NULL) return;

    if(strcmp(tr->nom,nomPere)==0){
        printf("les fils de (%s) sont:",tr->nom);
        printf("->(%s)",tr->fils->nom);
        do{
            printf("->(%s)",tmp->frere->nom);
            tmp=tmp->frere;
        }while(tmp->frere!=NULL);
        printf("\n\n");
    }
    afficherArbreFils(tr->fils,nomPere);
    afficherArbreFils(tr->frere,nomPere);

}

void afficherArbreFrere(arbre *tr,char nomFrere[]){
    arbre *tmp,*tmp2;
    tmp=tr->frere;
    tmp2=tr->parent;
     if(tr==NULL) return;

    if(strcmp(tr->nom,nomFrere)==0){
        printf("les freres de (%s) sont:",tr->nom);
        do{
            if(tmp2==tmp2->frere){
                printf("->(%s)",tmp2->nom);
                tmp2=tmp2->parent;
            }else{
                return ;
            }
        }while(tmp2->frere==tmp2);
        do{
            printf("->(%s)",tmp->nom);
            tmp=tmp->frere;
        }while(tmp->frere!=NULL);

        printf("\n\n");
    }
    afficherArbreFrere(tr->fils,nomFrere);
    afficherArbreFrere(tr->frere,nomFrere);

}

void supTree(arbre *tr){
    if(tr==NULL){
        exit;
    }

    printf("%d a ete sup \n",tr->nom);

    supTree(tr->fils);
    supTree(tr->frere);

    free(tr);

}




int main(){
    int i;
    char nomAmettre[100],nomFrere[100],nomPere[100];
    arbre tree;
    initTree(&tree);
  clrscr();
 do{
    rectangle(50,3,25,2);
    gotoxy(60,4);
    printf("MENU");

    rectangle(50,7,25,10);
    gotoxy(51,8);
    printf("1- Creer un arbre");
    gotoxy(51,9);
    printf("2-Ajouter un noeud");
    gotoxy(51,10);
    printf("3-Afficher un arbre");
    gotoxy(51,11);
    printf("4-Rechercher un noeud");
    gotoxy(51,12);
    printf("5-Afficher les freres");
    gotoxy(51,13);
    printf("6-Afficher les fils");
    gotoxy(51,14);
    printf("7- Quitter");

    rectangle(50,20,25,2);
    gotoxy(51,21);
    printf("Votre choix: ");
    fflush(stdin);
    scanf("%d",&i);
    switch(i){
        case 1:clrscr();
                printf("Entrez le nom ");
                scanf("%s",nomAmettre);
                tree=*creerTreeAvance(nomAmettre);

            break ;
        case 2:clrscr();

                break ;
        case 3:clrscr();
                afficherArbrePre(&tree);
            break ;
        case 4:clrscr();printf("4");
                break ;
        case 5:clrscr();
                printf("Vous voulez voir les freres de qui ? ");
                scanf("%s",nomFrere);
                afficherArbreFrere(&tree,nomFrere);
            break ;
        case 6:clrscr();
                printf("Vous voulez voir les fils de qui ? ");
                fflush(stdin);
                scanf("%s",nomPere);
                afficherArbreFils(&tree,nomPere);
                break ;
        case 7:clrscr();
                supTree(&tree);
                break;

    }
    printf("\n\n");
    }while(i!=7);
    return 0;
}
