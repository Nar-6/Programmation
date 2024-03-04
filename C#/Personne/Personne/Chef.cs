using System;

namespace Personne
{
    public class Chef:Employe
    {
        public string service { get; set; }

        public Chef(string nom, string prenom, DateTime dateNaiss, string service): base(nom, prenom, dateNaiss)
        {
            this.service = service;
        }

        public override void afficher() {
            base.afficher();
            Console.Write("Service : " + this.service );
        }

        public override double calculeSalaire(){

            double salaire = base.calculeSalaire();
            Console.WriteLine("Entrez le montant de la prime de responsabilité : ");
            double primeChef = Convert.ToDouble(Console.ReadLine());
            return primeChef + salaire;

            // Console.Write("Salaire : " + this.salaire );
        }
    }
}
