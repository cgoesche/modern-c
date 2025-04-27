#include <stdio.h>
#include <stdlib.h>
#include "test-double-arr-sort.h"

#define ARR_LEN(x) (sizeof(A)/sizeof(*A))

void merge_sort(double a[], size_t p, size_t r);
void merge(double a[], size_t p, size_t q, size_t r);
void print_arr(double a[], int a_len);
int is_sorted(double a[], int len);

int main(void)
{
        double A[12] = { 0.5, 0.3, 0.2, 0.1, 0.9, 0.8, 0.7, 0.6, 0.4, 0.3, 0.1, 0.2 };
        char* resp;

        merge_sort(A, 0, ARR_LEN(A) - 1);
        print_arr(A, ARR_LEN(A));
        resp = is_sorted(A, ARR_LEN(A)) ? "" : "not";

        printf("The array is %s sorted!\n", resp);

        return EXIT_SUCCESS;
}

void merge_sort(double a[], size_t p, size_t r)
{
        if (p < r) {
                size_t q = p + (r - p) / 2;
               
                merge_sort(a, p, q);
                merge_sort(a, q + 1, r);
                merge(a, p, q, r);
        }
}

void merge(double a[], size_t p, size_t q, size_t r)
{       
        size_t l_len = q - p + 1;
        size_t r_len = r - q;

        double L[l_len];
        double R[r_len];

        for (int i = 0; i < l_len; i++) {
                L[i] = a[p + i];
        }

        for (int i = 0; i < r_len; i++) {
                R[i] = a[q + 1 + i];
        }

        int i = 0, j = 0;
        int k = p;
        while (k <= r) {
                if ((i < l_len) && (j >= r_len || L[i] <= R[j])) {
                        a[k] = L[i];
                        i++;
                } else {
                        a[k] = R[j];
                        j++;
                }
        k++;
        }
}

void print_arr(double a[], int a_len)
{
        for (size_t i = 0; i < a_len; ++i) {
                printf("%.2f ", a[i]);
        }
        printf("\n");
}