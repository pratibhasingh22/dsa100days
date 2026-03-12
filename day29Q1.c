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

void appendNode(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    struct Node* temp = *head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = newNode;
}

struct Node* rotateRight(struct Node* head, int k) {
    if (head == NULL || k == 0)
        return head;

    // Step 1: Find length and tail node
    int length = 1;
    struct Node* tail = head;
    while (tail->next != NULL) {
        tail = tail->next;
        length++;
    }

    // Step 2: Reduce k if greater than length
    k = k % length;
    if (k == 0)
        return head;

    // Step 3: Connect tail to head forming circular list
    tail->next = head;

    // Step 4: Traverse to (length - k)th node (new tail)
    int steps = length - k;
    struct Node* newTail = head;
    for (int i = 1; i < steps; i++)
        newTail = newTail->next;

    // Step 5: New head is next of new tail
    struct Node* newHead = newTail->next;

    // Step 6: Break the circular link
    newTail->next = NULL;

    return newHead;
}

void printList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        if (temp->next == NULL)
            printf("%d", temp->data);
        else
            printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void freeList(struct Node* head) {
    struct Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    int n, val, k;
    struct Node* head = NULL;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter %d elements: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        appendNode(&head, val);
    }

    printf("Enter k (rotation count): ");
    scanf("%d", &k);

    printf("Original list:  ");
    printList(head);

    head = rotateRight(head, k);

    printf("Rotated list:   ");
    printList(head);

    freeList(head);
    return 0;
}