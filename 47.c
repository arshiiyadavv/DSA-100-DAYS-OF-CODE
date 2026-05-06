#include <stdio.h>
#include <stdlib.h>

// Structure for tree node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Create new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to find height of binary tree
int height(struct Node* root) {
    // Base case
    if (root == NULL)
        return 0;

    // Find height of left and right subtree
    int leftHeight = height(root->left);
    int rightHeight = height(root->right);

    // Return maximum height + 1
    return (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
}

int main() {
    /*
           1
          / \
         2   3
        / \
       4   5
    */

    struct Node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);

    printf("%d\n", height(root));

    return 0;
}