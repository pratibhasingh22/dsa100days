#include<stdio.h>

int main(){
    int n, pos;
    char choice;

    do{
        printf("enter the number of elements: ");
        scanf("%d", &n);

        int arr[n];

        printf("enter the elements of the array:\n");
        for (int i = 0; i < n; i++) {
            scanf("%d", &arr[i]);
        }

        printf("enter the position to delete the element: ");
        scanf("%d", &pos);

        if (pos < 1 || pos > n) {
            printf("invalid position\n");
        }
        else {
            for (int i = pos - 1; i < n - 1; i++) {
                arr[i] = arr[i + 1];
            }

            printf("Updated array:\n");
            for (int i = 0; i < n - 1; i++) {
                printf("%d ", arr[i]);
            }
            printf("\n");
        }

        printf("do u want to continue (y/n): ");
        scanf(" %c", &choice);

    } while (choice == 'y' || choice == 'Y');

    return 0;
}
