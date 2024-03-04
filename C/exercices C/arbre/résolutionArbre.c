#include <stdio.h>
#include <stdlib.h>
 
struct element
{
    int val;
    struct element *d;
    struct element *g;
};
 
typedef struct element arbre;
 
void afficherArbre( int i, arbre *arbre );
arbre *AjouterNoeud( arbre *monarbre, int valeur );
 
int main (void)
{
    FILE *f;
    f = fopen("arbrebinaire.txt","w");
    arbre *mon_arbre=NULL;
    mon_arbre = AjouterNoeud( mon_arbre, 1 );
    mon_arbre = AjouterNoeud( mon_arbre, 2 );
    mon_arbre = AjouterNoeud( mon_arbre, 3 );
    mon_arbre = AjouterNoeud( mon_arbre, 8 );
    mon_arbre = AjouterNoeud( mon_arbre, 9 );
    afficherArbre( 0,mon_arbre );
    fwrite ( &mon_arbre, 1, sizeof(mon_arbre), f );
    fclose(f);
    return 0;
}
 
arbre *AjouterNoeud( arbre *mon_arbre, int valeur )
{
    if ( mon_arbre == NULL )
    {
        arbre *noeud = (arbre *)malloc(sizeof(arbre));
 
        noeud->val=valeur;
        noeud->g=NULL;
        noeud->d=NULL;
 
        return noeud;
    }
 
    else
    {
        if ( mon_arbre->val > valeur )
        {
            arbre *noeud = (arbre *)malloc(sizeof(arbre));
            arbre *arbre_temporaire = mon_arbre;
 
            noeud->val=valeur;
            noeud->g=NULL;
            noeud->d=NULL;
 
            arbre_temporaire->d = noeud;
 
            return mon_arbre;
        }
 
        else
        {
            arbre *noeud = (arbre *)malloc(sizeof(arbre));
            arbre *arbre_temporaire = mon_arbre;
 
            noeud->val=valeur;
            noeud->g=NULL;
            noeud->d=NULL;
 
            arbre_temporaire->g = noeud;
 
            return mon_arbre;
        }
    }
}
 
void afficherArbre( int i, arbre *arbre )
{
    if ( arbre != NULL )
    {
        printf("\n hauteur %d : %d", i, arbre->val);
        i++;
 
        if ( arbre->g != NULL || arbre->d != NULL )
        {
            afficherArbre( i, arbre->g);
            afficherArbre( i, arbre->d);
        }
    }
 
    else printf("\n arbre vide");
}