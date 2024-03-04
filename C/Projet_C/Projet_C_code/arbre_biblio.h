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
typedef struct arbre arbre;
typedef struct membre membre;
struct membre{
    char prenom[30];
    int age;
    arbre *frere;
    arbre *fils;
    arbre *parent;
};

typedef struct arbre arbre;
struct arbre{
    membre *element;
};

void init_arbre(arbre *tree){
    tree->element = NULL;
}

void supprimer(arbre *tr){
    if(tr == NULL){
        printf("L\'arbre est vide !\n");
        return;
    }

    printf("%s a ete sup \n",tr->element->prenom);

    if(tr->element->fils != NULL){
        supprimer(tr->element->fils);
    }

    if(tr->element->frere != NULL){
        supprimer(tr->element->frere);
    }

    free(tr);

}

arbre *creerTree(char nomAMettre[],int ageAMettre){
    arbre *tr = malloc(sizeof(arbre));
    if(tr == NULL){
        printf("Erreur allocation memoire !\n");
        exit(EXIT_FAILURE);
    }
    tr->element = malloc(sizeof(membre));
    if(tr->element == NULL){
        printf("Erreur allocation memoire !\n");
        exit(EXIT_FAILURE);
    }
    strcpy(tr->element->prenom, nomAMettre);
    tr->element->age = ageAMettre;
    tr->element->fils = NULL;
    tr->element->frere = NULL;
    tr->element->parent = NULL;

    printf("creation de %s\n", tr->element->prenom);

    return tr;
}

arbre *creerTreeAvance(char nomAMettre[],int ageAMettre){
    arbre *tr=NULL,*tr1=NULL,*tr2=NULL,*tmp=NULL,*garde=NULL;

    tr=creerTree(nomAMettre,ageAMettre);
    tr1=tr;
    tr2=tr;
    garde=tr;

    int aje1,aje2;
    char choix1,choix2;
    char i[100],j[100],k[100];

    printf("%s A t il des fils?(O/N) \n",nomAMettre);
        fflush(stdin);
    scanf("%c",&choix1);
    if(choix1=='o'|| choix1=='O'){

        printf("quel est son nom ? \n");
        fflush(stdin);
        scanf("%s",k);
        do{

            printf("quel est son age ? \n");
            fflush(stdin);
            scanf("%d",&aje1);
            if (tr1->element->age-aje1 < 15){
                printf("Son enfant ne peut pas etre plus age que lui. \nRetapez le bon age.\n ");
            }
        }while (tr1->element->age-aje1 < 15);
        tmp=creerTreeAvance(k,aje1);
        tr1->element->fils=tmp;
        tmp->element->parent=tr1;

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
        printf("quel est son age ? \n");
        fflush(stdin);
        scanf("%d",&aje2);
        tmp=creerTreeAvance(j,aje2);
        tr2->element->frere=tmp;
        tmp->element->parent=tr2;

    }else{

        printf("ok\n");
        
    }

    return garde;
}

arbre *trouveParent(arbre *tr,char nomParent[]){
    if(tr==NULL) {
        printf("l\'arbre est vide");
        return NULL;
    }

    if(strcmp(tr->element->prenom,nomParent) == 0){
        return tr;
    }

    arbre *Parent = NULL;

    if(tr->element->fils != NULL){
        Parent = trouveParent(tr->element->fils,nomParent);
    }
    if(Parent == NULL && tr->element->frere != NULL){
        Parent = trouveParent(tr->element->frere,nomParent);
    }

    return Parent;
}

