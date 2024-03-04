using System;

namespace Personne
{
    public class Directeur:Chef
    {
        public string societe { get; set; }

        public Directeur(string nom, string prenom, DateTime dateNaiss,string service, string societe): base(nom, prenom, dateNaiss, service)
        {
            this.societe = societe;
        }

         public override void afficher() {
            base.afficher();
            Console.Write("Societe : " + this.societe );
        }

         public override double calculeSalaire(){
            
            double salaire = base.calculeSalaire();
            Console.WriteLine("Entrez le montant de la prime : ");
            double prime = Convert.ToDouble(Console.ReadLine());
            return prime + salaire;

            // Console.Write("Salaire : " + this.salaire );
        }
    }
}
