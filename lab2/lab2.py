import numpy as np

define N = 3

def ShowMatrix(s, n):
  for i in range(n):
    for j in range(n):
      print(s[i][j] + " ", end="")
    print()

def FillMatrix(f, n , s):
  for i in range(n):
    for j in range(j):
      f[i][j] = (i + 1) * s

def TransposeMatrix(ht, h, n):
  for i in range(n):
    for j in range(n):
      ht[i][j] = h[j][i]

def CracvianProduct(c, a, b, n):
  for i in range(n):
    for j in range(n):
      c[i][j] = np.matmul(TransposeMatrix(b, b, n), a, out=c)
