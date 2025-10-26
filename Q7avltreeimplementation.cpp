// Tanay
// csc/24/52
// practical 7
// to implement avl tree as an ADT

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    int height; // Height of the node

    // Constructor
    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
        height = 1; 
    }
};

int getHeight(Node* node) {
    if (node == NULL) {
        return 0;
    }
    return node->height;
}

int maxVal(int a, int b) {
    return (a > b) ? a : b;
}

// Function to get the balance factor of a node
int getBalance(Node* node) {
    if (node == NULL) {
        return 0;
    }
    return getHeight(node->left) - getHeight(node->right);
}

// Function to perform a right rotation
Node* rightRotate(Node* y) {
    Node* x = y->left;
    Node* T2 = x->right;

    x->right = y;
    y->left = T2;

    // Update heights
    y->height = maxVal(getHeight(y->left), getHeight(y->right)) + 1;
    x->height = maxVal(getHeight(x->left), getHeight(x->right)) + 1;

    return x;
}

// Function to perform a left rotation
Node* leftRotate(Node* x) {
    Node* y = x->right;
    Node* T2 = y->left;

    y->left = x;
    x->right = T2;

    // Update heights
    x->height = maxVal(getHeight(x->left), getHeight(x->right)) + 1;
    y->height = maxVal(getHeight(y->left), getHeight(y->right)) + 1;

    return y;
}

// Function to insert a new node into the AVL tree
Node* insertNode(Node* node, int val) {
    // 1. Perform standard BST insertion
    if (node == NULL) {
        return (new Node(val));
    }

    if (val < node->data) {
        node->left = insertNode(node->left, val);
    } else if (val > node->data) {
        node->right = insertNode(node->right, val);
    } else {
        return node;
    }

    // 2. Update height of this ancestor node
    node->height = 1 + maxVal(getHeight(node->left), getHeight(node->right));

    // 3. Get the balance factor
    int balance = getBalance(node);

    // 4. If unbalanced, check the 4 cases

    // Left Left (LL) Case
    if (balance > 1 && val < node->left->data) {
        return rightRotate(node);
    }

    // Right Right (RR) Case
    if (balance < -1 && val > node->right->data) {
        return leftRotate(node);
    }

    // Left Right (LR) Case
    if (balance > 1 && val > node->left->data) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    // Right Left (RL) Case
    if (balance < -1 && val < node->right->data) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    // Return the (possibly unchanged) node pointer
    return node;
}

// Function to search for a value (same as BST)
bool search(Node* node, int val) {
    if (node == NULL) {
        return false;
    }

    if (node->data == val) {
        return true;
    }

    if (val < node->data) {
        return search(node->left, val);
    } else {
        return search(node->right, val);
    }
}

// Function for preorder traversal (to show tree structure)
void preorderTraversal(Node* node) {
    if (node == NULL) {
        return;
    }
    cout << node->data << " ";
    preorderTraversal(node->left);
    preorderTraversal(node->right);
}

// Main function to run the program
int main() {
    Node* root = NULL; 

    cout << "Inserting 10, 20, 30 " << endl;
    root = insertNode(root, 10);
    root = insertNode(root, 20);
    root = insertNode(root, 30); 

    cout << "Tree after inserting (Preorder): ";
    preorderTraversal(root);
    cout << endl;

    cout << "\nInserting 40, 50 " << endl;
    root = insertNode(root, 40);
    root = insertNode(root, 50); 

    cout << "Tree after inserting(Preorder): ";
    preorderTraversal(root);
    cout << endl;

    cout << "\nInserting 3 " << endl;
    root = insertNode(root, 3);
    
    cout << "Final Tree (Preorder): ";
    preorderTraversal(root);
    cout << endl;

    cout << "\n--- Searching ---" << endl;
    cout << "Searching for 30: ";
    if (search(root, 30)) {
        cout << "Found" << endl;
    } else {
        cout << "Not Found" << endl;
    }

    cout << "Searching for 99: ";
    if (search(root, 99)) {
        cout << "Found" << endl;
    } else {
        cout << "Not Found" << endl;
    }

    cout << "\nProgram finished." << endl;

    return 0;
}
