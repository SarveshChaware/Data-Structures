//WRITE A FUNCTION TO FIND THE HEIGHT OF BINARY TREE AND ALSO FIND THE DEPTH 


#include <stdio.h>
#include <stdlib.h> 
struct Node{
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to insert a node into the BST
struct Node* insertNode(struct Node* root, int value) {
    if (root == NULL)
        return createNode(value);

    if (value < root->data)
        root->left = insertNode(root->left, value);
    else if (value > root->data)
        root->right = insertNode(root->right, value);

    // If value == root->data, do nothing (no duplicates)
    return root;
}

// Function to find the height of the binary tree
int findHeight(struct Node* root) {
    if (root == NULL)
        return -1; // Height of an empty tree is -1

    int leftHeight = findHeight(root->left);
    int rightHeight = findHeight(root->right);

    return (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
}

// Function to find the depth of a node in the binary tree
int findDepth(struct Node* root, int value, int depth) {
    if (root == NULL)
        return -1; // Value not found

    if (root->data == value)
        return depth;

    int leftDepth = findDepth(root->left, value, depth + 1);
    if (leftDepth != -1)
        return leftDepth;

    return findDepth(root->right, value, depth + 1);
}

int main(){
    struct Node*root = NULL;
    int n, value, depthValue;
    printf("Enter the number of nodes: ");
    scanf("%d", &n);
    printf("Enter the values of the nodes:\n");
    for(int i = 0; i < n; i++){
        scanf("%d", &value);
        root = insertNode(root, value);
    }
    printf("Height of the binary tree: %d\n", findHeight(root));
    printf("Enter the value to find its depth: ");
    scanf("%d", &depthValue);
    int depth = findDepth(root, depthValue, 0);
    if (depth != -1)
        printf("Depth of node %d: %d\n", depthValue, depth);
    else
        printf("Node %d not found in the tree.\n", depthValue);
    return 0;
} 
