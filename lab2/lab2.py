import sys 
import numpy as np

# Constant parameter
N = 3

# Function to show matrix with space between row elements
def ShowMatrix(s, n):
    for i in range(n):
        for j in range(n):
            print(s[i][j], end=" ")
        print()  # Blank line after completing each row

# Function to fill matrix with scale factor s
def FillMatrix(f, n, s):
    for i in range(n):
        for j in range(n):
            f[i][j] = (i + 1) * s

# Function to transpose matrix
def TransposeMatrix(ht, h, n):
    for i in range(n):
        for j in range(n):
            ht[i][j] = h[j][i]

# Function to compute Cracovian matrix product
def CracovianProduct(c, a, b, n):
    ht = np.zeros((n, n))  # Create a new local matrix for the transpose
    TransposeMatrix(ht, b, n)  # Transpose matrix b into ht
    np.matmul(a, ht, out=c)  # Multiply a by transpose(b) and store in c

# Main function to handle command line arguments and matrix operations
def main():
    if len(sys.argv) != 3:
        print("Error: Expected 2 arguments for scale factors sa and sb.")
        return
    
    # Convert arguments to float
    try:
        sa = float(sys.argv[1])
        sb = float(sys.argv[2])
    except ValueError:
        print("Error: Arguments must be floating-point values.")
        return

    # Create the matrices
    a = np.zeros((N, N))
    b = np.zeros((N, N))
    c = np.zeros((N, N))

    # Fill the matrices with the scale factors
    FillMatrix(a, N, sa)
    FillMatrix(b, N, sb)

    # Compute Cracovian product
    CracovianProduct(c, a, b, N)

    # Display the final result matrix c
    print("Resulting matrix C (Cracovian product of A and B):")
    ShowMatrix(c, N)

# Entry point of the program
if __name__ == "__main__":
    main()
   
