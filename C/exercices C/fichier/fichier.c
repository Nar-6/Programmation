#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int rechercher(FILE *f,char motRech[20]){
    char chaine[20];
    int v=1;
    while(fgets(chaine,20,f) != NULL){
        chaine[strlen(chaine)-1]='\0';
        if(strcmp(motRech,chaine)==0){
            v=0;
        }
    }
    if(v!=0){
        return 1;
    }else{
        return 0;
    }
}

int main(){
    int i;
    char motRech[20];
    FILE *f;
    f = fopen("mesprenoms.txt","r");
    printf("Veillez taper le mot à rechercher: ");
    scanf("%s", &motRech);
    if(rechercher(f,motRech)==0){
        printf("TROUVE");
    }else{
        printf("INCONNUE");
    }
    fclose(f);
    return 0;
}
