#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include "test-double-arr-sort.h"

#define ARR_LEN(x) (sizeof(A) / sizeof(*A))

void quicksort(double A[], size_t p, size_t r);
size_t partition(double A[], size_t p, size_t r);
void print_arr(double A[], size_t p, size_t r);

int main(){
    double A[10] = {3.2, 4.3, 8.1, 1.1, 4.2, 7.3, 1.2, 7, 2, 4.1};
    char *resp;

    printf("Unsorted initial array:\t");

    print_arr(A, 0, ARR_LEN(A) - 1);

    quicksort(A, 0, ARR_LEN(A) - 1);
    
    printf("Sorted array:\t\t");
    print_arr(A, 0, ARR_LEN(A) - 1);

    
    resp = is_sorted(A, ARR_LEN(A)) ? "" : "not";
    printf("The array is %s sorted.\n", resp);

    return EXIT_SUCCESS;
}

void quicksort(double A[], size_t p, size_t r){
    size_t q;

    if (p < r){
        q = partition(A, p, r);
        quicksort(A, p, q - 1);
        quicksort(A, q + 1, r);
    }
}

size_t partition(double A[], size_t p, size_t r){
    double x = A[r];
    int i = p - 1;
    double _temp;

    for(int j = p; j < r; j++){  
        _temp = 0;

        if (A[j] <= x){
            i = i + 1;
            _temp = A[i];
            A[i] = A[j];
            A[j] = _temp;
        }
    }

    _temp = A[i + 1];
    A[i + 1] = A[r];
    A[r] = _temp;

    return i + 1;
}

void print_arr(double A[], size_t p, size_t r){
    for (size_t i = p; i <= r; i++){
        printf(" %.1f", A[i]);
    }
    printf("\n");
}


