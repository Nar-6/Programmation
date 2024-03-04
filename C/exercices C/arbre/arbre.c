#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct arbre arbre;
struct arbre{
    char nom[100];
    arbre *fils;
    arbre *frere;
    arbre *parent;
};

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

int main(){
    arbre tree;
    printf("Entrez le nom ");
    creerTree(&tree);
    afficherArbre(&tree);
    return 0;
}