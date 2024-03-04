' Imports System

' Module Program
'     Sub Main(args As String())
'         Console.WriteLine("Hello World!")
'     End Sub
' End Module
Imports System

Module Program
    Sub Main()
        Dim input As String
        Console.Write("Entrez deux valeurs séparées par un espace : ")
        input = Console.ReadLine()

        Dim result As Double = SommeDeuxValeurs(input)
        Console.WriteLine("La somme des deux valeurs est : " & result)
    End Sub

    Function SommeDeuxValeurs(input As String) As Double
        Dim values() As String = input.Split(" ")

        If values.Length = 2 Then
            Dim valeur1 As Double
            Dim valeur2 As Double

            If Double.TryParse(values(0), valeur1) AndAlso Double.TryParse(values(1), valeur2) Then
                Return valeur1 + valeur2
            Else
                Console.WriteLine("Les valeurs saisies ne sont pas valides.")
            End If
        Else
            Console.WriteLine("Veuillez entrer deux valeurs séparées par un espace.")
        End If

        ' Si les valeurs ne sont pas valides, retourne NaN (Not-a-Number)
        Return Double.NaN
    End Function
End Module