arbre *ajout_membre(arbre *tree,char nom[],int age_A,char nomParent[] ,char typeAffiliation[]){
    arbre *nouv=creerTree(nom,age_A);
    

    if(typeAffiliation != NULL  &&  nomParent != NULL){

        arbre *Parent = trouveParent(tree,nomParent);

        if(strcmp(typeAffiliation,"fr") == 0  ||  strcmp(typeAffiliation,"FR") == 0  ||strcmp(typeAffiliation,"fR") == 0  ||strcmp(typeAffiliation,"Fr") == 0 ){

            if (Parent->element->frere != NULL) {

                nouv->element->frere = Parent->element->frere;
                Parent->element->frere = nouv;
                nouv->element->parent = Parent;
                nouv->element->frere->element->parent = nouv;
            } else {

                Parent->element->frere = nouv;
                nouv->element->parent = Parent;
            }
        }
        if( strcmp(typeAffiliation,"f") == 0  ||strcmp(typeAffiliation,"F") == 0 ){
            if (Parent->element->age - nouv->element->age < 15){
                int aje;
                printf("Son enfant ne peut pas etre plus age que lui. \nRetapez le bon age.\n ");
                do{

                    printf("quel est son age ? \n");
                    fflush(stdin);
                    scanf("%d",&aje);
                
                }while (Parent->element->age - aje < 15);
                nouv->element->age = aje;
            }

            if (Parent->element->fils != NULL) {

                nouv->element->frere = Parent->element->fils;
                Parent->element->fils = nouv;
                nouv->element->parent = Parent;
                nouv->element->frere->element->parent = nouv;
            } else {

            Parent->element->fils = nouv;
            nouv->element->parent = Parent;
            }

        }

        return NULL;

    } else{

        return nouv ;
   }

    return NULL;
}

void frere(arbre *tr,char nomFrere[]){

    if(tr==NULL){ 
        printf("votre arbre est vide !");
        return;
    }

    if(strcmp(tr->element->prenom,nomFrere)==0){

        if ( tr->element->parent != NULL && (tr == tr->element->parent->element->frere || tr->element->frere != NULL)){

            printf("les freres de %s sont:\n",tr->element->prenom);

            arbre *indexe = tr;

            while( indexe->element->parent != NULL && indexe == indexe->element->parent->element->frere ){
            fflush(stdin);
                printf("%s\n",indexe->element->parent->element->prenom);
                indexe=indexe->element->parent;
            }

            indexe = tr->element->frere;

            while(indexe != NULL){
                            fflush(stdin);
                printf("%s\n",indexe->element->prenom);
                indexe=indexe->element->frere;
            }

        } else if (tr->element->parent == NULL) {
            arbre *indexe = tr->element->frere;

            if (indexe != NULL) {
            printf("les freres de %s sont:\n",tr->element->prenom);
                while(indexe != NULL){
                                fflush(stdin);
                    printf("%s\n",indexe->element->prenom);
                    indexe=indexe->element->frere;
                }
            }else {
                fflush(stdin);
                printf("%s est fils unique \n", nomFrere);
                
                return;
            }
        } else{
            fflush(stdin);
            printf("%s est fils unique \n", nomFrere);
            
            return;
        }

        printf("\n\n");

    }

    if (tr->element->fils != NULL) {
        frere(tr->element->fils,nomFrere);
    }

    if (tr->element->frere != NULL) {
        frere(tr->element->frere,nomFrere);
    }
}

void enfant(arbre *tr, char nomPere[]) {
    if (tr == NULL) {
        printf("Votre arbre est vide !");
        return;
    }

    if (strcmp(tr->element->prenom, nomPere) == 0) {

        if (tr->element->fils != NULL){

            printf("Les fils de %s sont:\n", tr->element->prenom);

            arbre *filsCourant = tr->element->fils;

            while (filsCourant != NULL) {
                printf(".......%s\n", filsCourant->element->prenom);
                filsCourant = filsCourant->element->frere;
            }
        } else {
            fflush(stdin);
            printf("%s n\'a pas d\'enfant \n", nomPere);
            
            return;
        }

        printf("\n\n");
    }

    if (tr->element->fils != NULL) {
        enfant(tr->element->fils, nomPere);
    }

    if (tr->element->frere != NULL) {
        enfant(tr->element->frere, nomPere);
    }
}

