#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Create node
struct Node* createNode(int data) {
    printf("Creating node: %d\n", data);

    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Build tree
struct Node* buildTree(int arr[], int n) {
    if (n == 0 || arr[0] == -1) {
        printf("Tree is empty\n");
        return NULL;
    }

    printf("\n--- Building Tree ---\n");

    struct Node* root = createNode(arr[0]);

    struct Node** queue = (struct Node**)malloc(n * sizeof(struct Node*));
    int front = 0, rear = 0;

    queue[rear++] = root;

    int i = 1;

    while (i < n) {
        struct Node* current = queue[front++];
        printf("\nProcessing node: %d\n", current->data);

        // Left child
        if (arr[i] != -1) {
            printf("Adding LEFT child %d to %d\n", arr[i], current->data);
            current->left = createNode(arr[i]);
            queue[rear++] = current->left;
        }
        i++;

        // Right child
        if (i < n && arr[i] != -1) {
            printf("Adding RIGHT child %d to %d\n", arr[i], current->data);
            current->right = createNode(arr[i]);
            queue[rear++] = current->right;
        }
        i++;
    }

    free(queue);
    return root;
}

// Level Order Traversal
void levelOrder(struct Node* root) {
    if (root == NULL) return;

    printf("\n--- Level Order Traversal ---\n");

    struct Node** queue = (struct Node**)malloc(100 * sizeof(struct Node*));
    int front = 0, rear = 0;

    queue[rear++] = root;

    while (front < rear) {
        struct Node* current = queue[front++];

        printf("Visiting node: %d\n", current->data); // DEBUG
        printf("%d ", current->data);                // ACTUAL OUTPUT

        if (current->left != NULL) {
            printf(" -> enqueue left %d\n", current->left->data);
            queue[rear++] = current->left;
        }

        if (current->right != NULL) {
            printf(" -> enqueue right %d\n", current->right->data);
            queue[rear++] = current->right;
        }
    }

    free(queue);
}

// Main
int main() {
    int n;
    printf("Enter number of nodes: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter level order (-1 for NULL):\n");

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    struct Node* root = buildTree(arr, n);

    levelOrder(root);

    return 0;
}