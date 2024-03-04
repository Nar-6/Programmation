import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;


public class Fichier {
    public static void main(String[] args) {
        try {
            Scanner scanner = new Scanner (System.in);

            String nomFichier = "nomFichier.txt";
            String contenu;
            File fichier = new File(nomFichier);

            FileWriter writer = new FileWriter(fichier,true);

            System.out.println("Entrez votre note pour connaitre votre mention !");
            contenu = scanner.nextLine();
            contenu = contenu + "\n";

            if (fichier.exists() && fichier.length() == 0) {
                writer.write(contenu);
                System.out.println("Fichier ou texte créé avec succès");
            } else {
                BufferedReader lecteur = new BufferedReader(new FileReader(nomFichier));
                String ligne;

                while ((ligne = lecteur.readLine()) != null) {
                    if ((ligne = lecteur.readLine()) == null) {
                        writer.write(contenu);
                    }
                }
                lecteur.close();
                System.out.println("Fichier ajouté avec succès");
            }


            writer.close();
            scanner.close();
        } catch (IOException e) {
            // TODO: handle exception
            e.printStackTrace();
        }
    }
}