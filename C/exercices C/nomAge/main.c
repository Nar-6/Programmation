#include <stdio.h>
#include <stdlib.h>

int main(){
    int age;
    char nom[30];
    printf("Entrez votre nom et votre age :\n");
    scanf("%s",nom);
    scanf("%d",&age);
    if(age<18){
        printf("Bonjour je suis %s et je suis mineur car j'ai %d ans",nom,age);
    }else{
        printf("Bonjour je suis %s et je suis majeur car j'ai %d ans",nom,age);
    }
    return 0;
}
