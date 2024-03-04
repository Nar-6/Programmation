#include <stdio.h>
#include <string.h>

struct film {
    char titre[101];
    char metteur_en_scene[101];
    int annee;
    int public;
    float prix;

};
    struct film film1;
    struct film tab_film[10] ;

int main(){

    FILE *flot;
    int taille;
    int ret;
    char mot_clef[101];
    int resultat;
    int rang;
    int n =0 ;
    int i =0;
    int p;
    int q = 0;


    flot = fopen ("filmotheque", "r");
    if (flot == NULL) {
        perror("Faute ouverture : \n");
        return 0 ;
    }
    taille = sizeof (film1);



    while (1){


    ret = fread(&film1, taille , 1, flot);
        if (ret == -1) {
            perror("Faute ecriture : \n");
            return 0;
           }

            else if (ret!=0)  {
                tab_film[n]=film1;
                }

            else break;

             n++;
           }

            printf("Veuillez saisir un mot ou une partie du titre : ");
            scanf("%s",&mot_clef);

            for(i=0;i<10;i++){
                if (strstr(tab_film[i].titre,mot_clef) != NULL){
                    q++;
                    p = i;
                }
            }

     switch (q) {
     case 0:
        printf("Aucun film ne correspond");
        break;

     case 1:
      printf("Titre : %s\n",tab_film[p].titre);
      printf("Metteur en scene : %s\n",tab_film[p].metteur_en_scene);
      printf("Annee : %d\n",tab_film[p].annee);
        if  (tab_film[p].public ==0) {
            printf("Reserve aux adultes\n");
        }
 	    else if (tab_film[p].public ==1) {
            printf("Tout public\n");
        }
      printf("Prix: %.2f\n",tab_film[p].prix);
     break;


     default:
     for(i=0;i<10;i++){
                if (strstr(tab_film[i].titre,mot_clef) != NULL){
                    printf("%d : Titre : %s\n",i, tab_film[i].titre);


                    rang = i;
                }
            }

            printf("Veuillez saisir le rang de votre film : ");
            scanf("%d",&rang);
            printf("Titre : %s\n",tab_film[rang].titre);
            printf("Metteur en scene : %s\n",tab_film[rang].metteur_en_scene);
            printf("Annee : %d\n",tab_film[rang].annee);
            if  (tab_film[rang].public ==0) {
            printf("Reserve aux adultes\n");
            }
 	        else if (tab_film[rang].public ==1) {
            printf("Tout public\n");
            }
            printf("Prix: %.2f\n",tab_film[rang].prix);

            break;
     }


        fclose(flot);


}












