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


    flot = fopen("filmotheque", "a");
    if (flot==NULL) {
        perror("Faute ouverture : \n");
    }
    taille = sizeof (film1);


    printf("Veuillez saisir le titre : ");
    scanf("%s", &film1.titre);
    printf ("Veuillez saisir le metteur en scene : ");
    scanf("%s", &film1.metteur_en_scene);
    printf ("Veuillez saisir l'annee de sortie: ");
    scanf("%d", &film1.annee);
    printf("Veuillez saisir 0:Adulte. 1:Tout public. : ");
    scanf("%d", &film1.public);
    printf ("Veuillez saisir le prix : ");
    scanf("%f", &film1.prix);

    nbr = fwrite(&film1, taille, 1, flot);

    if(nbr != 1) {
        perror("Faute ecriture :\n");

        fclose(flot);
    }
}


