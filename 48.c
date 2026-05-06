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

// Function to count leaf nodes
int countLeafNodes(struct Node* root) {
    // If tree is empty
    if (root == NULL)
        return 0;

    // If node is a leaf node
    if (root->left == NULL && root->right == NULL)
        return 1;

    // Count leaf nodes in left and right subtrees
    return countLeafNodes(root->left) + countLeafNodes(root->right);
}

int main() {
    /*
           1
          / \
         2   3
        / \
       4   5

       Leaf Nodes: 4, 5, 3
    */

    struct Node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);

    printf("%d\n", countLeafNodes(root));

    return 0;
}