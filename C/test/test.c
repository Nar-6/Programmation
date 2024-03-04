#include <stdio.h>
#include <stdlib.h>

int main(){
    int r,n,i,tab[10];
    for(i=0;i<10;i++){
        tab[i]=0;
    }
    printf("Entrez un nombre\n");
    scanf("%d",&n);
    do{
        r=n%10;
        n=n/10;
        tab[r]=1;
    }while(n!=0);
    for(i=0;i<10;i++){
        if(tab[i]==1){
            printf("[%d]",i);
        }
    }
    return 0;

}
