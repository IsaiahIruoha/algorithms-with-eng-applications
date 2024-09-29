import numpy as np
import time

N = 50  

a = np.zeros((N, N))
b = np.zeros((N, N))
c = np.zeros((N, N))

def matrix_multiply():
    """Basic matrix multiplication algorithm."""
    global a, b, c
    for i in range(N):
        for j in range(N):
            c[i][j] = 0
            for k in range(N):
                c[i][j] += a[i][k] * b[k][j]

def initialize_my_data():
    """Set the contents of a and b with non-zero values for testing."""
    global a, b
    for i in range(N):
        for j in range(N):
            a[i][j] = i + j  # Example: Sum of indices
            b[i][j] = i - j  # Example: Difference of indices

def main():
    start_time = time.time()
    
    matrix_multiply()
    
    finish_time = time.time()
    
    elapsed_time = finish_time - start_time
    print(f"Problem size N = {N}, Elapsed time = {elapsed_time:.5f} seconds")

if __name__ == "__main__":
    main()
