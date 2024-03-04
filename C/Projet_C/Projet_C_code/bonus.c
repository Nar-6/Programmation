#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NOM 50

typedef struct Membre {
    char prenom[MAX_NOM];
    int age;
    struct Arbre *frere;
    struct Arbre *fils;
    struct Arbre *parent;
} Membre;

typedef struct Arbre {
    Membre *element;
} Arbre;

int parcourirArbre(Arbre *racine, Membre **tableau, int taille) {
    if (racine == NULL) {
        return taille;
    }
    tableau[taille] = racine->element;
    taille++;
    Arbre *frere = racine->element->frere;
    while (frere != NULL) {
        taille = parcourirArbre(frere, tableau, taille);
        frere = frere->element->frere;
    }
    taille = parcourirArbre(racine->element->fils, tableau, taille);
    return taille;
}

int comparerMembres(const void *p1, const void *p2) {
    Membre *m1 = *(Membre **) p1;
    Membre *m2 = *(Membre **) p2;
    return m1->age - m2->age;
}

void trierMembres(Membre **tableau, int taille) {
    qsort(tableau, taille, sizeof(Membre *), comparerMembres);
}

void afficherMembres(Membre **tableau, int taille) {
    for (int i = 0; i < taille; i++) {
        printf("%s (%d ans)\n", tableau[i]->prenom, tableau[i]->age);
    }
}

int main() {
    // Exemple d'arbre généalogique
    Membre a = {"A", 50, NULL, NULL, NULL};
    Membre b = {"B", 30, NULL, NULL, NULL};
    Membre c = {"C", 40, NULL, NULL, NULL};
    Membre d = {"D", 20, NULL, NULL, NULL};
    Membre e = {"E", 25, NULL, NULL, NULL};
    Membre f = {"F", 35, NULL, NULL, NULL};
    Membre g = {"G", 45, NULL, NULL, NULL};

    Arbre arbre_a = {&a};
    Arbre arbre_b = {&b};
    Arbre arbre_c = {&c};
    Arbre arbre_d = {&d};
    Arbre arbre_e = {&e};
    Arbre arbre_f = {&f};
    Arbre arbre_g = {&g};

    arbre_a.element->fils = &arbre_b;
    arbre_b.element->frere = &arbre_c;
    arbre_c.element->fils = &arbre_d;
    arbre_d.element->frere = &arbre_e;
    arbre_e.element->frere = &arbre_f;
    arbre_f.element->frere = &arbre_g;

    // Parcours de l'arbre et tri des membres
    Membre *tableau[MAX_NOM];
    int taille = parcourirArbre(&arbre_a, tableau, 0);
    trierMembres(tableau, taille);

    // Affichage des membres triés par âge
    printf("Membres triés par âge :\n");
    afficherMembres(tableau, taille);

    return 0;
}
