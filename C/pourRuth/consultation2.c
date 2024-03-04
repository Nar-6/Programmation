#include <stdio.h>
#include <string.h>

typedef struct film film;
struct film {
        char titre[101];
        char metteur_en_scene[101];
        int annee;
        int public;
        float prix;
    };
    film tab_film[2];

void main() {
    FILE *flot;
    int taille,nbr,ret[2],i,n;
  


    flot = fopen("filmotheque", "r");
    if (flot == NULL) {
        perror("Faute ouverture : \n");
  }

  taille = sizeof (tab_film);
    for(i=0;i<2;i++){
        ret[i] = fread(&tab_film[i], taille, 1, flot);
           if (ret[i] == -1) {
       perror("Faute lecture : \n");
   }
}
   i=0;
   do{
       printf("%d : Titre : %s\n",i+1,tab_film[i].titre);
       i++;
   }while(i<2);
    printf("Veuillez saisir le rang de votre film: ");
    scanf("%d",&n);
    printf("Titre : %s\n", tab_film[n-1].titre);
    printf("Metteur en scene : %s\n", tab_film[n-1].metteur_en_scene);
    printf("Annee : %d\n", tab_film[n-1].annee);
    if (tab_film[n-1].public == 1 )printf ("Tout public\n");
    else printf ("Adulte\n");
    printf("Prix : %.2f\n", tab_film[n-1].prix);



   fclose(flot);

  }
