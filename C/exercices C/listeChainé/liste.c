#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <string.h>


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
typedef struct cell cell;
struct cell{
    int val;
    cell *suivant;
    cell *prec;
};
typedef struct liste liste;
struct liste{
    cell *premier;
};


//initialiser la liste à une liste vide
void initList(liste *pL){
    pL->premier=NULL;//initialise la liste à une liste vide
    // pL->premier->suivant = NULL;
    // pL->premier->prec = NULL;
}

void ajoutElement(liste *L, int n) {
    // Ajout en tête
    cell *nouv;
    int i;
    for (i = 0; i < n; i++) {
        cell *p = L->premier;
        nouv = malloc(sizeof(cell));
        nouv->val = i;
        if ( p == NULL ) {
            nouv->suivant = NULL;
            nouv->prec = NULL;
            L->premier = nouv;
        } else{
            p->prec = nouv;
            nouv->suivant = p;
            nouv->prec = NULL;
            L->premier = nouv;
        }
    }
    printf("Les ont bien été ajoutés !\n");
}

int palyndrome(liste *L) {
    if ( L->premier == NULL) {
        printf("La liste est vide !");
        return 2;
    } else {
        cell *p = L->premier, *q ;
        int t = 0;
        while (p->suivant != NULL) {
            t++;
            q = p->suivant;
        }
        t = t / 2;
        for (int i = 0; i < t; i++){
            if (p->val != q->val) return 0;
            p = p->suivant;
            q = q->prec;
        }
        return 1;
    }
}

void inversList (liste *L) {
    if ( L->premier == NULL) {
        printf("La liste est vide !\n");
    } else {
        cell *p = L->premier, *q = NULL ;
        int t = 1, tmp;
        do {
            t++;
            q = p->suivant; 
            p = p->suivant;
        } while (p->suivant != NULL);
        p = L->premier;
        t = t / 2;
        for (int i = 0; i < t; i++){
            tmp = p->val;
            p->val = q->val;
            q->val = tmp;
            p = p->suivant;
            q = q->prec;
        }
        printf("La liste a ete inverse !\n");
    }
}

void afficheList(liste *L){
    if(L->premier==NULL){
        printf("La liste est vide !");
    }else{
        cell *pcr;
        pcr=L->premier;
        do{
            printf("Valeur : %d\n",pcr->val);
            pcr=pcr->suivant;
        }while (pcr!=NULL);
        printf("Voici la liste des etudiants !\n");
    }
}

void ajoutTete(liste *L, int i) {
    // Ajout en tête
    cell *nouv;
    cell *p = L->premier;
    nouv = malloc(sizeof(cell));
    nouv->val = i;
    if ( p == NULL ) {
        nouv->suivant = NULL;
        nouv->prec = NULL;
        L->premier = nouv;
    } else{
        p->prec = nouv;
        nouv->suivant = p;
        nouv->prec = NULL;
        L->premier = nouv;
    }
    printf("L'element a bien ete ajoute !\n");
}

void supDoub (liste *L) {
    cell *p = L->premier, *q = L->premier;
    if ( L->premier != NULL ){
        while (p->suivant != NULL){
            q = p->suivant;
            while (p->val == q->val) {
                p->suivant = q->suivant;
                if (q->suivant != NULL) q->suivant->prec = p;
                free(q);
                q = p->suivant;
            }
            p = p->suivant;
        }
    }
}

void triBulleChaine (liste *L){
    cell *p = L->premier;
    int tmp = 0,nbre = 0;
    bool permut = true;
    while (p->suivant != NULL) {
        nbre++;
        p = p->suivant;
    }
    while(permut == true ){
        p = L->premier;
        permut = false;
        for (int i = 0; i < nbre; i++){
            if (p->val > p->suivant->val){
                permut = true;
                tmp = p->val;
                p->val = p->suivant->val;
                p->suivant->val = tmp;
            }
            p = p->suivant;
        }
    }
}

void ajoutQueue (int x, liste *L) {
    if(L->premier==NULL){
        printf("La liste est vide !");
    }else{
        cell *pcr,*nouv;
        pcr=L->premier;
        do{
            pcr=pcr->suivant;
        }while (pcr->suivant!=NULL);
        nouv=malloc(sizeof(cell));
        nouv->val = x;
        nouv->suivant=pcr->suivant;
        pcr->suivant=nouv;
        nouv->prec=pcr;
        printf("\n");
        printf("Voici la liste des etudiants !\n");
    }
}

void supQueue(liste *L){

}

