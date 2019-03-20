# -*- coding: utf-8 -*-
"""
Created on Sun Mar 25 12:00:53 2018

@author: BBG
"""

## module gaussElimin

"""
x = gaussElimin(a,b)
solves [a]{b} = {x} by Gauss Elimination
"""
import numpy as np
from numpy import dot

def gaussElimin(a, b):
    n = len(b)
    print(a)
    
    # Elimination phase
    for j in range(0, n-1): # for the columns
        for i in range(j+1, n): # for the rows
            #print (i, j)
            #print (a[i])
            
            if a[i][j] != 0.0:
                lam = a[i][j]/ a[j][j]
                for k in range(j+1, n):
                    
                    a[i][k] = a[i][k] - lam*a[j][k]
                    #print(a)
                    #print(b[i])
                    b[i][j] = b[i][j] - lam*b[j][j]
                    
            #print(a)
            print('----------------------')
            print(b)
    # back substitution
    for j in range(n-1, -1, -1):
        b[j] = (b[j] - dot(a[j][j+1:n], b[j+1][n])/a[j][j])
    return b