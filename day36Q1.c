#include <stdio.h>
#include <stdlib.h>

#define MAX 6   // One extra slot to distinguish full vs empty

int queue[MAX];
int front = -1;
int rear  = -1;

void enqueue(int value) {
    int nextRear = (rear + 1) % MAX;
    if (nextRear == front) {
        printf("Queue Overflow\n");
        return;
    }
    if (front == -1)
        front = 0;              // First element sets front
    rear = nextRear;
    queue[rear] = value;
}

int dequeue() {
    if (front == -1) {
        printf("Queue Underflow\n");
        return -1;
    }
    int value = queue[front];
    if (front == rear) {
        front = -1;             // Queue becomes empty
        rear  = -1;
    } else {
        front = (front + 1) % MAX;  // Wrap around
    }
    return value;
}

void display() {
    if (front == -1) {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue (front to rear): ");
    int i = front;
    while (1) {
        if (i == rear) {
            printf("%d", queue[i]);
            break;
        }
        printf("%d ", queue[i]);
        i = (i + 1) % MAX;     // Wrap around
    }
    printf("\n");
}

int main() {
    int n, m, val;

    printf("Enter number of elements to enqueue: ");
    scanf("%d", &n);

    printf("Enter %d elements: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        enqueue(val);
    }

    printf("\n--- Queue After Enqueue ---\n");
    display();

    printf("\nEnter number of elements to dequeue: ");
    scanf("%d", &m);

    printf("\n--- Dequeue Operations ---\n");
    for (int i = 0; i < m; i++) {
        int dequeued = dequeue();
        if (dequeued != -1)
            printf("Dequeued: %d\n", dequeued);
    }

    // Wrap around: enqueue dequeued elements at rear
    printf("\n--- Wrapping dequeued slots ---\n");
    for (int i = 0; i < m; i++) {
        enqueue(queue[(front - m + i + MAX) % MAX]);
    }

    printf("\n--- Queue After Wrap Around ---\n");
    display();

    return 0;
}