// import Personne; 
import java.io.*; 
public class Test1{ public static void main(String arg[]){ 
// p1
 Personne p1=new Personne("Jean","Dupont",30); 
 System.out.print("p1="); p1.identifie(); 
// p2 référence le même objet que p1
 Personne p2=p1; 
 System.out.print("p2="); p2.identifie(); 
// p3 référence un objet qui sera une copie de l'objet référencé par p1
 Personne p3=new Personne(p1); 
 System.out.print("p3="); p3.identifie(); 
// on change l'état de l'objet référencé par p1
 p1.initialise("Micheline","Benoît",67); 
 System.out.print("p1="); p1.identifie(); 
// comme p2=p1, l'objet référencé par p2 a du changer d'état
 System.out.print("p2="); p2.identifie(); 
// comme p3 ne référence pas le même objet que p1, l'objet référencé par p3 n'a pas du changer
 System.out.print("p3="); p3.identifie(); 
 } 
}