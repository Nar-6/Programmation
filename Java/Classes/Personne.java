public class Personne{ 
 // attributs
 private String prenom; private String nom; 
 private int age; 
 
 // constructeurs
 public Personne(String P, String N, int age){ 
 initialise(P,N,age); 
 } 
 public Personne(Personne P){ 
 initialise(P); 
 } 
 // méthode
 public void initialise(String P, String N, int age){ 
 this.prenom=P; 
 this.nom=N; this.age=age; 
 } 
 public void initialise(Personne P){ this.prenom=P.prenom; 
 this.nom=P.nom; 
 this.age=P.age; 
 } 
 // méthode
 public void identifie(){ 
 System.out.println(prenom+","+nom+","+age); 
 } 
}