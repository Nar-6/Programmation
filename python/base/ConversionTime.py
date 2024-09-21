#!/bin/python3

import math
import os
import random
import re
import sys

#
# Complete the 'timeConversion' function below.
#
# The function is expected to return a STRING.
# The function accepts STRING s as parameter.
#

def timeConversion(s):
    # Extraire AM/PM
    period = s[-2:]
    
    # Extraire l'heure, les minutes et les secondes
    hour = int(s[:2])
    minutes_seconds = s[2:-2]
    
    # Si c'est AM
    if period == "AM":
        if hour == 12:
            # 12 AM -> 00
            return f"00{minutes_seconds}"
        else:
            # Autres heures AM, pas de changement
            return f"{s[:2]}{minutes_seconds}"
    
    # Si c'est PM
    else:
        if hour == 12:
            # 12 PM reste inchangé
            return f"12{minutes_seconds}"
        else:
            # Ajouter 12 pour les heures PM
            return f"{hour + 12:02}{minutes_seconds}"
            
            

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    s = '12:00:00AM'

    result = timeConversion(s)

    fptr.write(result + '\n')

    fptr.close()
