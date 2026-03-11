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

int getLength(struct Node* head) {
    int length = 0;
    while (head != NULL) {
        length++;
        head = head->next;
    }
    return length;
}

struct Node* findIntersection(struct Node* head1, struct Node* head2) {
    int len1 = getLength(head1);
    int len2 = getLength(head2);

    // Advance the pointer of the longer list
    while (len1 > len2) {
        head1 = head1->next;
        len1--;
    }
    while (len2 > len1) {
        head2 = head2->next;
        len2--;
    }

    // Traverse both lists simultaneously
    while (head1 != NULL && head2 != NULL) {
        if (head1->data == head2->data)
            return head1;
        head1 = head1->next;
        head2 = head2->next;
    }

    return NULL;
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
    int n, m, val;
    struct Node* head1 = NULL;
    struct Node* head2 = NULL;

    printf("Enter number of nodes in first list: ");
    scanf("%d", &n);

    printf("Enter %d elements for first list: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        appendNode(&head1, val);
    }

    printf("Enter number of nodes in second list: ");
    scanf("%d", &m);

    printf("Enter %d elements for second list: ", m);
    for (int i = 0; i < m; i++) {
        scanf("%d", &val);
        appendNode(&head2, val);
    }

    struct Node* intersection = findIntersection(head1, head2);

    if (intersection != NULL)
        printf("Intersection point: %d\n", intersection->data);
    else
        printf("No Intersection\n");

    freeList(head1);
    freeList(head2);
    return 0;
}