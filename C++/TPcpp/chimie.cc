 #include <iostream>
#include <string>
#include <cmath>
#define BONUS
using namespace std;

class Flacon
{
private:
  string nom;
  double volume;
  double pH;

public:
  Flacon(string nom, double volume, double pH) : nom(nom), volume(volume), pH(pH) {}

  ostream& etiquette(ostream& sortie)const {
    sortie << nom << " : " << volume << " mL , pH " << pH ;
    return sortie;
  }

  friend ostream& operator<<(ostream& os, const Flacon& flacon) {
     flacon.etiquette(os);
    return os;
  }


  Flacon operator+(const Flacon& flacon) const {
    string nom_melange = nom + " + "+flacon.nom;
    double Volume_melange = volume + flacon.volume;
    double pH_melange = -log10((volume*pow(10.0,-pH) + flacon.volume*pow(10.0,-flacon.pH))/(volume+flacon.volume)) ;
    return Flacon(nom_melange, Volume_melange, pH_melange);
  }
  // Méthode pour diluer le contenu du flacon
    void diluer(double factor) {
        volume *= factor;
        pH -= log10(factor);
    }

    // Méthode pour changer le nom du flacon
    void changerNom(string nouveau_nom) {
        nom = nouveau_nom;
    }

    // Méthode pour comparer le pH de deux flacons
    bool operator>(const Flacon& other) const {
        return pH > other.pH;
    }

    // Méthode pour comparer le volume de deux flacons
    bool operator<(const Flacon& other) const {
        return volume < other.volume;
    }


  Flacon& operator+=(const Flacon& other) {
        
        volume += other.volume;
        nom += " + " + other.nom;
        pH =  -log10((volume*pow(10.0,-pH) + other.volume*pow(10.0,-other.pH))/(volume+other.volume)) ;
        return *this;
    }
};


/*******************************************
 * Ne rien modifier après cette ligne.
 *******************************************/

void afficher_melange(Flacon const& f1, Flacon const& f2)
{
  cout << "Si je mélange " << endl;
  cout << "\t\"" << f1 << "\"" << endl;
  cout << "avec" << endl;
  cout << "\t\"" << f2 << "\"" << endl;
  cout << "j'obtiens :" << endl;
  cout << "\t\"" << (f1 + f2) << "\"" << endl;
}

int main()
{
  Flacon flacon1("Eau", 600.0, 7.0);
  Flacon flacon2("Acide chlorhydrique", 500.0, 2.0);
  Flacon flacon3("Acide perchlorique",  800.0, 1.5);

  afficher_melange(flacon1, flacon2);
  afficher_melange(flacon2, flacon3);
   return 0;
}