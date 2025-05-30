// Function to create a new BST node
struct Node* newNode(int item) {
    struct Node* temp = 
       (struct Node*)malloc(sizeof(struct Node));
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
}


// Function to insert a new node with the given key
struct Node* insert(struct Node* node, int key) {
  
    // If the tree is empty, return a new node
    if (node == NULL)
        return newNode(key);
    
    // If the key is already present in the tree,
    // return the node
    if (node->key == key)
        return node;
    
    // Otherwise, recur down the tree. If the key 
    // to be inserted is greater than the node's key,
    // insert it in the right subtree
    if (node->key < key)
        node->right = insert(node->right, key);
  
    // If the key to be inserted is smaller than 
    // the node's key,insert it in the left subtree
    else
        node->left = insert(node->left, key);

    // Return the (unchanged) node pointer
    return node;
}

// Function to perform inorder tree traversal
void inorder(struct Node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->key);
        inorder(root->right);
    }
}
