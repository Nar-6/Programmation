  taille = sizeof (tab_film);
    for(i=0;i<2;i++){
        ret[i] = fread(&tab_film[i], taille, 1, flot);
           if (ret[i] == -1) {
       perror("Faute lecture : \n");
   }
