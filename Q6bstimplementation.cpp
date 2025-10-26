// Tanay
// csc/24/52
// practical 6
// to implement binary search tree  as an ADT


#include <iostream>

using namespace std;

// Node structure for the BST
struct Node {
    int data;
    Node* left;
    Node* right;

    // Constructor to initialize a new node
    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};

// Function to insert a new node
Node* insertNode(Node* node, int val) {
    if (node == NULL) {
        node = new Node(val);
        return node;
    }

    if (val < node->data) {
        node->left = insertNode(node->left, val);
    } else {
        node->right = insertNode(node->right, val);
    }
    return node;
}

// Function for inorder traversal
void inorderTraversal(Node* node) {
    if (node == NULL) {
        return;
    }
    inorderTraversal(node->left);
    cout << node->data << " ";
    inorderTraversal(node->right);
}

// Function for preorder traversal
void preorderTraversal(Node* node) {
    if (node == NULL) {
        return;
    }
    cout << node->data << " ";
    preorderTraversal(node->left);
    preorderTraversal(node->right);
}

// Function for postorder traversal
void postorderTraversal(Node* node) {
    if (node == NULL) {
        return;
    }
    postorderTraversal(node->left);
    postorderTraversal(node->right);
    cout << node->data << " ";
}

// Function to find the smallest node (used in delete)
Node* findMin(Node* node) {
    while (node->left != NULL) {
        node = node->left;
    }
    return node;
}

// Function to delete a node
Node* deleteNode(Node* node, int val) {
    if (node == NULL) {
        return node;
    }

    if (val < node->data) {
        node->left = deleteNode(node->left, val);
    } else if (val > node->data) {
        node->right = deleteNode(node->right, val);
    } else {
        // Case 1: No child or one child
        if (node->left == NULL) {
            Node* temp = node->right;
            delete node;
            return temp;
        } else if (node->right == NULL) {
            Node* temp = node->left;
            delete node;
            return temp;
        }

        // Case 2: Two children
        Node* temp = findMin(node->right);
        node->data = temp->data;
        node->right = deleteNode(node->right, temp->data);
    }
    return node;
}

// Function to search for a value
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

// Function to display all traversals
void displayTraversals(Node* root) {
    if (root == NULL) {
        cout << "Tree is empty." << endl;
        return;
    }

    cout << "Inorder:   ";
    inorderTraversal(root);
    cout << endl;

    cout << "Preorder:  ";
    preorderTraversal(root);
    cout << endl;

    cout << "Postorder: ";
    postorderTraversal(root);
    cout << endl;
}


// Main function to run the program
int main() {
    Node* root = NULL; // The root of the BST

    cout << "Inserting 50, 30, 70, 20, 40, 60, 80" << endl;
    root = insertNode(root, 50);
    root = insertNode(root, 30);
    root = insertNode(root, 70);
    root = insertNode(root, 20);
    root = insertNode(root, 40);
    root = insertNode(root, 60);
    root = insertNode(root, 80);

    cout << "\n--- Initial Tree Traversals ---" << endl;
    displayTraversals(root);

    cout << "\n--- Searching ---" << endl;
    cout << "Searching for 40: ";
    if (search(root, 40)) {
        cout << "Found" << endl;
    } else {
        cout << "Not Found" << endl;
    }

    cout << "Searching for 90: ";
    if (search(root, 90)) {
        cout << "Found" << endl;
    } else {
        cout << "Not Found" << endl;
    }

    cout << "\n--- Deleting 20 (leaf node) ---" << endl;
    root = deleteNode(root, 20);
    displayTraversals(root);

    cout << "\n--- Deleting 30 (node with two children) ---" << endl;
    root = deleteNode(root, 30);
    displayTraversals(root);

    cout << "\n--- Deleting 50 (root node) ---" << endl;
    root = deleteNode(root, 50);
    displayTraversals(root);

    cout << "\nProgram finished." << endl;

    return 0;
}