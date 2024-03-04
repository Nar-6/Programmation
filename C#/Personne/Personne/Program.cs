using System;
using Personne;

class Program
{
    static void Main()
    {
        Personne.Personne p1 = new Personne.Personne("KOUNASSO", "Thibaut", new DateTime(2003, 7, 8));
        Personne.Employe e1 = new Personne.Employe("KOUNASSO", "Thibaut", new DateTime(2003, 7, 8));
        Personne.Directeur d1 = new Personne.Directeur("KOUNLE", "Salaupard", new DateTime(2002, 1, 8), "ESGIS", "caract");

        p1.afficher(); 
        e1.afficher(); 
        // double salaire1 = e1.calculeSalaire();
        double salaire2 = d1.calculeSalaire();

        Console.WriteLine("Le salaire de "+ d1.nom + d1.prenom + " est :" + salaire2);
                                               
    }
}
