#!/bin/python3

import math
import os
import random
import re
import sys

#
# Complete the 'breakingRecords' function below.
#
# The function is expected to return an INTEGER_ARRAY.
# The function accepts INTEGER_ARRAY scores as parameter.
#

def breakingRecords(scores):
    # Write your code here
    scoreMax = scores[0]
    scoreMin = scores[0]
    nbrMax = 0
    nbrMin = 0
    
    for score in scores:
        if score > scoreMax:
            scoreMax = score
            nbrMax += 1
        elif score < scoreMin:
            scoreMin = score
            nbrMin += 1
    
    return [nbrMax, nbrMin]   
    
        
        

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    n = int(input().strip())

    scores = list(map(int, input().rstrip().split()))

    result = breakingRecords(scores)

    fptr.write(' '.join(map(str, result)))
    fptr.write('\n')

    fptr.close()
