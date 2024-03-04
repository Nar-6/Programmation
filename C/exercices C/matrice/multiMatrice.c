#include <stdio.h>

int main() {
    int rows1, cols1, rows2, cols2;

    // Demandez les dimensions des deux matrices à l'utilisateur
    printf("Entrez le nombre de lignes de la première matrice : ");
    scanf("%d", &rows1);
    printf("Entrez le nombre de colonnes de la première matrice : ");
    scanf("%d", &cols1);
    printf("Entrez le nombre de lignes de la deuxième matrice : ");
    scanf("%d", &rows2);
    printf("Entrez le nombre de colonnes de la deuxième matrice : ");
    scanf("%d", &cols2);

    // Vérifiez si les dimensions permettent la multiplication
    if (cols1 != rows2) {
        printf("Les dimensions des matrices ne permettent pas la multiplication.\n");
        return 1;
    }

    int matrice1[rows1][cols1], matrice2[rows2][cols2], produit[rows1][cols2];

    // Demandez les éléments de la première matrice à l'utilisateur
    printf("Entrez les éléments de la première matrice :\n");
    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < cols1; j++) {
            printf("Entrez l'élément [%d][%d]:\n",i,j);
            scanf("%d", &matrice1[i][j]);
        }
    }

    // Demandez les éléments de la deuxième matrice à l'utilisateur
    printf("Entrez les éléments de la deuxième matrice :\n");
    for (int i = 0; i < rows2; i++) {
        for (int j = 0; j < cols2; j++) {
            printf("Entrez l'élément [%d][%d]:\n",i,j); 
            scanf("%d", &matrice2[i][j]);
        }
    }

    // Effectuez la multiplication des matrices
    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < cols2; j++) {
            produit[i][j] = 0;
            for (int k = 0; k < cols1; k++) {
                produit[i][j] += matrice1[i][k] * matrice2[k][j];
            }
        }
    }

    // Affichez la matrice résultante
    printf("Le produit des deux matrices est :\n");
    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < cols2; j++) {
            printf("[%d] ", produit[i][j]);
        }
        printf("\n");
    }

    return 0;
}
