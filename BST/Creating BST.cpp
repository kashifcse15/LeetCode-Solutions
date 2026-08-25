#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int value) {
        data = value;
        left = NULL;
        right = NULL;
    }
};

Node* insert(Node* root, int value) {

    // If tree is empty
    if (root == NULL) {
        return new Node(value);
    }

    // Smaller values go to left
    if (value < root->data) {
        root->left = insert(root->left, value);
    }

    // Greater values go to right
    else if (value > root->data) {
        root->right = insert(root->right, value);
    }

    return root;
}

// Inorder traversal
void inorder(Node* root) {

    if (root == NULL)
        return;

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main() {

    Node* root = NULL;

    root = insert(root, 50);
    insert(root, 30);
    insert(root, 70);
    insert(root, 20);
    insert(root, 40);
    insert(root, 60);
    insert(root, 80);

    cout << "Inorder Traversal: ";
    inorder(root);

    return 0;
}
