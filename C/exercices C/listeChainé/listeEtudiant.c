#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct NEtudiant NEtudiant;
struct NEtudiant{
    char nom[30];
    unsigned int age;
    char sexe;
    NEtudiant *suivant;
};
typedef struct listeEtudiant listeEtudiant;
struct listeEtudiant{
    NEtudiant *premier;
};

//initialiser la liste à une liste vide
void initList(listeEtudiant *pL){
    pL->premier=NULL;//initialise la liste à une liste vide
}

//supprime l'element en tete de lsite
void supEntete(listeEtudiant *L){
    NEtudiant *ptr;
    if(L->premier==NULL){
        printf("La liste est vide!");
    }else{
        ptr=L->premier;
        L->premier=ptr->suivant;
        if(L->premier==NULL){
            printf("Il y avait un seul etudiant, il a ete supprime.\n");
        }else{
            printf("\tL\'etudiant en tete a ete supprime.\n");
        }
    }
}

// supprime l'element en queue de liste
void supEnqueue(listeEtudiant *L){
    NEtudiant *pre,*de;
    if(L->premier==NULL){
        printf("La liste est vide!");
    }else{
        pre=L->premier;
        de=L->premier;
        if(L->premier->suivant==NULL){
            L->premier=NULL;
            printf("Il y avait un seul etudiant, il a ete supprime.\n\n");
        }else{
            do{
                if(de->suivant!=NULL){
                    pre=de;
                }else{
                    pre->suivant=NULL;
                }
                de=de->suivant;
            }while(de!=NULL);
            printf("L\'etudiant en queue a ete supprime.\n\n");
        }
    }
}

//supprime n'importe quel element de la liste 
void supElement(listeEtudiant *L,NEtudiant E){
    listeEtudiant *N;
    NEtudiant *pre,*de,*troi,*aSup;
    troi=L->premier;pre=L->premier;de=L->premier;
    printf("Entrez le sexe de l\'etudiant a supprimer: ");
    fflush(stdin);
    scanf("%s",&E.nom);
    strcpy(aSup->nom, E.nom);
    initList(N);
    while((strcmp(aSup->nom,de->nom)!=0) || (de->suivant!=NULL)){
        pre=de;
        troi=de->suivant->suivant;
        de=de->suivant;
        printf("dzf");
    }
    if(de->suivant==NULL){
        supEnqueue(L);
    }
    if(pre==de){
        supEntete(L);
    }
    // if(L->premier=NULL){
    //     printf("La liste est vide !");
    // }else{
    //     do{
    //         if(strcmp(E.nom,de->nom)!=0){
    //             pre=de;
    //             troi=de->suivant->suivant;
    //         }else{
    //             de->suivant=NULL;
    //             N->premier=troi;
    //         }
    //         de=de->suivant;
    //     }while(de!=NULL);
    // }
    // supEnqueue(L);
    // pre->suivant=N->premier;
}

//affiche tous les elements dune listes d'etudiants
void afficheList(listeEtudiant *L){
    if(L->premier==NULL){
        printf("La liste est vide !");
    }else{
        NEtudiant *pcr;
        pcr=L->premier;
        do{
            printf("Nom: %s\n Age: %d\n Sexe: %c\n\n",pcr->nom,pcr->age,pcr->sexe);
            pcr=pcr->suivant;
        }while (pcr!=NULL);
        printf("Voici la liste des etudiants !\n");
    }
}
 
// void ajout(listeEtudiant *L, NEtudiant *E){
//         E->suivant=L->premier;
//         L->premier=nouv;}

//creer un element puis l'ajoute a la liste
void ajoutElement(listeEtudiant *pL, NEtudiant NE){
    //ajout en tete
    NEtudiant *nouv;
    int n,i;
    printf("Combien d'etudiants voulez vous creer ? ");
    scanf("%d",&n);
    for(i=0;i<n;i++){
        nouv=malloc(sizeof(NEtudiant));
        printf("Saisissez le nom de l'etudiant %d: ",n-i);
        scanf("%s",&NE.nom);
        strcpy(nouv->nom, NE.nom);
        printf("Saisissez l'age de l'etudiant %d: ",n-i);
        scanf("%d",&NE.age);
        nouv->age=NE.age;
        printf("Saisissez le sexe de l'etudiant %d: ",n-i);
        fflush(stdin);
        scanf("%c",&NE.sexe);
        nouv->sexe=NE.sexe;
        nouv->suivant=pL->premier;
        pL->premier=nouv;
        printf("\n\n");
    }
    printf("Les etudiants ont bien ete ajoute !\n\n");
}


int main(){
    listeEtudiant maList;
    NEtudiant E,A;
    initList(&maList);
    ajoutElement(&maList,E);
    afficheList(&maList);
    // supEntete(&maList);
    // supEnqueue(&maList);
    supElement(&maList,A);
    afficheList(&maList);
    return 0;
}