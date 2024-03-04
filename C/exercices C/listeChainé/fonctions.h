#ifndef FONCTIONS_H_INCLUDED
#define FONCTIONS_H_INCLUDED

typedef struct NEtudiant NEtudiant;
struct NEtudiant
{
    char nom[30];
    unsigned int age;
    char sexe;
    NEtudiant *suivant;
};

typedef struct List_Etudiant List_Etudiant;
struct List_Etudiant
{
    NEtudiant *premier;
};



void initList (List_Etudiant *pl);
void ajoutEtu (List_Etudiant *pL, NEtudiant NE);
void  affichList (List_Etudiant L);
NEtudiant renseignerEtu ();
NEtudiant* rechercherEtu (List_Etudiant L, char nomEtuARechercher[]);
void supprimer (List_Etudiant *L, char nomEtuASup[]);

#endif // FONCTIONS_H_INCLUDED
