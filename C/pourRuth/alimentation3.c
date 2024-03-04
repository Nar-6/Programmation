#include <stdio.h>
#include <string.h>

struct film {
    char titre[101];
    char metteur_en_scene[101];
    int annee;
    int public;
    float prix;
};

 struct film film1 ;
 struct film tab_film[10] ;

int main() {
    FILE *flot;
    int taille;
    int nbr;
    int ret;
    int resultat;
    int i;


    flot = fopen ("filmotheque", "a");
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

            else if (ret!=0) {
                tab_film[i]=film1;
                }

            else break;

            i++;
        }

    printf("veuillez saisir le titre : ");
    scanf("%s", &film1.titre);

         for (i=0 ; i<10; i++){
            resultat=strcmp(film1.titre,tab_film[i].titre);
            if (resultat!=0){
                printf("Ce film existe deja");
            return 0;
            }

         }

    printf("veuillez saisir le metteur en scene : ");
    scanf("%s", &film1.metteur_en_scene);
    printf("veuillez saisir l'annee du film :");
    scanf("%d", &film1.annee);
    printf("Veuillez choisir le public 1:Tout public sinon 0:Adulte : ");
    scanf("%d", &film1.public);
    printf("veuillez saisir le prix :");
    scanf("%f", &film1.prix);


    nbr = fwrite(&film1, taille, 1, flot);
    if (nbr != 1) {
        perror("Faute ecriture : \n");
        return 0;
    }


    fclose(flot);

}



