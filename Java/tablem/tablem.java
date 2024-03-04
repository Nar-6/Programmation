// package tablem;

import java.util.Scanner;

public class tablem {
    public static void main(String[] args) {

        for (int j = 0; j<13; j++){
            System.out.println(" Table de " + j);
             for (int i = 0; i < 13; i++) {
                System.out.println(j+" x "+ i +" = " + j*i);
            }
            System.out.println(" \n\n");
            // System.out.println(" ------------- ");
        }
}
}
