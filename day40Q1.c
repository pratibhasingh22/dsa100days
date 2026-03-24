#include <stdio.h>
#include <stdlib.h>

// ─── Heapify Down (Max Heap) ──────────────────────────────────────────────────

void heapifyDown(int arr[], int n, int i) {
    int largest = i;
    int left    = 2 * i + 1;
    int right   = 2 * i + 2;

    if (left  < n && arr[left]  > arr[largest]) largest = left;
    if (right < n && arr[right] > arr[largest]) largest = right;

    if (largest != i) {
        int temp       = arr[i];
        arr[i]         = arr[largest];
        arr[largest]   = temp;
        heapifyDown(arr, n, largest);
    }
}

// ─── Build Max Heap ───────────────────────────────────────────────────────────

void buildMaxHeap(int arr[], int n) {
    // Start from last non-leaf node and heapify down
    for (int i = n / 2 - 1; i >= 0; i--)
        heapifyDown(arr, n, i);
}

// ─── Heap Sort ────────────────────────────────────────────────────────────────

void heapSort(int arr[], int n) {
    // Step 1: Build max heap from input array
    buildMaxHeap(arr, n);

    printf("Max Heap built: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n\n");

    // Step 2: Extract max one by one
    printf("--- Extraction Steps ---\n");
    for (int i = n - 1; i > 0; i--) {
        // Move current root (max) to end
        int temp = arr[0];
        arr[0]   = arr[i];
        arr[i]   = temp;

        printf("Extracted max: %d → Placed at index %d\n", arr[i], i);

        // Heapify reduced heap
        heapifyDown(arr, i, 0);

        // Print current state
        printf("Array state:   [ ");
        for (int j = 0; j < n; j++) {
            if (j == i) printf("| ");       // Separator: sorted portion
            printf("%d ", arr[j]);
        }
        printf("]\n");
        printf("                 ");
        for (int j = 0; j < i; j++) printf("    ");
        printf("↑ sorted\n\n");
    }
}

// ─── Display ──────────────────────────────────────────────────────────────────

void printArray(int arr[], int n, const char* label) {
    printf("%s [ ", label);
    for (int i = 0; i < n; i++) {
        if (i == n - 1) printf("%d ", arr[i]);
        else            printf("%d, ", arr[i]);
    }
    printf("]\n");
}

// ─── Main ─────────────────────────────────────────────────────────────────────

int main() {
    int n;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int* arr = (int*)malloc(n * sizeof(int));

    printf("Enter %d elements: ", n);
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    printf("\n════════════════════════════════════\n");
    printf("          HEAP SORT                 \n");
    printf("════════════════════════════════════\n\n");

    printArray(arr, n, "Original array:");
    printf("\n");

    heapSort(arr, n);

    printArray(arr, n, "Sorted array:  ");

    free(arr);
    return 0;
}