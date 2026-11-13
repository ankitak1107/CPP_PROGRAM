#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *left, *right;
};

Node* insert(Node* root, int x) {
    if (root == NULL)
        return new Node{x, NULL, NULL};

    if (x < root->data)
        root->left = insert(root->left, x);
    else
        root->right = insert(root->right, x);

    return root;
}

int minimum(Node* root) {
    while (root->left != NULL)
        root = root->left;
    return root->data;
}

void mirror(Node* root) {
    if (root == NULL)
        return;

    Node* t = root->left;
    root->left = root->right;
    root->right = t;

    mirror(root->left);
    mirror(root->right);
}

void display(Node* root) {
    if (root != NULL) {
        display(root->left);
        cout << root->data << " ";
        display(root->right);
    }
}

int main() {
    Node* root = NULL;
    int n, x;

    cout << "Enter number of nodes (1-100): ";
    cin >> n;
    if (n < 1 || n > 100) {
        cout << "Invalid number of nodes";
        return 0;
    }

    cout << "Enter values: ";
    for (int i = 0; i < n; i++) {
        cin >> x;
        root = insert(root, x);
    }

    cout << "Minimum = " << minimum(root);

    cout << "\\nEnter new value to insert: ";
    cin >> x;
    root = insert(root, x);

    cout << "Before mirror: ";
    display(root);

    mirror(root);

    cout << "\\nAfter mirror: ";
    display(root);

    return 0;
}
