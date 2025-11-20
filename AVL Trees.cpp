#include <stdio.h>
#include <stdlib.h>

// AVL Tree Node Structure
typedef struct AVLNode {
    int key;
    struct AVLNode *left;
    struct AVLNode *right;
    int height;
} AVLNode;

// Function to create a new node
AVLNode* createNode(int key) {
    AVLNode* newNode = (AVLNode*)malloc(sizeof(AVLNode));
    newNode->key = key;
    newNode->left = newNode->right = NULL;
    newNode->height = 1;
    return newNode;
}

// Function to get the height of a node
int height(AVLNode* node) {
    return node ? node->height : 0;
}

// Function to get the balance factor of a node
int getBalance(AVLNode* node) {
    return node ? height(node->left) - height(node->right) : 0;
}

// Right Rotate
AVLNode* rightRotate(AVLNode* y) {
    AVLNode* x = y->left;
    AVLNode* T2 = x->right;
    x->right = y;
    y->left = T2;
    y->height = 1 + (height(y->left) > height(y->right) ? height(y->left) : height(y->right));
    x->height = 1 + (height(x->left) > height(x->right) ? height(x->left) : height(x->right));
    return x;
}

// Left Rotate
AVLNode* leftRotate(AVLNode* x) {
    AVLNode* y = x->right;
    AVLNode* T2 = y->left;
    y->left = x;
    x->right = T2;
    x->height = 1 + (height(x->left) > height(x->right) ? height(x->left) : height(x->right));
    y->height = 1 + (height(y->left) > height(y->right) ? height(y->left) : height(y->right));
    return y;
}

// Function to insert a key into the AVL tree
AVLNode* insert(AVLNode* node, int key) {
    if (!node) return createNode(key);
    if (key < node->key)
        node->left = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);
    else
        return node; // Duplicate keys are not allowed

    node->height = 1 + (height(node->left) > height(node->right) ? height(node->left) : height(node->right));

    int balance = getBalance(node);

    if (balance > 1 && key < node->left->key)
        return rightRotate(node);

    if (balance < -1 && key > node->right->key)
        return leftRotate(node);

    if (balance > 1 && key > node->left->key) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    if (balance < -1 && key < node->right->key) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

// Function to find the node with the minimum value
AVLNode* minNode(AVLNode* node) {
    AVLNode* current = node;
    while (current->left != NULL)
        current = current->left;
    return current;
}

// Function to delete a key from the AVL tree
AVLNode* deleteNode(AVLNode* root, int key) {
    if (!root) return root;

    if (key < root->key)
        root->left = deleteNode(root->left, key);
    else if (key > root->key)
        root->right = deleteNode(root->right, key);
    else {
        if (!root->left || !root->right) {
            AVLNode* temp = root->left ? root->left : root->right;
            if (!temp) {
                temp = root;
                root = NULL;
            } else
                *root = *temp;
            free(temp);
        } else {
            AVLNode* temp = minNode(root->right);
            root->key = temp->key;
            root->right = deleteNode(root->right, temp->key);
        }
    }

    if (!root) return root;

    root->height = 1 + (height(root->left) > height(root->right) ? height(root->left) : height(root->right));

    int balance = getBalance(root);

    if (balance > 1 && getBalance(root->left) >= 0)
        return rightRotate(root);

    if (balance > 1 && getBalance(root->left) < 0) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    if (balance < -1 && getBalance(root->right) <= 0)
        return leftRotate(root);

    if (balance < -1 && getBalance(root->right) > 0) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

// Function to perform in-order traversal
void inOrder(AVLNode* root, FILE* file) {
    if (root) {
        inOrder(root->left, file);
        fprintf(file, "%d\n", root->key);
        inOrder(root->right, file);
    }
}

// Function to read elements from a file and build the AVL tree
AVLNode* readFromFile(const char* filename) {
    FILE* file = fopen(filename, "r");
    if (!file) {
        perror("Failed to open file");
        return NULL;
    }

    AVLNode* root = NULL;
    int key;
    while (fscanf(file, "%d", &key) != EOF) {
        root = insert(root, key);
    }

    fclose(file);
    return root;
}

// Function to write the in-order traversal to a file
void writeToFile(const char* filename, AVLNode* root) {
    FILE* file = fopen(filename, "w");
    if (!file) {
        perror("Failed to open file");
        return;
    }

    inOrder(root, file);
    fclose(file);
}

int main() {
    const char* inputFilename = "input.txt";
    const char* outputFilename = "output.txt";

    AVLNode* root = readFromFile(inputFilename);
    if (root == NULL) {
        fprintf(stderr, "Error reading input file.\n");
        return 1;
    }

    printf("Tree built successfully. Writing in-order traversal to file...\n");

    writeToFile(outputFilename, root);

    printf("In-order traversal written to %s\n", outputFilename);

    // Example of deletion operation
    int keyToDelete = 5;
    root = deleteNode(root, keyToDelete);
    printf("Deleted key %d from the tree.\n", keyToDelete);

    // Write the updated tree to a new file
    writeToFile("updated_output.txt", root);
    printf("Updated in-order traversal written to updated_output.txt\n");

    return 0;
}
