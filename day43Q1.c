#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Create new node
struct Node* createNode(int data) {
    printf("Creating node with value: %d\n", data);

    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Build tree from level order
struct Node* buildTree(int arr[], int n) {
    if (n == 0 || arr[0] == -1) {
        printf("Tree is empty\n");
        return NULL;
    }

    printf("Building tree...\n");

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
        } else {
            printf("LEFT child of %d is NULL\n", current->data);
        }
        i++;

        // Right child
        if (i < n && arr[i] != -1) {
            printf("Adding RIGHT child %d to %d\n", arr[i], current->data);
            current->right = createNode(arr[i]);
            queue[rear++] = current->right;
        } else if (i < n) {
            printf("RIGHT child of %d is NULL\n", current->data);
        }
        i++;
    }

    free(queue);
    return root;
}

// Inorder traversal
void inorder(struct Node* root) {
    if (root == NULL)
        return;

    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

// Main
int main() {
    int n;
    printf("Enter number of nodes: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter level order values (-1 for NULL):\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    struct Node* root = buildTree(arr, n);

    printf("\nInorder Traversal: ");
    inorder(root);

    return 0;
}