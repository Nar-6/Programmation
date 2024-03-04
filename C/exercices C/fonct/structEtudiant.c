#include <stdio.h>
#include <stdlib.h>

typedef struct Etudiant Etudiant;
struct Etudiant{
    char nom[30];
    unsigned int age;
    char sexe;
};

void Afficher(Etudiant etudiants[], int n){
    int i;
    for(i=0;i<n;i++){
        printf("Nom: %s, Age: %d, Sexe: %c\n",etudiants[i].nom,etudiants[i].age,etudiants[i].sexe);
    }
}
void Maxi(Etudiant etudiants[], int n){
    int i,t,max;
    max=etudiants[0].age;
    t=0;
    for(i=1;i<n;i++){
        if(etudiants[i].age>=max){
            t=i;
        }
    }
    printf("L\'etudiant le plus age est :%s",etudiants[t].nom);
}

int main(){
    int n,i;
    Etudiant etudiants[n];
    printf("Saisissez le nombre d'etudiants: ");
    scanf("%d",&n);
    printf("Entrez les informations:\n");
    for(i=0;i<n;i++){
        printf("le nom de l\'etudiant %d:",i+1);
        scanf("%s",&etudiants[i].nom);
        printf("l\'age de l\'etudiant %d:",i+1);
        scanf("%d",&etudiants[i].age);
        printf("le sexe de l\'etudiant %d:",i+1);
        fflush(stdin);
        scanf("%c",&etudiants[i].sexe);
    }
    Afficher(etudiants,n);
    Maxi(etudiants,n);
    return 0;
}

