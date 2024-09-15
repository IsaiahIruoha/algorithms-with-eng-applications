#include <stdio.h>
#include <stdlib.h>

#define N 10 

void print_array(int A[], int n) {
    printf("Array contents: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");
}

void insertion_sort(int A[], int n) {
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = A[i];
        j = i - 1;

        while (j >= 0 && A[j] > key) {
            A[j + 1] = A[j];
            j = j - 1;
        }
        A[j + 1] = key;
    }
}


int main() {
    int arr[N];

    printf("Lab 1 - insertion sort\n");

    // // Set each element of the array to a random value in the range 0-127
    // for (int i = 0; i < N; i++) {
    //     arr[i] = rand() >> 24;  // Right shift by 24 bits to get a value between 0 and 127
    // }

    // Set each element of the array to a random value in the range 0-127
    for (int i = 0; i < N; i++) {
        arr[i] = rand() % 128; 
    }

    printf("List before sorting:\n");
    print_array(arr, N);

    insertion_sort(arr, N);

    printf("List after sorting:\n");
    print_array(arr, N);

    return 0;
}
