#include <stdio.h>

int main() {
    int p, q;
    printf("enter the size of array1");
    scanf("%d", &p);
    int A[p];
    printf("enter the values of array1");

    for (int i = 0; i < p; i++) {
        scanf("%d", &A[i]);
    }
    printf("enter the size of array2");
    scanf("%d", &q);
    int B[q];
    printf("enter the values of array2");
    for (int i = 0; i < q; i++) {
        scanf("%d", &B[i]);
    }

    int i = 0, j = 0;

    while (i < p && j < q) {
        if (A[i] <= B[j]) {
            printf("%d ", A[i]);
            i++;
        } else {
            printf("%d ", B[j]);
            j++;
        }
    }
    while (i < p) {
        printf("%d ", A[i]);
        i++;
    }
    while (j < q) {
        printf("%d ", B[j]);
        j++;
    }

    return 0;
}
