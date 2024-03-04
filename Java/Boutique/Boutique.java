public class Boutique {
    public String nom;
    public Produit[] produits;

    public Boutique(String nom) {
        this.nom = nom;
    }

    public String getNom() {
        return nom;
    }

    public void setNom(String nom) {
        this.nom = nom;
    }

    public Produit[] getProduits() {
        return produits;
    }

    public void setProduits(Produit[] produits) {
        this.produits = produits;
    }

    public static void main(String[] args) {
        Produit[] produits = {
            new Produit("A", 5),
            new Produit("B", 15),
            new Produit("C", 11)
        };

        Boutique boutique = new Boutique("B1");
        boutique.setProduits(produits);
        System.out.println("ah "+ boutique.produits[2].nbre);
    }
}
