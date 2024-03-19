choix = 0
while choix != 5:
    print('Choisissez une opération :')
    choix = int(input('''
        1- addition
        2- soustraction
        3- multiplication
        4- division
        5- Pour quitter le programme
    '''))

    if choix == 1:
        x = int(input('entrez le premier entier : '))
        y = int(input('entrez le second entier : '))
        print("La somme de ",x," et de ",y," est ",x+y)
    elif choix == 2:
        print("Option 2 sélectionnée")
    elif choix == 3:
        print("Option 3 sélectionnée")
    elif choix == 4:
        print("Option 4 sélectionnée")
    elif choix == 5:
        print("Vous avez quitté le programme")
    else:
        print("Option invalide")



