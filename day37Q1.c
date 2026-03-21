#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

int pqueue[MAX];
int size = 0;

void insert(int value) {
    if (size == MAX) {
        printf("Priority Queue Overflow\n");
        return;
    }
    // Insert at end
    pqueue[size] = value;
    int i = size;
    size++;

    // Bubble up to maintain min-heap order
    while (i > 0) {
        int parent = (i - 1) / 2;
        if (pqueue[parent] > pqueue[i]) {
            int temp        = pqueue[parent];
            pqueue[parent]  = pqueue[i];
            pqueue[i]       = temp;
            i               = parent;
        } else {
            break;
        }
    }
    printf("Inserted: %d\n", value);
}

void heapifyDown(int i) {
    int smallest = i;
    int left     = 2 * i + 1;
    int right    = 2 * i + 2;

    if (left  < size && pqueue[left]  < pqueue[smallest])
        smallest = left;
    if (right < size && pqueue[right] < pqueue[smallest])
        smallest = right;

    if (smallest != i) {
        int temp          = pqueue[i];
        pqueue[i]         = pqueue[smallest];
        pqueue[smallest]  = temp;
        heapifyDown(smallest);
    }
}

void delete() {
    if (size == 0) {
        printf("-1\n");
        return;
    }
    printf("%d\n", pqueue[0]);      // Print highest priority (minimum)
    pqueue[0] = pqueue[size - 1];   // Move last element to root
    size--;
    heapifyDown(0);                 // Restore heap order
}

void peek() {
    if (size == 0) {
        printf("-1\n");
        return;
    }
    printf("%d\n", pqueue[0]);      // Minimum is always at root
}

void display() {
    if (size == 0) {
        printf("Priority Queue is empty\n");
        return;
    }
    printf("Priority Queue (heap order): ");
    for (int i = 0; i < size; i++) {
        if (i == size - 1)
            printf("%d", pqueue[i]);
        else
            printf("%d ", pqueue[i]);
    }
    printf("\n");
}

int main() {
    int n;
    char operation[20];
    int value;

    printf("Enter number of operations: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter operation: ");
        scanf("%s", operation);

        if (strcmp(operation, "insert") == 0) {
            scanf("%d", &value);
            insert(value);
        } else if (strcmp(operation, "delete") == 0) {
            delete();
        } else if (strcmp(operation, "peek") == 0) {
            peek();
        } else if (strcmp(operation, "display") == 0) {
            display();
        } else {
            printf("Invalid operation\n");
        }
    }

    return 0;
}