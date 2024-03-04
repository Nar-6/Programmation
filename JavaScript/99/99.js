class carte {
    valeur;
    
    constructor(valeur) {
        this.valeur = valeur;
    }
    
    getValeur(){
        return this.valeur;
    }
    setValeur(newVal){
        this.valeur = newVal ;
    }

}

class deck {
    cartes = [
        new carte(),
        new carte(),
        new carte()
    ];

    constructor(cartes) {
        this.cartes = cartes;
    }
    getCartes(){
        return this.cartes;
    }
    setCartes(newVal){
        this.cartes = newVal ;
    }

}

class Joueur {
    nom;
    deck = new deck(); 

    constructor(nom,deck){
        this.nom = nom;
        this.deck = deck;
    }
    getCartes(){
        return this.deck;
    }
    setCartes(newVal){
        this.deck = newVal ;
    }
    getNom () {
        return this.nom;
    }
    setNom(newval){
        this.nom = newval;
    }
} 

const joueur1Case = document.querySelector(".joueur1");
const joueur2Case = document.querySelector(".joueur2");
const pioche = document.querySelector(".pioche");
const valeursPossibles = [0,1 ,2,3,4,5,6,7,8,9,10,-10,'multi','1 ou 11','reverse'];

let Joueur1 = new Joueur() ;
let Joueur2 = new Joueur() ;
let joueurCourant = Joueur1 ;

pioche.addEventListener("click",() => {
    let indexAleatoire = Math.floor(Math.random()*valeursPossibles.length);
    let aleatoire = valeursPossibles[indexAleatoire];
    joueurCourant.deck.cartes[1].valeur = aleatoire;
});
