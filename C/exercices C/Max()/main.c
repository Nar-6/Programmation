#include <stdio.h>
#include <stdlib.h>

int max(int a, int b){
    if(a<b){
       a=b;
    }
        return a;
}
int som(int *x,int y){
    *x+=y;
    return *x;
}
int main(){
    int a,b;
    printf("Entrez deux entiers: \n");
    scanf("%d%d",&a,&b);
    /*printf("Le maximum est %d.\n",max(a,b));
    printf("le premier est %d et le second est %d.\n",a,b);*/
    printf("La somme des deux entiers est %d\n",som(&a,b));
    printf("affichons a: %d",a);
    return 0;
}