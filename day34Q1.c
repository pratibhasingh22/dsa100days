#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Stack node using linked list
struct Node {
    int data;
    struct Node* next;
};

struct Node* top = NULL;

void push(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = top;
    top = newNode;
}

int pop() {
    if (top == NULL) {
        printf("Stack Underflow\n");
        exit(1);
    }
    int value = top->data;
    struct Node* temp = top;
    top = top->next;
    free(temp);
    return value;
}

int isEmpty() {
    return top == NULL;
}

int evaluatePostfix(char* expr) {
    char* token = strtok(expr, " ");

    while (token != NULL) {

        // Case 1: Operand → push to stack
        if (token[0] != '+' && token[0] != '-' &&
            token[0] != '*' && token[0] != '/' || strlen(token) > 1) {
            push(atoi(token));
        }

        // Case 2: Operator → pop two operands, compute, push result
        else {
            int b = pop();  // Second operand (popped first)
            int a = pop();  // First operand  (popped second)
            int result;

            switch (token[0]) {
                case '+': result = a + b; break;
                case '-': result = a - b; break;
                case '*': result = a * b; break;
                case '/': result = a / b; break;
            }

            printf("  %d %c %d = %d\n", a, token[0], b, result);
            push(result);
        }

        token = strtok(NULL, " ");
    }

    return pop();
}

int main() {
    char expr[200];

    printf("Enter postfix expression: ");
    fgets(expr, sizeof(expr), stdin);
    expr[strcspn(expr, "\n")] = '\0';   // Remove trailing newline

    printf("\n--- Evaluation Steps ---\n");
    int result = evaluatePostfix(expr);

    printf("\nResult: %d\n", result);

    return 0;
}