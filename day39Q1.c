#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

int heap[MAX];
int size = 0;

// ─── Helper: Swap ─────────────────────────────────────────────────────────────

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// ─── Bubble Up (after insert) ─────────────────────────────────────────────────

void bubbleUp(int i) {
    while (i > 0) {
        int parent = (i - 1) / 2;
        if (heap[parent] > heap[i]) {
            swap(&heap[parent], &heap[i]);
            i = parent;
        } else {
            break;
        }
    }
}

// ─── Heapify Down (after extractMin) ─────────────────────────────────────────

void heapifyDown(int i) {
    int smallest = i;
    int left     = 2 * i + 1;
    int right    = 2 * i + 2;

    if (left  < size && heap[left]  < heap[smallest]) smallest = left;
    if (right < size && heap[right] < heap[smallest]) smallest = right;

    if (smallest != i) {
        swap(&heap[i], &heap[smallest]);
        heapifyDown(smallest);
    }
}

// ─── Core Operations ─────────────────────────────────────────────────────────

void insert(int value) {
    if (size == MAX) {
        printf("Heap Overflow\n");
        return;
    }
    heap[size] = value;
    bubbleUp(size);
    size++;
    printf("Inserted: %d\n", value);
}

void extractMin() {
    if (size == 0) {
        printf("-1\n");
        return;
    }
    printf("%d\n", heap[0]);        // Print minimum (root)
    heap[0] = heap[size - 1];       // Move last element to root
    size--;
    heapifyDown(0);                 // Restore heap property
}

void peek() {
    if (size == 0) {
        printf("-1\n");
        return;
    }
    printf("%d\n", heap[0]);        // Minimum always at root
}

// ─── Display Heap ─────────────────────────────────────────────────────────────

void displayHeap() {
    if (size == 0) {
        printf("Heap is empty\n");
        return;
    }
    printf("Heap array: [ ");
    for (int i = 0; i < size; i++) {
        if (i == size - 1)
            printf("%d ", heap[i]);
        else
            printf("%d, ", heap[i]);
    }
    printf("]\n");

    // Print tree structure level by level
    printf("Heap tree:\n");
    int level = 1;
    int i     = 0;
    while (i < size) {
        printf("  Level %d: ", level);
        for (int j = 0; j < level && i < size; j++, i++)
            printf("%d ", heap[i]);
        printf("\n");
        level *= 2;
    }
}

// ─── Main ─────────────────────────────────────────────────────────────────────

int main() {
    int  n;
    char operation[20];
    int  value;

    printf("Enter number of operations: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter operation (insert x / extractMin / peek): ");
        scanf("%s", operation);

        if (strcmp(operation, "insert") == 0) {
            scanf("%d", &value);
            insert(value);
            displayHeap();
        } else if (strcmp(operation, "extractMin") == 0) {
            extractMin();
            displayHeap();
        } else if (strcmp(operation, "peek") == 0) {
            peek();
        } else {
            printf("Invalid operation\n");
        }
        printf("\n");
    }

    return 0;
}