#!/bin/python3

import math
import os
import random
import re
import sys

#
# Complete the 'miniMaxSum' function below.
#
# The function accepts INTEGER_ARRAY arr as parameter.
#

def max(arr):
    maxN = arr[0]
    for ar in arr:
        if ar > maxN:
            maxN = ar
    return maxN
    
def min(arr):
    minN = arr[0]
    for ar in arr:
        if ar < minN:
            minN = ar
    return minN

def miniMaxSum(arr):
    # Write your code here
    total = 0
    for ar in arr:
        total = total + ar
    maxSum = total - min(arr)
    minSum = total - max(arr)
    print(f"{minSum} {maxSum}")
        
    

if __name__ == '__main__':

    arr = list(map(int, input().rstrip().split()))

    miniMaxSum(arr)
