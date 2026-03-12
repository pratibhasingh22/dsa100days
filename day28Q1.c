#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void appendNode(struct Node** head, struct Node** tail, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        *tail = newNode;
        newNode->next = *head;  // Points to itself
        return;
    }
    (*tail)->next = newNode;    // Link old tail to new node
    *tail = newNode;            // Update tail
    (*tail)->next = *head;      // New tail points back to head
}

void traverseCircular(struct Node* head) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    struct Node* temp = head;
    do {
        if (temp->next == head)
            printf("%d", temp->data);
        else
            printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);    // Stop when we return to head
    printf("\n");
}

void freeList(struct Node* head) {
    if (head == NULL) return;
    struct Node* temp = head->next;
    struct Node* nextNode;
    while (temp != head) {
        nextNode = temp->next;
        free(temp);
        temp = nextNode;
    }
    free(head);
}

int main() {
    int n, val;
    struct Node* head = NULL;
    struct Node* tail = NULL;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter %d elements: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        appendNode(&head, &tail, val);
    }

    printf("Circular linked list: ");
    traverseCircular(head);

    freeList(head);
    return 0;
}