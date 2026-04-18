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

// Insert into BST
struct Node* insert(struct Node* root, int data) {
    if (root == NULL) {
        printf("Inserting %d\n", data);
        return createNode(data);
    }

    if (data < root->data) {
        printf("%d < %d → go LEFT\n", data, root->data);
        root->left = insert(root->left, data);
    } else if (data > root->data) {
        printf("%d > %d → go RIGHT\n", data, root->data);
        root->right = insert(root->right, data);
    }

    return root;
}

// Search in BST
int search(struct Node* root, int key) {
    if (root == NULL) {
        printf("Reached NULL → Not Found\n");
        return 0;
    }

    printf("Checking node: %d\n", root->data);

    if (key == root->data) {
        printf("Key %d FOUND\n", key);
        return 1;
    }
    else if (key < root->data) {
        printf("%d < %d → go LEFT\n", key, root->data);
        return search(root->left, key);
    }
    else {
        printf("%d > %d → go RIGHT\n", key, root->data);
        return search(root->right, key);
    }
}

// Main
int main() {
    int n;
    printf("Enter number of nodes: ");
    scanf("%d", &n);

    int val;
    struct Node* root = NULL;

    printf("Enter values to insert into BST:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        root = insert(root, val);
    }

    int key;
    printf("Enter key to search: ");
    scanf("%d", &key);

    int found = search(root, key);

    if (found)
        printf("\nResult: Found\n");
    else
        printf("\nResult: Not Found\n");

    return 0;
}