#!/bin/python3

import math
import os
import random
import re
import sys

#
# Complete the 'plusMinus' function below.
#
# The function accepts INTEGER_ARRAY arr as parameter.
#

def plusMinus(arr):
    nbrP = 0
    nbrM = 0
    nbrZ = 0
    for p in arr:
        if p > 0:
            nbrP += 1
        elif p < 0:
            nbrM += 1
        else:
            nbrZ += 1
    
    total = len(arr)
    print(f"{nbrP / total:.6f}")
    print(f"{nbrM / total:.6f}")
    print(f"{nbrZ / total:.6f}")


if __name__ == '__main__':
    n = int(input().strip())

    arr = list(map(int, input().rstrip().split()))

    plusMinus(arr)
