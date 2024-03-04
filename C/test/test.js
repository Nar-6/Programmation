

    let i,n,r;
    let nbr;
    printf("Entrez un nombre: ");
    scanf("%d",n);
    for(i=0;i<10;i++){
        nbr[i]=0;
    }
    do{
        r=n%10;
        n=n/10;
        nbr[r]=1;
    }while(n!=0);
    for(i=0;i<10;i++){
        if(nbr[i]=1){
            printf("[%d]",i);
        }
    }