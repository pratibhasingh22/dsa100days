#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// ─── Node Structure ───────────────────────────────────────────────────────────

struct Node {
    int data;
    struct Node* next;
};

// ─── Queue Structure ──────────────────────────────────────────────────────────

struct Queue {
    struct Node* front;
    struct Node* rear;
    int size;
};

// ─── Initialize Queue ─────────────────────────────────────────────────────────

void initQueue(struct Queue* q) {
    q->front = NULL;
    q->rear  = NULL;
    q->size  = 0;
}

// ─── Enqueue ──────────────────────────────────────────────────────────────────

void enqueue(struct Queue* q, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;

    if (q->rear == NULL) {
        q->front = newNode;     // First element sets both front and rear
        q->rear  = newNode;
    } else {
        q->rear->next = newNode;  // Link new node at rear
        q->rear       = newNode;  // Update rear
    }
    q->size++;
    printf("Enqueued: %d\n", value);
}

// ─── Dequeue ──────────────────────────────────────────────────────────────────

void dequeue(struct Queue* q) {
    if (q->front == NULL) {
        printf("-1\n");
        return;
    }
    struct Node* temp = q->front;
    printf("Dequeued: %d\n", temp->data);

    q->front = q->front->next;  // Move front forward
    if (q->front == NULL)
        q->rear = NULL;         // Queue is now empty

    free(temp);
    q->size--;
}

// ─── Peek ─────────────────────────────────────────────────────────────────────

void peek(struct Queue* q) {
    if (q->front == NULL) {
        printf("peek()    → -1\n");
        return;
    }
    printf("peek()    → %d\n", q->front->data);
}

// ─── isEmpty ──────────────────────────────────────────────────────────────────

void isEmpty(struct Queue* q) {
    printf("empty()   → %s\n", q->front == NULL ? "true" : "false");
}

// ─── Size ─────────────────────────────────────────────────────────────────────

void getSize(struct Queue* q) {
    printf("size()    → %d\n", q->size);
}

// ─── Display ──────────────────────────────────────────────────────────────────

void display(struct Queue* q) {
    if (q->front == NULL) {
        printf("Queue     → [ empty ]\n");
        return;
    }
    printf("Queue     → [ ");
    struct Node* temp = q->front;
    while (temp != NULL) {
        if (temp->next == NULL)
            printf("%d ", temp->data);
        else
            printf("%d, ", temp->data);
        temp = temp->next;
    }
    printf("] ← rear\n");
}

// ─── Free Queue ───────────────────────────────────────────────────────────────

void freeQueue(struct Queue* q) {
    struct Node* temp;
    while (q->front != NULL) {
        temp     = q->front;
        q->front = q->front->next;
        free(temp);
    }
    q->rear = NULL;
    q->size = 0;
}

// ─── Main ─────────────────────────────────────────────────────────────────────

int main() {
    int n, value;
    char operation[20];
    struct Queue q;
    initQueue(&q);

    printf("Enter number of operations: ");
    scanf("%d", &n);

    printf("\n════════════════════════════════════\n");
    printf("       QUEUE (LINKED LIST)          \n");
    printf("════════════════════════════════════\n\n");

    for (int i = 0; i < n; i++) {
        printf("Enter operation (enqueue x / dequeue / peek / size / empty / display): ");
        scanf("%s", operation);

        if (strcmp(operation, "enqueue") == 0) {
            scanf("%d", &value);
            enqueue(&q, value);
            display(&q);
        } else if (strcmp(operation, "dequeue") == 0) {
            dequeue(&q);
            display(&q);
        } else if (strcmp(operation, "peek") == 0) {
            peek(&q);
        } else if (strcmp(operation, "size") == 0) {
            getSize(&q);
        } else if (strcmp(operation, "empty") == 0) {
            isEmpty(&q);
        } else if (strcmp(operation, "display") == 0) {
            display(&q);
        } else {
            printf("Invalid operation\n");
        }
        printf("\n");
    }

    freeQueue(&q);
    return 0;
}