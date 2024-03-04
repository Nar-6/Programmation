#include <stdio.h>
#include <stdlib.h>

int main() {
    int rows, cols;

    // Demandez les dimensions des matrices à l'utilisateur
    printf("Entrez le nombre de lignes : ");
    scanf("%d", &rows);
    printf("Entrez le nombre de colonnes : ");
    scanf("%d", &cols);

    int matrice1[rows][cols], matrice2[rows][cols], somme[rows][cols];

    // Demandez les éléments de la première matrice à l'utilisateur
    printf("Entrez les éléments de la première matrice :\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("Entrez l'élément [%d][%d]:\n",i,j);
            scanf("%d", &matrice1[i][j]);
        }
    }

    // Demandez les éléments de la deuxième matrice à l'utilisateur
    printf("Entrez les éléments de la deuxième matrice :\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("Entrez l'élément [%d][%d]:\n",i,j);
            scanf("%d", &matrice2[i][j]);
        }
    }

    // Additionnez les deux matrices et stockez le résultat dans la matrice "somme"
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            somme[i][j] = matrice1[i][j] + matrice2[i][j];
        }
    }

    // Affichez la matrice résultante
    printf("La somme des deux matrices est :\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("[%d] ", somme[i][j]);
        }
        printf("\n");
    }

    return 0;
}