void supElement(liste *L,int x){
     if(L->premier==NULL){
        printf("La liste est vide !");
    }else{
        cell *p = L->premier;
        if (p->val == x){
            p->suivant->prec = NULL;
            L->premier = L->premier->suivant;
            printf("Element %d supprimé !\n", p->val);
            free(p);
        }else {
            cell *q;
            while( p->suivant != NULL && p->val != x){
                q = p;
                p = p->suivant;
            }
            if (p->val == x) {
                if (p->suivant == NULL) {
                    q->suivant = NULL;
                    printf("Element %d supprime !\n", p->val);
                    free(p);
                } else {
                    p->suivant->prec = q;
                    q->suivant = p->suivant;
                    printf("Element %d supprime !\n", p->val);
                    free(p);
                }
            }else{
                printf("Element introuvable !\n");
            }
        }
    }
}

void afficheInv (liste *L) {
     if(L->premier==NULL){
        printf("La liste est vide !");
    }else{
        cell *p = L->premier;
        while (p->suivant != NULL) {
            p = p->suivant;
        }
        do {
            printf("Valeur : %d\n",p->val);
            p = p->prec;
        } while (p != NULL);
        printf("Affichage inverse ! \n");
    }
}

bool recherche ( int x, liste *L) {
    if(L->premier==NULL){
        printf("La liste est vide !");
    }else{
        cell *pcr = L->premier;
        do{
            if (pcr->val == x) return true;
            pcr = pcr->suivant;
        }while (pcr->suivant!=NULL);
       
        return false;
    }
}

liste fusion (liste L1,liste L2){
    triBulleChaine(&L1);
    triBulleChaine(&L2);
    cell *p1 = NULL, *p2 = NULL, *q1 = NULL, *q2 = NULL,*tmp = NULL,*tmp2 = NULL;
    p1 = L1.premier;
    p2 = L2.premier; 
    q1 = p1->prec; 
    q2 = p2->prec;
    bool fusion ;
    liste L3; initList(&L3);
    L3 = L1;
    int t1 = 0,t2 = 0,j=0;
    while ( p1 != NULL ){
        t1++;
        p1 = p1->suivant;
    }
    while ( p2 != NULL ){
        t2++;
        p2 = p2->suivant;
    }
    if ( L1.premier->val > L2.premier->val ){
        L1 = L2;
        L2 = L3;
        L3 = L1;
    }
    p1 = L1.premier;
    p2 = L2.premier; 
    q1 = p1->prec; 
    q2 = p2->prec;
    while ( p1 != NULL) {
        while ( p2 != NULL) {
            
            fusion = false;
            // printf("jgdfv %d %d\n", p1->val,p2->val);
            if ( p1->val < p2->val) {
                fusion = true;
                tmp = p1->suivant;
                if ( p2->prec == NULL) {
                    p1->suivant = p2;
                    p2->prec = p1;
                } else {
                    q2->suivant = p1;
                    p2->prec = p1;
                    p1->suivant = p2;
                    p1->prec = q2;
                }
                p1 = tmp;
                L1.premier = tmp;
            }
            tmp2 = p2;
            // printf("[%d]",fusion);
            if ( !fusion) {
                if ( j == t2-1){
                    p2 = L2.premier;
                    q2= L2.premier->prec;
                } else {
                    q2 = p2;
                    p2 = p2->suivant;
                }
            } else {
                if (L1.premier == NULL) {
                    p2 = NULL;
                } else {
                    p2 = L2.premier;
                    q2= L2.premier->prec;
                }
            }
        }
        if ( fusion ) p1 = tmp;
        else p1 = p1->suivant;                                      
    }
    if (L1.premier != NULL) {
        cell *p3 =L3.premier;
        while ( p3->suivant != NULL) {
            p3 = p3->suivant;
        }
        p3->suivant = L1.premier;
        L1.premier->prec = p3;
    }
    supDoub(&L3);
    return L3;
}



int main(int argc, char const *argv[])
{
    liste L1,L2;
    initList(&L1);
    initList(&L2);

    ajoutTete(&L1,1);
    ajoutTete(&L1,2);
    ajoutTete(&L1,3);

    ajoutTete(&L2,4);
    ajoutTete(&L2,2);
    ajoutTete(&L2,6);
    ajoutTete(&L2,24);
    printf("\n");

    afficheList(&L1);

    printf("\n");

    afficheList(&L2);
    
    printf("\n");

    liste L3 = fusion(L1,L2);

    afficheList(&L3);
    inversList(&L3);
    afficheList(&L3);
    
    // ajoutElement(&L1,7);
    // afficheList(&L1);
    // if (recherche(3,&L1)) printf("%d trouve !", 3);

    // printf("\n");
    
    // ajoutQueue(10,&L1);
    // // triBulleChaine(&L1);
    // afficheList(&L1);
    
    // printf("\n");
    
    // supElement(&L1,0);
    // afficheList(&L1);

    // printf("\n");

    // afficheInv(&L1);
    // afficheList(&L1);

    // printf("\n");

    // afficheList(&L1);
    // ajoutQueue(2,&L1);
    // triBulleChaine(&L1);
    // afficheList(&L1);
    // supDoub(&L1);
    // afficheList(&L1);
    // free(L1);
    // free(&L2);
    // free(&L3);

    return 0;
}
