#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int queue[MAX];
int front = -1;
int rear  = -1;

void enqueue(int value) {
    if (rear == MAX - 1) {
        printf("Queue Overflow\n");
        return;
    }
    if (front == -1)
        front = 0;          // First element sets front
    queue[++rear] = value;
}

int dequeue() {
    if (front == -1 || front > rear) {
        printf("Queue Underflow\n");
        return -1;
    }
    return queue[front++];
}

void display() {
    if (front == -1 || front > rear) {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue (front to rear): ");
    for (int i = front; i <= rear; i++) {
        if (i == rear)
            printf("%d", queue[i]);
        else
            printf("%d ", queue[i]);
    }
    printf("\n");
}

int isEmpty() {
    return (front == -1 || front > rear);
}

int main() {
    int n, val;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter %d elements: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        enqueue(val);
    }

    printf("\n--- Queue State ---\n");
    display();

    printf("\n--- Dequeue Operations ---\n");
    printf("Dequeued: %d\n", dequeue());
    printf("Dequeued: %d\n", dequeue());

    printf("\n--- Queue After Dequeue ---\n");
    display();

    return 0;
}
