using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;

namespace Personne
{
    public class Secretaire:Employe
    {
        public string societe { get; set; }

        public Secretaire(string nom, string prenom, DateTime dateNaiss,string societe): base(nom, prenom, dateNaiss)
        {
            this.societe = societe;
        }

         public override void afficher() {
            base.afficher();
            Console.Write("Societe : " + this.societe );
        }
    }
}