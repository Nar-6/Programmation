#include <stdio.h>
#include <stdlib.h>

typedef struct noeud arbre ;
struct noeud {
    int val;
    arbre *fils;
    arbre *frere;
    arbre *parent;
};


arbre *creerTree(int x){
    arbre *tr=malloc(sizeof(arbre));
    if(tr==NULL){
        printf("Erreur allocation memoire !\n");
        exit(EXIT_FAILURE);
    }
    tr->val=x;
    tr->fils=NULL;
    tr->frere=NULL;
    tr->parent=NULL;

        printf("creation de %d\n", tr->val);
    return tr;
}

void supTree(arbre *tr){
    if(tr==NULL){
        return;
    }

    printf("%d a ete sup \n",tr->val);

    supTree(tr->fils);
    supTree(tr->frere);

    free(tr);

}

arbre *joinTree(arbre *right, arbre *left, int node){
    arbre *tr=creerTree(node);

    tr->fils=right;
    tr->frere=left;

    if(right!=NULL){
        right->parent=tr;
    }
    if(left!=NULL){
        left->parent=tr;
    }

    return tr;
}

void afficherArbrePre(arbre *tr){
     if(tr==NULL) return;

     if(tr->parent!=NULL){
         printf("(%d) -> (%d)\n",tr->parent->val,tr->val);
     }else{
         printf("(%d)\n",tr->val);
     }

     if(tr->fils!=NULL){
         afficherArbrePre(tr->fils);
     }
     if(tr->frere!=NULL){
         afficherArbrePre(tr->frere);
     }
}

void afficherArbrePrecis(arbre *tr,int x){
     if(tr==NULL) return;

    if(tr->val==x){
        printf("(%d) -> (%d)\n",tr->val,tr->fils->val);
        printf("(%d) -> (%d)\n\n",tr->val,tr->frere->val);
    }

    afficherArbrePrecis(tr->fils,x);
    afficherArbrePrecis(tr->frere,x);

}

void afficherArbreFils(arbre *tr,int x){
    arbre *tmp;
    tmp=tr->fils;
     if(tr==NULL) return;

    if(tr->val==x){
        printf("les fils de (%d) sont:",tr->val);
        printf("->(%d)",tr->fils->val);
        do{
            printf("->(%d)",tmp->frere->val);
            tmp=tmp->frere;
        }while(tmp!=NULL);
        printf("\n\n");
    }
    afficherArbreFils(tr->fils,x);
    afficherArbreFils(tr->frere,x);

}

void afficherArbreFrereHaut(arbre *tr){
    arbre *tmp2=tr;
    if(tmp2==tmp2->parent->frere){
        do{
            printf("->(%d)",tmp2->parent->val);
            tmp2=tmp2->parent;
        }while(tmp2->parent->frere==tmp2);
    }
}
void afficherArbreFrereBas(arbre *tr){
    arbre *tmp=tr;
    do{
        printf("->(%d)",tmp->frere->val);
        tmp=tmp->frere;
    }while(tmp!=NULL);
}
void afficherArbreFrere(arbre *tr,int x){
     if(tr==NULL) return;

    if(tr->val==x){
        printf("les freres de (%d) sont:",tr->val);
        afficherArbreFrereBas(tr);
        afficherArbreFrereHaut(tr);
        printf("\n\n");
    }
    afficherArbreFrere(tr->fils,x);
    afficherArbreFrere(tr->frere,x);

}

int compterNoeud(arbre *tr){
    if (tr==NULL){
        return 0;
    }

    return (compterNoeud(tr->frere)+compterNoeud(tr->fils)+1);
}

arbre *creerTreeAvance(int x){
    arbre *tr=creerTree(x),*tr2,*tmp,*garde;
    tr2=tr;
    garde=tr;
    char choix1,choix2;
    int i,j,k;
    printf("%d A t il des fils?(O/N) \n",x);
        fflush(stdin);
    scanf("%c",&choix1);
    if(choix1=='o'|| choix1=='O'){
        printf("quel est sa valeur ? \n");
        fflush(stdin);
        scanf("%d",&k);
         tmp=creerTreeAvance(k);
        tr->fils=tmp;
        tmp->parent=tr;
        tr=tr->fils;
    }else{
        printf("ok\n");
    }
    printf("%d A t il des frere?(O/N) \n",x);
            fflush(stdin);
    scanf("%c",&choix2);
    if(choix2=='o'|| choix2=='O'){
        printf("quel est sa valeur ? \n");
        fflush(stdin);
        scanf("%d",&j);
        tmp=creerTreeAvance(j);
        tr2->frere=tmp;
        tmp->parent=tr2;
        tr2=tr2->frere;
    }else{
        printf("ok\n");
    }

    return garde;
}

int main(){
    arbre tree, element1, element2;
    int x,y;
    char choix;
    // tree=*joinTree(joinTree(creerTree(3),creerTree(2),5),creerTree(9),10);
    tree=*creerTreeAvance(10);
    afficherArbrePre(&tree);
    // printf("le nombre de noeud est %d\n",compterNoeud(&tree));
    // printf("Donnez la valeur parente: ");
    // scanf("%d",&x);
    // afficherArbrePrecis(&tree,x);
    printf("vous voulez voir la famille de quelle valeu5r ?");
    scanf("%d",&y);
    afficherArbreFils(&tree,y);
    afficherArbreFrere(&tree,y);
    supTree(&tree);
    return 0;
}