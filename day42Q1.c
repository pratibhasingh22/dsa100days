#include <stdio.h>
#include <stdlib.h>

// ─── Stack Node ───────────────────────────────────────────────────────────────

struct StackNode {
    int data;
    struct StackNode* next;
};

// ─── Queue Node ───────────────────────────────────────────────────────────────

struct QueueNode {
    int data;
    struct QueueNode* next;
};

// ─── Queue Structure ──────────────────────────────────────────────────────────

struct Queue {
    struct QueueNode* front;
    struct QueueNode* rear;
    int size;
};

// ─── Stack Operations ─────────────────────────────────────────────────────────

struct StackNode* stackTop = NULL;

void push(int value) {
    struct StackNode* newNode = (struct StackNode*)malloc(sizeof(struct StackNode));
    newNode->data = value;
    newNode->next = stackTop;
    stackTop      = newNode;
}

int pop() {
    if (stackTop == NULL) return -1;
    int value         = stackTop->data;
    struct StackNode* temp = stackTop;
    stackTop          = stackTop->next;
    free(temp);
    return value;
}

int isStackEmpty() {
    return stackTop == NULL;
}

// ─── Queue Operations ─────────────────────────────────────────────────────────

void initQueue(struct Queue* q) {
    q->front = NULL;
    q->rear  = NULL;
    q->size  = 0;
}

void enqueue(struct Queue* q, int value) {
    struct QueueNode* newNode = (struct QueueNode*)malloc(sizeof(struct QueueNode));
    newNode->data = value;
    newNode->next = NULL;
    if (q->rear == NULL) {
        q->front = newNode;
        q->rear  = newNode;
    } else {
        q->rear->next = newNode;
        q->rear       = newNode;
    }
    q->size++;
}

int dequeue(struct Queue* q) {
    if (q->front == NULL) return -1;
    struct QueueNode* temp = q->front;
    int value              = temp->data;
    q->front               = q->front->next;
    if (q->front == NULL)
        q->rear = NULL;
    free(temp);
    q->size--;
    return value;
}

// ─── Display Queue ────────────────────────────────────────────────────────────

void displayQueue(struct Queue* q, const char* label) {
    printf("%s [ ", label);
    struct QueueNode* temp = q->front;
    while (temp != NULL) {
        if (temp->next == NULL)
            printf("%d ", temp->data);
        else
            printf("%d, ", temp->data);
        temp = temp->next;
    }
    printf("]\n");
}

// ─── Reverse Queue Using Stack ────────────────────────────────────────────────

void reverseQueue(struct Queue* q) {
    // Step 1: Dequeue all elements and push onto stack
    printf("--- Step 1: Dequeue → Push to Stack ---\n");
    while (q->front != NULL) {
        int val = dequeue(q);
        printf("  Dequeue %d → Push to stack\n", val);
        push(val);
    }

    // Step 2: Pop from stack and enqueue back
    printf("\n--- Step 2: Pop from Stack → Enqueue ---\n");
    while (!isStackEmpty()) {
        int val = pop();
        printf("  Pop %d → Enqueue to queue\n", val);
        enqueue(q, val);
    }
}

// ─── Free Queue ───────────────────────────────────────────────────────────────

void freeQueue(struct Queue* q) {
    while (q->front != NULL) {
        struct QueueNode* temp = q->front;
        q->front = q->front->next;
        free(temp);
    }
    q->rear = NULL;
    q->size = 0;
}

// ─── Main ─────────────────────────────────────────────────────────────────────

int main() {
    int n, val;
    struct Queue q;
    initQueue(&q);

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter %d elements: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        enqueue(&q, val);
    }

    printf("\n════════════════════════════════════\n");
    printf("      REVERSE QUEUE USING STACK     \n");
    printf("════════════════════════════════════\n\n");

    displayQueue(&q, "Original queue: ");

    printf("\n");
    reverseQueue(&q);

    printf("\n");
    displayQueue(&q, "Reversed queue: ");

    freeQueue(&q);
    return 0;
}