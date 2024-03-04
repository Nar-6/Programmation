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

void main() {
    FILE *flot;
    int taille;
    int nbr;
    int ret;


    flot = fopen("filmotheque", "r");
    if (flot == NULL) {
        perror("Faute ouverture : \n");
  }

  taille = sizeof (film1);

   ret = fread(&film1, taille, 1, flot);
   if (ret == -1) {
       perror("Faute lecture : \n");
   }
    printf("Titre : %s\n", film1.titre);
    printf("Metteur en scene : %s\n", film1.metteur_en_scene);
    printf("Annee : %d\n", film1.annee);
    if (film1.public == 1 )printf ("Tout public\n");
    else printf ("Adulte\n");
    printf("Prix : %f\n", film1.prix);



   fclose(flot);

  }
