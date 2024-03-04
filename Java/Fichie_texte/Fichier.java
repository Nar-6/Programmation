import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;


public class Fichier {
    public static void main(String[] args) {
        try {
            String nomFichier = "nomFichier.txt";

            File fichier = new File(nomFichier);

            FileWriter writer = new FileWriter(fichier,true);

            if (fichier.exists() && fichier.length() == 0) {
                writer.write("Bonjour tout le monde. ehgdcb\n");
                System.out.println("Fichier ou texte créé avec succès");
            } else {
                BufferedReader lecteur = new BufferedReader(new FileReader(nomFichier));
                String ligne;
                StringBuilder contenu = new StringBuilder();

                while ((ligne = lecteur.readLine()) != null) {
                    if ((ligne = lecteur.readLine()) == null) {
                        ligne += "contenu ajouté à la ligne";
                    }
                    contenu.append(ligne).append("\n");
                }
                lecteur.close();
                writer.write(contenu.toString());
                System.out.println("Fichier ajouté avec succès");
            }


            writer.close();

        } catch (IOException e) {
            // TODO: handle exception
            e.printStackTrace();
        }
    }
}