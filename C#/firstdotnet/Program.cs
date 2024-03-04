using System;
using System.Linq;
using System.Collections.Generic;

class Program
{   
    static void Main()
    {
        // Fonction d'addition
        int resultatAddition = Additionner(5, 7);
        Console.WriteLine("Résultat de l'addition : " + resultatAddition);

        // Exemple d'utilisation de la méthode Find() avec un tableau
        int[] numbersArray = { 1, 2, 3, 4, 5 };
        int resultatFindArray = numbersArray.FirstOrDefault(x => x == 3);
        Console.WriteLine("Premier élément égal à 3 dans le tableau : " + resultatFindArray);

        // Exemple d'utilisation de la méthode FindIndex() avec un tableau
        int indexFindIndexArray = Array.FindIndex(numbersArray, x => x == 3);
        Console.WriteLine("Index du premier élément égal à 3 dans le tableau : " + indexFindIndexArray);

        // Exemple d'utilisation de la méthode FindLast() avec un tableau
        int[] Array = { 1, 2, 3, 4, 5, 3 };
        int resultatFindLastArray = Array.LastOrDefault(x => x == 3);
        Console.WriteLine("Dernier élément égal à 3 dans le tableau : " + resultatFindLastArray);

        // Exemple d'utilisation de la méthode FindLastIndex() avec un tableau
        int lastIndexFindLastIndexArray = Array.FindLastIndex(Array, x => x == 3);
        Console.WriteLine("Index du dernier élément égal à 3 dans le tableau : " + lastIndexFindLastIndexArray);

        
        // Exemple d'utilisation de la méthode Find()
        List<int> numbers = new List<int> { 1, 2, 3, 4, 5 };
        int resultatFind = numbers.Find(x => x == 3);
        Console.WriteLine("Premier élément égal à 3 : " + resultatFind);

        // Exemple d'utilisation de la méthode FindIndex()
        int indexFindIndex = numbers.FindIndex(x => x == 3);
        Console.WriteLine("Index du premier élément égal à 3 : " + indexFindIndex);

        // Exemple d'utilisation de la méthode FindLast()
        List<int> numbersWithDuplicate = new List<int> { 1, 2, 3, 4, 5, 3 };
        int resultatFindLast = numbersWithDuplicate.FindLast(x => x == 3);
        Console.WriteLine("Dernier élément égal à 3 : " + resultatFindLast);

        // Exemple d'utilisation de la méthode FindLastIndex()
        int lastIndexFindLastIndex = numbersWithDuplicate.FindLastIndex(x => x == 3);
        Console.WriteLine("Index du dernier élément égal à 3 : " + lastIndexFindLastIndex);
    }

        
    // Fonction d'addition qui prend deux paramètres et renvoie la somme
    static int Additionner(int a, int b)    
    {
        int somme = a + b;
        return somme;
    }
}


