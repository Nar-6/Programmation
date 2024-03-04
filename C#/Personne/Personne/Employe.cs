using System;

namespace Personne
{
    public class Employe : Personne
    {
        public double sursalaire { get; set; }
        public double salairedebase { get; set; }
        public double bonus { get; set; 
         }

        public virtual double calculeSalaire()
        {
            // Demander à l'utilisateur de saisir les informations nécessaires
            Console.WriteLine("Entrez le salaire de base : ");
            this.salairedebase = Convert.ToDouble(Console.ReadLine());

            Console.WriteLine("Entrez le montant du bonus : ");
            this.bonus = Convert.ToDouble(Console.ReadLine());

            Console.WriteLine("Entrez le montant sur salaire : ");
            this.sursalaire = Convert.ToDouble(Console.ReadLine());

            // Calculer le CNSS et le VPS
            double cnss = this.salairedebase * 0.2;
            double vps = this.salairedebase * 0.16;

            // Calculer le salaire
            double salaire = this.sursalaire + this.salairedebase + this.bonus - cnss - vps;
            // Console.WriteLine("Le salaire est de : "+ salaire );
            return salaire;
        }

        public Employe(string nom, string prenom, DateTime dateNaiss) : base(nom, prenom, dateNaiss)
        {

        }

        public override void afficher()
        {
            base.afficher();
            // Console.Write("Salaire : " + this.salaire );
        }
    }
}
