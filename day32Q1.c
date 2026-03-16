#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int stack[MAX];
int top = -1;

void push(int value) {
    if (top == MAX - 1) {
        printf("Stack Overflow\n");
        return;
    }
    stack[++top] = value;
}

void pop() {
    if (top == -1) {
        printf("Stack Underflow\n");
        return;
    }
    printf("Popped: %d\n", stack[top--]);
}

void display() {
    if (top == -1) {
        printf("Stack is empty\n");
        return;
    }
    printf("Remaining stack (top to bottom): ");
    for (int i = top; i >= 0; i--) {
        if (i == 0)
            printf("%d", stack[i]);
        else
            printf("%d ", stack[i]);
    }
    printf("\n");
}

int main() {
    int n, m, val;

    printf("Enter number of elements to push: ");
    scanf("%d", &n);

    printf("Enter %d elements: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        push(val);
    }

    printf("Enter number of elements to pop: ");
    scanf("%d", &m);

    printf("\n--- Pop Operations ---\n");
    for (int i = 0; i < m; i++)
        pop();

    printf("\n--- Stack State ---\n");
    display();

    return 0;
}