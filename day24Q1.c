#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->next = NULL;
    return node;
}

void deleteFirst(struct Node** head, int key) {
    struct Node* curr = *head;
    struct Node* prev = NULL;

    while (curr != NULL && curr->data != key) {
        prev = curr;
        curr = curr->next;
    }

    if (curr == NULL) return;

    if (prev == NULL) *head = curr->next;
    else prev->next = curr->next;

    free(curr);
}

int main() {
    int n;
    printf("enter the value of n");
    scanf("%d", &n);

    struct Node* head = NULL;
    struct Node* tail = NULL;

    for (int i = 0; i < n; i++) {
        int val;
        printf("the key to be deleted");
        scanf("%d", &val);
        struct Node* node = createNode(val);
        if (!head) head = tail = node;
        else { tail->next = node; tail = node; }
    }

    int key;
    scanf("%d", &key);
    deleteFirst(&head, key);

    for (struct Node* curr = head; curr != NULL; curr = curr->next)
        printf("%d%s", curr->data, curr->next ? " " : "\n");

    return 0;
}