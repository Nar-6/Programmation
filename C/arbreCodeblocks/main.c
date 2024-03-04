#include <stdio.h>
#include <stdlib.h>

// typedef struct nœud nœud ;
// struct noeud {
//  le_type_de_val val;
//  int g, d;
// };
// typedef nœud ArbreT [N];
// ArbreT A;
typedef struct noeud noeud ;
struct noeud {
    int val;
    noeud *fils_g;
    noeud *fils_d;
};
noeud Racine ;

void initTree(noeud *a){
    a->fils_d=NULL;
    a->fils_g=NULL;
}

void ajoutNoeud(noeud *a){
    noeud *b,*c;
    int d,g;
    char i;
    b=a;
    c=a;
    if(a->fils_g==NULL && a->fils_d==NULL){
        printf("cet arbre  est vide ! Voulez vous ajouter un noeud ?(O/N) :");
        scanf("%c",&i);
        if(i=='O'|| i=='o'){
            if(a->fils_d==NULL){
                b=a->fils_d;
                printf("Saisssez votre nombre droit:");
                scanf("%d",&d);
                b->val=d;
            }else{
                ajoutNoeud(b->fils_d);
            }
            if(a->fils_g==NULL){
                c=a->fils_g;
                printf("Saisssez votre nombre gauche:");
                fflush(stdin);
                scanf("%d",&g);
                c->val=g;
            }else{
                ajoutNoeud(c->fils_g);
            }
        }
        if(i=='N' || i=='n'){
            printf("OK !");

        }
    }
}

void afficheArbre(noeud *a){
    if(a->fils_g!=NULL){
        afficheArbre(a->fils_g);
    }else{
        printf("%d", a->val);
    }
    if(a->fils_d!=NULL){
        afficheArbre(a->fils_d);
    }else{
        printf("%d", a->val);
    }

}

int main(){
    FILE *f;
    int nbr,taille;
    f = fopen("arbrebinaire.txt","w");
    if (f==NULL) {
        perror("Faute ouverture : \n");
    }
    taille = sizeof (Racine);
    initTree(&Racine);
    Racine.val=5;
    ajoutNoeud(&Racine);
    fprintf(f,"la racine est %d",Racine.val);
    // do{
    //     nbr = fwrite(&Racine, taille, 1, f);


    // }while()

    // if(nbr != 1) {
    //     perror("Faute ecriture :\n");

        fclose(f);
    // }
    return 0;
}
