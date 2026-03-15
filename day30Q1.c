#include <stdio.h>
#include <stdlib.h>

struct Node {
    int coeff;
    int exp;
    struct Node* next;
};

struct Node* createNode(int coeff, int exp) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->coeff = coeff;
    newNode->exp   = exp;
    newNode->next  = NULL;
    return newNode;
}

void appendNode(struct Node** head, int coeff, int exp) {
    struct Node* newNode = createNode(coeff, exp);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    struct Node* temp = *head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = newNode;
}

void printPolynomial(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        int c = temp->coeff;
        int e = temp->exp;

        if (e == 0)
            printf("%d", c);           // Constant term: 50
        else if (e == 1)
            printf("%dx", c);          // Linear term:   40x
        else
            printf("%dx^%d", c, e);    // Higher terms:  10x^4

        if (temp->next != NULL)
            printf(" + ");

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
    int n, coeff, exp;
    struct Node* head = NULL;

    printf("Enter number of terms: ");
    scanf("%d", &n);

    printf("Enter coefficient and exponent for each term:\n");
    for (int i = 0; i < n; i++) {
        printf("  Term %d: ", i + 1);
        scanf("%d %d", &coeff, &exp);
        appendNode(&head, coeff, exp);
    }

    printf("\nPolynomial: ");
    printPolynomial(head);

    freeList(head);
    return 0;
}