using System;

namespace Personne
{
    public class Personne
    {
        public string nom { get; set; }
        public string prenom { get; set; }
        public DateTime dateNaiss { get; set; }

        public Personne(string nom, string prenom, DateTime dateNaiss)
        {
            this.nom = nom;
            this.prenom = prenom;
            this.dateNaiss = dateNaiss;
        }

        public int age()
        {
            // Calculer la différence entre la date d'aujourd'hui et la date de naissance
            TimeSpan ageTimeSpan = DateTime.Now - dateNaiss;

            // Convertir la différence en jours
            int ageEnJours = ageTimeSpan.Days;

            // Diviser le nombre de jours par 365.25 pour obtenir l'âge en années
            int ageEnAnnees = (int)Math.Floor(ageEnJours / 365.25);

            // Retourner l'âge en années
            return ageEnAnnees;
        }

        public virtual void afficher()
        {
            Console.Write("Nom : " + this.nom + ", Prenom : " + this.prenom + ", Age : " + this.age());
        }
    }
}
