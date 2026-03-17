#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

char stack[MAX];
int top = -1;

void push(char c) {
    stack[++top] = c;
}

char pop() {
    return stack[top--];
}

char peek() {
    return stack[top];
}

int isEmpty() {
    return top == -1;
}

int precedence(char op) {
    if (op == '*' || op == '/')
        return 2;
    if (op == '+' || op == '-')
        return 1;
    return 0;
}

int isOperand(char c) {
    return (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || (c >= '0' && c <= '9');
}

void infixToPostfix(char* infix, char* postfix) {
    int i = 0, j = 0;

    while (infix[i] != '\0') {
        char c = infix[i];

        // Case 1: Operand → directly add to postfix
        if (isOperand(c)) {
            postfix[j++] = c;
        }

        // Case 2: Opening parenthesis → push to stack
        else if (c == '(') {
            push(c);
        }

        // Case 3: Closing parenthesis → pop until '('
        else if (c == ')') {
            while (!isEmpty() && peek() != '(')
                postfix[j++] = pop();
            pop();  // Remove '(' from stack
        }

        // Case 4: Operator → pop higher/equal precedence operators first
        else {
            while (!isEmpty() && precedence(peek()) >= precedence(c))
                postfix[j++] = pop();
            push(c);
        }

        i++;
    }

    // Step 5: Pop remaining operators from stack
    while (!isEmpty())
        postfix[j++] = pop();

    postfix[j] = '\0';
}

int main() {
    char infix[MAX], postfix[MAX];

    printf("Enter infix expression: ");
    scanf("%s", infix);

    infixToPostfix(infix, postfix);

    printf("Infix expression:   %s\n", infix);
    printf("Postfix expression: %s\n", postfix);

    return 0;
}