#include <stdio.h>
#include <stdlib.h>

void Afficher(float nbr[], int n){
    int i;
    for(i=0;i<n;i++){
        printf("%.1f\n",nbr[i]);
    }
}
float Maxi(float nbr[], int n){
    int i;
    float max;
    max=nbr[0];
    for(i=1;i<n;i++){
        if(nbr[i]>max){
            max=nbr[i];
        }
    }
    return max;
}

int main(){
    int n,i;
    float nbr[n];
    printf("Quelle est la taille de votre tableau?\n");
    scanf("%d",&n);
    printf("Entrez vos valeurs:\n");
    for(i=0;i<n;i++){
        printf("Celle de la %de cellule:",i+1);
        scanf("%f",&nbr[i]);
    }
    printf("Les valeurs de votre tableau sont:\n");
    Afficher(nbr,n);
    printf("Le max de votre tableau est : %.1f",Maxi(nbr,n));
    return 0;
}

// fflush(stdin); pour vider le tampon 