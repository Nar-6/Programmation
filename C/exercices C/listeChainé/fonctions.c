#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fonctions.h"

void initList (List_Etudiant *pl)
{
    pl->premier = NULL;
}

void ajoutEtu (List_Etudiant *pL, NEtudiant NE)
{
    //L'ajout se fera en tête
    NEtudiant *nouv;
    nouv = malloc (sizeof(NEtudiant));
    strcpy (nouv->nom, NE.nom);
    nouv->age = NE.age;
    nouv->sexe = NE.sexe;
    nouv->suivant = pL->premier;
    pL->premier = nouv;
}

void  affichList (List_Etudiant L)
{
    if (L.premier == NULL)
        printf("La liste est vide !");
    else
    {
        NEtudiant *pcr;
        pcr = L.premier;
        do
        {
            printf (" Nom : %s\n Age : %d\n Sexe : %c\n\n", pcr->nom, pcr->age, pcr->sexe);
            pcr = pcr->suivant;
            Sleep(2800);
        }while (pcr != NULL);
    }
}

NEtudiant renseignerEtu ()
{
    NEtudiant Etu;
    printf("\t\t\tEnregistrement d'un etudiant\n\tNom : ");
    scanf ("%s", &Etu.nom);
    printf("\tAge : " );
    scanf("%d", &Etu.age);
    printf("\tSexe : " );
    scanf("%s", &Etu.sexe);

    return Etu;
}

NEtudiant* rechercherEtu (List_Etudiant L, char nomEtuARechercher[])
{
        NEtudiant *point;
        point = L.premier;
        while(point != NULL)
        {
            if (strcmp(point->nom, nomEtuARechercher) == 0)
            {
                return point;
            }
            point = point->suivant;
        }
}

/*
    Ecris une fonction Supprimer qui prend en param une liste
    et un critère et qui

*/

void supprimer (List_Etudiant *L, char nomEtuASup[])
{
    NEtudiant *pt1, *pt2, etuSup;
    pt2 = L->premier;
    pt1 = pt2;
    while ((pt2->suivant != NULL) && (strcmp(pt2->nom, nomEtuASup))!=0)
    {
        pt1 = pt2;
        pt2 = pt2->suivant;
    }
    Sleep(2000);
    if (pt1 == pt2)
    {
        if (strcmp(pt2->nom, nomEtuASup)==0)
        {
            strcpy(etuSup.nom, pt2->nom);
            etuSup.age = pt2->age;
            etuSup.sexe = pt2->sexe;
            L->premier = pt2->suivant;
            free(pt2);
            printf("\n\nL'etudiant dont les coordonnees suivent a bien ete supprime de la base de donnees\n");
            Sleep(2000);
            printf (" Nom : %s\n Age : %d\n Sexe : %c\n\n", etuSup.nom, etuSup.age, etuSup.sexe);
            Sleep(2800);
        }
        else
        {
            printf("\n\nImpossible d'effectuer cette operation !\nL'etudiant %s n'existe pas dans la base de donnees", nomEtuASup);
            Sleep(2800);
        }
    }
    else
    {
        if (strcmp(pt2->nom, nomEtuASup)==0)
        {
            strcpy(etuSup.nom, pt2->nom);
            etuSup.age = pt2->age;
            etuSup.sexe = pt2->sexe;
            pt1->suivant = pt2->suivant;
            free(pt2);
            printf("\n\nL'etudiant dont les coordonnees suivent a bien ete supprime de la base de donnees\n");
            Sleep(2000);
            printf (" Nom : %s\n Age : %d\n Sexe : %c\n\n", etuSup.nom, etuSup.age, etuSup.sexe);
            Sleep(2800);
        }
        else
        {
            printf("\n\nImpossible d'effectuer cette operation !\nL'etudiant %s n'existe pas dans la base de donnees", nomEtuASup);
            Sleep(2800);
        }
    }
}