void parent(arbre *tr,char nom[]){

     if(tr==NULL) return;

    if(strcmp(tr->element->prenom,nom)==0){
        if(tr->element->parent != NULL)
        printf("Le parent direct de %s est: %s\n",tr->element->prenom,tr->element->parent->element->prenom);
    }
     if(tr->element->fils!=NULL){
        parent(tr->element->fils,nom);
     }
     if(tr->element->frere!=NULL){
        parent(tr->element->frere,nom);
     }
}

void parent_avance(arbre *tr, char nom[]) {
    if (tr == NULL) {
        return;
    }

    if (strcmp(tr->element->prenom, nom) == 0) {
        arbre *indexe = tr;

        while (indexe->element->parent != NULL && indexe != indexe->element->parent->element->fils) {
            indexe = indexe->element->parent;
        }

        if (indexe->element->parent != NULL) {
            printf("Le parent direct de %s est: %s\n", tr->element->prenom, indexe->element->parent->element->prenom);
        
        } else {
            printf("Le parent direct de %s n'a pas pu etre trouve car il fait partie de la fratrie racine (logique) .\n", tr->element->prenom);
            
        }
    }

    if (tr->element->fils != NULL) {
        parent_avance(tr->element->fils, nom);
    }

    if (tr->element->frere != NULL) {
        parent_avance(tr->element->frere, nom);
    }
}

int est_membre(arbre *tr,char nom[]){
     if(tr==NULL){
         return 0;
     }

    if(strcmp(tr->element->prenom,nom) == 0){
        return 1;
    }

     if(tr->element->fils != NULL && est_membre(tr->element->fils,nom)){
        return 1;
     }

     if( est_membre(tr->element->frere,nom) && tr->element->frere != NULL ){
        return 1;
     }
    return 0;
}

int compter(arbre *tr){
    if (tr==NULL){
        return 0;
    }

    int i=0;
    arbre *indexe = tr;
    while (indexe->element->parent != NULL){
        if (indexe == indexe->element->parent->element->fils){
            i=i+1;
        }
        indexe = indexe->element->parent;
    }

    return i;
}

void affiche_arbre(arbre *tr){

    if(tr==NULL) {
        printf("l\'arbre est vide");
        return;
    }
    int i;
    for ( i=0 ; i < compter(tr) ; i++ ){
        printf(".......");
    }
    printf("%s, %d\n",tr->element->prenom,tr->element->age);

    if(tr->element->fils!=NULL){
    affiche_arbre(tr->element->fils);
    }
    if(tr->element->frere!=NULL){
    affiche_arbre(tr->element->frere);
    }
}

void triDecroissant(int tab[], int taille) {
    int i, j, temp;
    for (i = 0; i < taille-1; i++) {
        for (j = 0; j < taille-i-1; j++) {
            if (tab[j] < tab[j+1]) {
                temp = tab[j];
                tab[j] = tab[j+1];
                tab[j+1] = temp;
            }
        }
    }
}

void bonus(arbre *tr,char nom[]){
    int i=1;

    if (strcmp(tr->element->prenom, nom) == 0) {

        if (tr->element->fils != NULL){

            arbre *filsCourant = tr->element->fils;

            while (filsCourant != NULL) {
                i=i+1;
                filsCourant = filsCourant->element->frere;
            }

        }
    }

    if (i > 1) {
        int ages[i-1],j;
        arbre *filsCourant = tr->element->fils; 

        for (j = 0; j < i-1; j++) {

            ages[j] = filsCourant->element->age;
            filsCourant = filsCourant->element->frere;
        }

        triDecroissant(ages,i-1);
        filsCourant = tr->element->fils;

        while (filsCourant != NULL) {
            for (j = 0; j < i-1; j++) {

                if (ages[j] == filsCourant->element->age ) {
                    affiche_arbre(filsCourant);
                }
            }
            filsCourant = filsCourant->element->frere;
        }

    }
    

    
}