import java.util.Scanner;

public class moy {
    
    public static void main(String[] args) {
        Scanner scanner = new Scanner (System.in);
        int note ;
        boolean voir = false ;
        do {
            System.out.println("Entrez votre note pour connaitre votre mention !");
            note = scanner.nextInt();
            if ( note < 0 || note > 20) {
                System.out.println("Entrez une note sur 20");
            }else  if(!scanner.hasNextInt()){
                System.out.println("Entrez un entier");
            }
            else{
                voir = true;
            }
        } while ( voir == false );

        System.out.println("Vous avez entré "+ note );

       if (note < 9 ) System.out.println("NUL");
       else if (note < 10) System.out.println("Insuffisant");
       else if (note < 12) System.out.println("Passable");
       else if (note < 14) System.out.println("Assez Bien");
       else if (note < 16) System.out.println("Bien");
       else if (note < 18) System.out.println("Tres Bien");
       else if (note < 20) System.out.println("Excellent");

        scanner.close();
    }
}
