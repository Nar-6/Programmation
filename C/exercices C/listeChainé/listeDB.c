#include "liste.h"

int main(){
    liste l1,l2,l3;
    initList(&l1);
    initList(&l2);
    initList(&l3);

    int i,n;
    clrscr();
    do{
        rectangle(50,3,35,2);
        gotoxy(66,4);
        printf("MENU");

        rectangle(50,7,35,12);
        gotoxy(51,8);
        printf("1-Creer une liste");
        gotoxy(51,9);
        printf("2-Ajouter un element");
        gotoxy(51,10);
        printf("3-Ajouter un element en queue");
        gotoxy(51,11);
        printf("4-Trier la liste");
        gotoxy(51,12);
        printf("5-Supprimer un element");
        gotoxy(51,13);
        printf("6-Supprimer les doublons");
        gotoxy(51,14);
        printf("7-Supprimer le dernier element");
        gotoxy(51,15);
        printf("8-Fusionner deux listes");
        gotoxy(51,16);
        printf("9-Inverser la liste");
        gotoxy(51,17);
        printf("10-Verifier si palindrome");
        gotoxy(51,18);
        printf("11-Quitter");
        
        rectangle(50,21,35,2);
        gotoxy(51,22);
        printf("Votre choix: ");
        fflush(stdin);
        scanf("%d",&i);
        switch(i){
            case 1:clrscr();
                if ( l1.premier == NULL) {
                printf("Votre liste contient combien d'elements ? :");
                scanf("%d",&n);
                ajoutElementAvance(&l1,n);
                afficheList(&l1);
                } else {
                printf("Vous avez deja une liste courante \n");
                }
                break ;

            case 2:clrscr();
                printf("Entrez la valeur à ajouter :");
                scanf("%d",&n);
                ajoutTete(&l1,n);
                afficheList(&l1);
                break ;

            case 3:clrscr();
                printf("Entrez la valeur à ajouter :");
                scanf("%d",&n);
                ajoutQueue(n,&l1);
                afficheList(&l1);
                break;

            case 4:clrscr();
                triBulleChaine(&l1);
                afficheList(&l1);
                break;

            case 5:clrscr();
                printf("Quel element voulez vous supprimer ? : ");
                scanf("%d",&n);
                supElement(&l1,n);
                afficheList(&l1);
                break ;

            case 6:clrscr();
                supDoub(&l1);
                afficheList(&l1);
                break ;

            case 7:clrscr();
                supQueue(&l1);
                afficheList(&l1);
                break;

            case 8:clrscr();
                char response;
                printf("Creez la liste a fusionne a la liste courante\n\n");
                printf("la liste contient combien d'elements ? :");
                scanf("%d",&n);
                ajoutElementAvance(&l2,n);
                afficheList(&l2);
                l3 = fusion(l1,l2);
                afficheList(&l3);
                printf("\nVoulez vous que le resultat de la fusion devienne votre liste courante ? (o/n) ");
                do{
                    scanf("%c",&response);
                    if (response == 'o' || response == 'O') {
                        l1 = l3;
                        printf("Fusion enregistree !\n");
                    } else if(response == 'n' || response == 'N') {
                        printf("d'accord\n");
                    } else {
                        printf("Choisissez entre oui ou non (o/n)\n");
                    }
                } while (response != 'o' && response != 'O' && response != 'n' && response != 'N');
                break;

            case 9:clrscr();
                inversList(&l1);
                afficheList(&l1);
                break;

            case 10:clrscr();
                int verif = palyndrome(&l1);
                if ( verif == 0 ) printf ("Votre listes n'est pas un palindrome !\n");
                else if (verif == 1) printf("Votre listes est un palindrome !\n");
                break;

            case 11:clrscr();
                supprimer(&l1);
                printf("Vous avez quitte le programme !");
                break;

            default :clrscr();
                printf("Choisissez un nombre entre entre 1 et 11");
                break;
        }
        printf("\n\n");
    }while(i!=11);
    return 0;
}