#!/bin/python3

import math
import os
import random
import re
import sys

#
# Complete the 'fibonacciModified' function below.
#
# The function is expected to return an INTEGER.
# The function accepts following parameters:
#  1. INTEGER t1
#  2. INTEGER t2
#  3. INTEGER n
#
def fibonacci(n, memo):
    if (memo[n] != -1):
        return memo[n]
    x = fibonacci(n-1,memo)
    y = fibonacci(n-2,memo)
    memo[n] = x*x + y
    return memo[n]
    
def fibonacciModified(t1, t2, n):
    memo = [-1]*(n+1)
    memo[1] = t1
    memo[2] = t2
    return fibonacci(n, memo)

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    first_multiple_input = input().rstrip().split()

    t1 = int(first_multiple_input[0])

    t2 = int(first_multiple_input[1])

    n = int(first_multiple_input[2])

    result = fibonacciModified(t1, t2, n)

    fptr.write(str(result) + '\n')

    fptr.close()
