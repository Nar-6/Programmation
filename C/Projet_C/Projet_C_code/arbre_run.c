#include "arbre_biblio.h"


int main(){

    int i,age,j;
    char ok[4],nomAmettre[100],nomFrere[100],nomPere[100],nomParent[100],type_affil[10];
    arbre  *tree = NULL;
    clrscr();
    do{
        rectangle(50,3,30,2);
        gotoxy(63,4);
        printf("MENU");

        rectangle(50,7,30,10);
        gotoxy(51,8);
        printf("1-Creer un arbre");
        gotoxy(51,9);
        printf("2-Ajouter un noeud");
        gotoxy(51,10);
        printf("3-Afficher l'arbre");
        gotoxy(51,11);
        printf("4-Rechercher un noeud");
        gotoxy(51,12);
        printf("5-Afficher les freres");
        gotoxy(51,13);
        printf("6-Afficher les fils");
        gotoxy(51,14);
        printf("7-Afficher le parent direct");
        gotoxy(51,15);
        printf("8-Quitter");

        rectangle(50,20,30,2);
        gotoxy(51,21);
        printf("Votre choix: ");
        fflush(stdin);
        scanf("%d",&i);
        switch(i){
            case 1:clrscr();
                printf("Creer le premier element de l'arbre \nDonnez son prenom ");
                scanf("%s",nomAmettre);
                printf("Quel est son age ? ");
                scanf("%d",&age);
                tree = creerTreeAvance(nomAmettre,age);
                break ;
            case 2:clrscr();
            if(tree == NULL){
                
                printf("Entrez les infos du premier element de l\'arbre (prenom, age) \n");
                printf("Prenom : ");
                        fflush(stdin);
                scanf("%s",nomAmettre); 
                printf("Age : ");
                        fflush(stdin);
                scanf("%d",&age);
                tree = ajout_membre(tree,nomAmettre,age,NULL,NULL);
                printf("%s a ete ajoute",nomAmettre);

            }else{

                printf("Entrez les infos de l\'element a ajouter (prenom, age, le prenom de son parent\n l\'affiliation avec ce dernier (frere=fr fils=f))\n");
                
                printf("Prenom : "); 
                        fflush(stdin);
                scanf("%s",nomAmettre); 

                printf("Prenom du parent : ");
                    fflush(stdin);
                scanf("%s",nomParent);

                printf("Affiliation : ");
                    fflush(stdin);
                scanf("%s", type_affil);
                
                printf("Age : ");
                        fflush(stdin);
                scanf("%d",&age);

                ajout_membre(tree,nomAmettre,age,nomParent,type_affil);
                
                 printf("%s a ete ajoute",nomAmettre);
            }
                    break ;
            case 3:clrscr();
                affiche_arbre(tree);
                printf("tapez OK pour continuer \n");
                scanf("%s",ok);
                break ;
            case 4:clrscr();
                printf("Quel membre recherchez-vous ? ");
                scanf("%s",nomAmettre);
                if(!est_membre(tree,nomAmettre)){
                    printf("%s n\'existe pas !",nomAmettre);
                }else{
                    printf("%s existe !", nomAmettre);
                }
                    break ;
            case 5:clrscr();
                printf("Vous voulez voir les freres de qui ? \nDonnez son prenom: ");
                scanf("%s",nomFrere);
                if(!est_membre(tree,nomFrere)){
                    printf("%s n\'existe pas !",nomFrere);
                }else{
                    frere(tree,nomFrere);
                    printf("tapez OK pour continuer \n");
                    scanf("%s",ok);
                }

                break ;
            case 6:clrscr();
                printf("Vous voulez voir les enfents de qui ? \nDonnez son prenom: ");
                scanf("%s",nomPere);
                if(!est_membre(tree,nomPere)){
                    printf("%s n\'existe pas !",nomPere);
                }else{
                    enfant(tree,nomPere);
                    printf("tapez OK pour continuer \n");
                    scanf("%s",ok); 
                }

                    break ;
            case 7:clrscr();
                printf("Vous voulez voir le parent direct de qui ? \nDonnez son prenom: ");
                scanf("%s",nomParent);
                if(!est_membre(tree,nomParent)){
                    printf("%s n\'existe pas !",nomParent);
                }else{
                    parent_avance(tree, nomParent);
                    printf("tapez OK pour continuer \n");
                    scanf("%s",ok); 
                }

                    break;
            case 8:clrscr();
                supprimer(tree);
                printf("Vous avez quitte le programme !");
                    break;

        }
        printf("\n\n");
    }while(i!=8);
    return 0;
}